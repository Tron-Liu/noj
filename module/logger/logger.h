#pragma once

#include "spdlog/logger.h"

#include <cstdint>
#include <memory>
#include <string>

namespace noj {

struct LogConfig {
  std::string level;
  std::string path;
  uint64_t size;
  int count;
};

class Logger {
private:
  const std::string loggerName_ = "NOJ";

  std::shared_ptr<spdlog::logger> logger_;

private:
  Logger() = default;

public:
  static Logger* GetInstance();
  std::shared_ptr<spdlog::logger> GetLogger();

  void Init(LogConfig config);
};

#define INITLOG(config) Logger::GetInstance()->Init(config);

#define BASELOG(logger, level, ...)                                            \
  (logger)->log(                                                               \
    spdlog::source_loc { __FILE__, __LINE__, __func__ }, level, __VA_ARGS__)

#define LOG_TRACE(...)                                                         \
  BASELOG(Logger::GetInstance()->GetLogger(), spdlog::level::trace, __VA_ARGS__)

#define LOG_DEBUG(...)                                                         \
  BASELOG(Logger::GetInstance()->GetLogger(), spdlog::level::debug, __VA_ARGS__)

#define LOG_INFO(...)                                                          \
  BASELOG(Logger::GetInstance()->GetLogger(), spdlog::level::info, __VA_ARGS__)

#define LOG_WARN(...)                                                          \
  BASELOG(Logger::GetInstance()->GetLogger(), spdlog::level::warn, __VA_ARGS__)

#define LOG_ERROR(...)                                                         \
  BASELOG(Logger::GetInstance()->GetLogger(), spdlog::level::err, __VA_ARGS__)

#define LOG_CRITICAL(...)                                                      \
  BASELOG(                                                                     \
    Logger::GetInstance()->GetLogger(), spdlog::level::critical, __VA_ARGS__)

} // namespace noj