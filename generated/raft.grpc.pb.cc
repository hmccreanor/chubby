// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: raft.proto

#include "raft.pb.h"
#include "raft.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>

static const char* Raft_method_names[] = {
  "/Raft/AppendEntries",
  "/Raft/RequestVote",
};

std::unique_ptr< Raft::Stub> Raft::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Raft::Stub> stub(new Raft::Stub(channel, options));
  return stub;
}

Raft::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_AppendEntries_(Raft_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RequestVote_(Raft_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Raft::Stub::AppendEntries(::grpc::ClientContext* context, const ::AppendEntriesReq& request, ::AppendEntriesRes* response) {
  return ::grpc::internal::BlockingUnaryCall< ::AppendEntriesReq, ::AppendEntriesRes, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AppendEntries_, context, request, response);
}

void Raft::Stub::async::AppendEntries(::grpc::ClientContext* context, const ::AppendEntriesReq* request, ::AppendEntriesRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::AppendEntriesReq, ::AppendEntriesRes, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AppendEntries_, context, request, response, std::move(f));
}

void Raft::Stub::async::AppendEntries(::grpc::ClientContext* context, const ::AppendEntriesReq* request, ::AppendEntriesRes* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AppendEntries_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::AppendEntriesRes>* Raft::Stub::PrepareAsyncAppendEntriesRaw(::grpc::ClientContext* context, const ::AppendEntriesReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::AppendEntriesRes, ::AppendEntriesReq, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AppendEntries_, context, request);
}

::grpc::ClientAsyncResponseReader< ::AppendEntriesRes>* Raft::Stub::AsyncAppendEntriesRaw(::grpc::ClientContext* context, const ::AppendEntriesReq& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAppendEntriesRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Raft::Stub::RequestVote(::grpc::ClientContext* context, const ::RequestVoteReq& request, ::RequestVoteRes* response) {
  return ::grpc::internal::BlockingUnaryCall< ::RequestVoteReq, ::RequestVoteRes, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_RequestVote_, context, request, response);
}

void Raft::Stub::async::RequestVote(::grpc::ClientContext* context, const ::RequestVoteReq* request, ::RequestVoteRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::RequestVoteReq, ::RequestVoteRes, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RequestVote_, context, request, response, std::move(f));
}

void Raft::Stub::async::RequestVote(::grpc::ClientContext* context, const ::RequestVoteReq* request, ::RequestVoteRes* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RequestVote_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::RequestVoteRes>* Raft::Stub::PrepareAsyncRequestVoteRaw(::grpc::ClientContext* context, const ::RequestVoteReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::RequestVoteRes, ::RequestVoteReq, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_RequestVote_, context, request);
}

::grpc::ClientAsyncResponseReader< ::RequestVoteRes>* Raft::Stub::AsyncRequestVoteRaw(::grpc::ClientContext* context, const ::RequestVoteReq& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRequestVoteRaw(context, request, cq);
  result->StartCall();
  return result;
}

Raft::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Raft_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Raft::Service, ::AppendEntriesReq, ::AppendEntriesRes, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Raft::Service* service,
             ::grpc::ServerContext* ctx,
             const ::AppendEntriesReq* req,
             ::AppendEntriesRes* resp) {
               return service->AppendEntries(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Raft_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Raft::Service, ::RequestVoteReq, ::RequestVoteRes, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Raft::Service* service,
             ::grpc::ServerContext* ctx,
             const ::RequestVoteReq* req,
             ::RequestVoteRes* resp) {
               return service->RequestVote(ctx, req, resp);
             }, this)));
}

Raft::Service::~Service() {
}

::grpc::Status Raft::Service::AppendEntries(::grpc::ServerContext* context, const ::AppendEntriesReq* request, ::AppendEntriesRes* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Raft::Service::RequestVote(::grpc::ServerContext* context, const ::RequestVoteReq* request, ::RequestVoteRes* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


