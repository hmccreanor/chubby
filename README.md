# Chubby Clone

Clone of Google's Chubby written in C++.

## Things I will need to figure out/build:
1. Chubby itself
2. RAFT implementation
3. RPC calls

I am going to start by figuring out RPC calls first as they seem important for both the RAFT and Chubby implementations.
I then plan on building RAFT, hopefully in such a way that it is easy to implement Chubby on top of this.


### Open questions/things to explore
- [ ] RPCs feel like the right way of doing this, but I don't really know why? I think they are faster than making some sort of REST API but can't really justify why this is the case.
