#include "logger.h"

#include "spdlog/async.h"
#include "spdlog/common.h"
#include "spdlog/sinks/rotating_file_sink.h"

#include <cstring>
#include <string>
#include <unistd.h>

namespace noj {

Logger* Logger::GetInstance()
{
  static Logger instance;
  return &instance;
}

std::shared_ptr<spdlog::logger> Logger::GetLogger() { return logger_; }

void Logger::Init(LogConfig config)
{

  logger_ = spdlog::rotating_logger_mt<spdlog::async_factory>(
    loggerName_, config.path, config.size, config.count);

  logger_->set_pattern(
    "[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [thread %t] [%s %!:%#] %v");

  logger_->set_level(spdlog::level::from_str(config.level));
  logger_->flush_on(spdlog::level::from_str(config.level));
}

} // namespace noj