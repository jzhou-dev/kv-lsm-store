#pragma once
#include <string_view>

enum class ResponseStatus { Success, NotFoundError, BadRequest, ServerError };

constexpr std::string_view ToString(ResponseStatus status) {
  switch (status) {
  case ResponseStatus::Success:
    return "Success";
  case ResponseStatus::NotFoundError:
    return "NotFoundError";
  case ResponseStatus::ServerError:
    return "ServerError";
  case ResponseStatus::BadRequest:
    return "BadRequest";
  }
}
