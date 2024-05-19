#include "logger.h"
#include "path.h"
#include <cstring>
#include <filesystem>
#include <string>
#include <unistd.h>

namespace TL {

Logger* Logger::instance_ = nullptr;

Logger::Logger()
{
  std::string homePath = Path::getHome();
  std::string filename = homePath + "/" + "logs" + "/" + fileName_;

  logger_ = spdlog::daily_logger_mt(loggerName_, filename, 0, 30);
}

Logger* Logger::GetInstance()
{
  if (instance_ == nullptr) {
    instance_ = new Logger();
    return instance_;
  }

  return instance_;
}

LoggerPtr Logger::GetLogger() { return logger_; }

} // namespace TL