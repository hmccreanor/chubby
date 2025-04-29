#include <boost/asio.hpp>

#include <iostream>
#include <vector>
#include "connection.hpp"
#include <boost/serialization/vector.hpp>
#include "raft_types.hpp"

namespace chubby {
  class server {
    public:
      server(boost::asio::io_context& io_context, unsigned short port)
        : acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::io::tcp::v4(), port)) {

          request_vote_req.term = 1;
          request_vote_req.candidateId = 9;
          request_vote_req.lastLogIndex = 4;
          request_vote_req.lastLogTerm = 5;

          connection_ptr new_conn(new connection(acceptor_.get_executor()));
          acceptor_.async_accept(new_conn->socket(), std::bind(&server::handle_accept, this, boost::asio::placeholders::errors, new_conn));

        }
      void handle_accept(const boost::system::error_code& e, connection_ptr conn) {
        if (!e) {
          // The connection::async_write() function will automatically
          // serialize the data structure for us.
          conn->async_write(request_vote_req_,
              std::bind(&server::handle_write, this,
                boost::asio::placeholders::error, conn));
        }

        // Start an accept operation for a new connection.
        connection_ptr new_conn(new connection(acceptor_.get_executor()));
        acceptor_.async_accept(new_conn->socket(),
            std::bind(&server::handle_accept, this,
              boost::asio::placeholders::error, new_conn));
      }

      void handle_write(const boost::system::error_code& e, connection_ptr conn) {
        // Nothing to do. The socket will be closed automatically when the last
        // reference to the connection object goes away.
      }

    private:
      boost::asio::ip::tcp::acceptor acceptor_;

      RequestVoteReq request_vote_req_;
  };
}

int main(int argc, char** argv) {
  try {
    if (argc != 2) {
      std::cerr << "Usage: server <port>" << std::endl;
      return 1;
    }
    unsigned short port = std::stoi(argv[1]);

    boost::asio::io_context io_context;

    chubby::server server(io_context, port);
    io_context.run();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
