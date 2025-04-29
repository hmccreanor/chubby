#include <boost/asio.hpp>

#include <iostream>
#include <vector>
#include "connection.hpp"
#include "raft_types.hpp"

namespace chubby {

  class client {
    public:
      client(boost::asio::io_context& io_context, const std::string& host, const std::string& service)
      : connection_(io_context.get_executor()) {
        boost::asio::ip::tcp::resolver resolver(io_context);
        boost::asio::ip::tcp::resolver::query query(host, service);
        boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

        boost::asio::async_connect(connection_.socket(), endpoint_iterator, std::bind(&client::handle_connect, this, boost::asio::placeholders::error));
      }

      void handle_connect(boost::system::error_code& e) {
        if (!e) {
          // Successfully established connection. Start operation to read
          // request vote req. The connection::async_read() function will automatically
          // decode the data that is read from the underlying socket.
          connection_.async_read(request_vote_req_,
              std::bind(&client::handle_read, this,
                boost::asio::placeholders::error));
        } else {
          // An error occurred. Log it and return. Since we are not starting a new
          // operation the io_context will run out of work to do and the client will
          // exit.
          std::cerr << e.message() << std::endl;
        }
      }

      void handle_read(boost::system::error_code& e) {
        if (!e) {
          std::cout << "RequestVoteReq\n";
          std::cout << "term=" << request_vote_req_.term << "\n";
          std::cout << "candidateId=" << request_vote_req_.candidateId << "\n";
          std::cout << "lastLogIndex=" << request_vote_req_.lastLogIndex << "\n";
          std::cout << "lastLogTerm=" << request_vote_req_.lastLogTerm << "\n\n";
        } else {
          // An error occurred.
          std::cerr << e.message() << std::endl;
        }
        // Since we are not starting a new operation the io_context will run out of
        // work to do and the client will exit.
      }

    private:
      connection connection_;

      raft::RequestVoteReq request_vote_req_;
  };
}

int main(int argc, char** argv) {
  try {
    if (argc != 3) {
      std::cerr << "Usage: client <host> <port>" << std::endl;
      return 1;
    }
    boost::asio::io_context io_context;
    chubby::client client(io_context, argv[1], argv[2]);

    io_context.run();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
