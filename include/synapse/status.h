#ifndef SYNAPSE_STATUS_H_
#define SYNAPSE_STATUS_H_

#include <string>
#include <utility>


namespace synapse {

enum class StatusCode : int {
  kOk = 0,
  kUnknown = 2,
  kInvalidArgument = 3,
  kDeadlineExceeded = 4,
  kNotFound = 5,
  kResourceExhausted = 8,
  kFailedPrecondition = 9,
  kOutOfRange = 11,
  kUnimplemented = 12,
  kInternal = 13,
  kUnavailable = 14,
};

class Status {
 public:
  Status(StatusCode code, std::string message) : code_(code), message_(std::move(message)) {}
  explicit Status(StatusCode code) : code_(code) {}
  Status() : code_(StatusCode::kOk) {}

  [[nodiscard]] auto ok() const -> bool { return code_ == StatusCode::kOk; }
  [[nodiscard]] auto code() const -> StatusCode { return code_; }
  [[nodiscard]] auto message() const -> std::string { return message_; }

 private:
  StatusCode code_;
  std::string message_;
};

}  // namespace synapse

#endif  // SYNAPSE_STATUS_H_
