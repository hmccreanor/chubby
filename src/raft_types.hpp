#ifndef RAFT_TYPES_HPP
#define RAFT_TYPES_HPP

#include <string>
#include <vector>

namespace raft {
  struct AppendEntriesReq {
    unsigned int term;
    unsigned int leaderId;
    unsigned int prevLogIndex;
    unsigned int leaderCommit;
    std::vector<std::string> logEntries;

    template <typename Archive>
    void serialise(Archive& ar, const unsigned int version) {
      ar & term;
      ar & leaderId;
      ar & prevLogIndex;
      ar & leaderCommit;
      ar & logEntries;
    }
  }; 

  struct AppendEntriesRes {
    unsigned int term;
    bool success;

    template <typename Archive>
    void serialise(Archive& ar, const unsigned int version) {
      ar & term;
      ar & success;
    }
  }; 

  struct RequestVoteReq {
    unsigned int term;
    unsigned int candidateId;
    unsigned int lastLogIndex;
    unsigned int lastLogTerm;

    template <typename Archive>
    void serialise(Archive& ar, const unsigned int version) {
      ar & term;
      ar & candidateId;
      ar & lastLogIndex;
      ar & lastLogTerm;
    }
  }; 

  struct RequestVoteRes {
    unsigned int term;
    bool voteGranted;

    template <typename Archive>
    void serialise(Archive& ar, const unsigned int version) {
      ar & term;
      ar & voteGranted;
    }
  }; 

}

#endif // RAFT_TYPES_HPP
