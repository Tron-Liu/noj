#pragma once

#include <filesystem>
#include <iostream>
#include <memory>
#include <string>

#include "spdlog/logger.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/spdlog.h"

#include "path.h"

namespace TL {

typedef std::shared_ptr<spdlog::logger> LoggerPtr;

class Logger {
private:
  const int BUFFER_SIZE = 512;

  const std::string loggerName_ = "NOJLogger";
  const std::string fileName_   = "daily.txt";

  static Logger* instance_;
  std::shared_ptr<spdlog::logger> logger_;

private:
  Logger();
  ~Logger();

public:
  static Logger* GetInstance();
  LoggerPtr GetLogger();
};

} // namespace TL