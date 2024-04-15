#include "threadPool.h"

namespace TL {

TL::ThreadPool::ThreadPool(int thread_number, int max_requests)
  : number_(thread_number)
  , maxRequests_(max_requests)
{
}

} // namespace TL
