#pragma once

#include <cstdint>
#include <memory>
#include <thread>

namespace TL {

class ThreadPool {
private:
  uint32_t number_;
  uint32_t maxRequests_;
  bool stop_;
  std::unique_ptr<std::thread> threads_;

private:

public:
  ThreadPool(int thread_number = 8, int max_requests = 10000);
  ~ThreadPool();

  bool append();
};

} // namespace TL
