# Chubby Clone

Clone of Google's Chubby written in C++.

## Things I will need to figure out/build:
1. Chubby itself
2. RAFT implementation
3. RPC calls

I am going to start by figuring out RPC calls first as they seem important for both the RAFT and Chubby implementations.
I then plan on building RAFT, hopefully in such a way that it is easy to implement Chubby on top of this.


## Open questions/things to explore:
- [x] RPCs feel like the right way of doing this, but I don't really know why? I think they are faster than making some sort of REST API but can't really justify why this is the case.
    - I think the order of performant ways for remote services to communicate is (fastest to slowest) sockets > RPCs > REST. 
    - The reason for RPCs being faster than REST is to do with how data is serialised (binary with RPCs and Protobufs vs text-based JSON for REST) and connection reuse (RPCs using http2 which supports connection reuse whereas REST using http1.1 which does not). The reason TCP sockets are faster than both of these is that they are a transport layer protocol compared to an application layer protocol and as such do not incur any of the costs of packaging data into http packets, processing headers etc.
    - I am going to go with RPCs for now because, from what I have seen, network latency is likely to bottleneck performance rather than the compute overhead of using RPC instead of TCP. Network latency seems to be on the order 0.5-100ms depending on whether you are sending data across a datacenter vs cross-continent or even further. RPC latency seems to be on the order of microseconds. Even in the case where we are sending data across a datacenter (which is the case for the Chubby cells in the original paper), we are unlikely to be bottlenecked by RPC time. As such, I will favour the lower development overhead of RPCs and go with them.
