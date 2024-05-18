#include "socket.h"

#include <arpa/inet.h>
#include <cerrno>
#include <memory>
#include <netinet/in.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <tuple>
#include <unistd.h>

namespace TL {

bool Socket::Create()
{
  int sock = socket(PF_INET, SOCK_STREAM, 0);

  if (-1 == sock) {
    logger_->error("create socket failed, errno is {}", errno);
    fd_ = 0;

    return false;
  } else {
    fd_ = sock;
  }

  return true;
}

bool Socket::Bind(std::string ip, int port)
{
  struct sockaddr_in address;
  bzero(&address, sizeof(address));
  address.sin_family = AF_INET;
  inet_pton(AF_INET, ip.c_str(), &address.sin_addr);
  address.sin_port = htons(port);

  int ret = bind(fd_, (struct sockaddr*)&address, sizeof(address));

  if (-1 == ret) {
    logger_->error("bind socket failed, errno is {}", errno);
    return false;
  }

  return true;
}

bool Socket::Listen(int maxNum) const noexcept
{
  int ret = listen(fd_, maxNum);

  if (-1 == ret) {
    logger_->error("listen socket failed, errno is {}", errno);
    return false;
  }

  return true;
}

bool Socket::Accept(std::shared_ptr<Socket>& connfd)
{
  struct sockaddr_in clientAddr;
  socklen_t addrLength = sizeof(clientAddr);
  int ret = accept(fd_, (struct sockaddr*)&clientAddr, &addrLength);

  if (ret < 0) {
    logger_->error("Socket connection failed, errno is {}.", errno);
    return false;
  }

  connfd = std::make_shared<Socket>(ret);
  return true;
}

void Socket::Close()
{
  if (fd_) close(fd_);

  connected_ = false;
}

bool Socket::Recv(char* data, int& length)
{
  int ret = recv(fd_, data, MAX_BUFFER_SIZE - 1, 0);
  
  if (-1 == ret) {
    logger_->error("recv data failed, errno is {}", errno);
    return false;
  }

  length = ret;
  return true;
}

bool Socket::Send(const char* data, const int length)
{
  int ret = send(fd_, data, length, 0);

  if (-1 == ret) {
    logger_->info("data sends failed, errno is {}", errno);
    return false;
  }

  return true;
}

int Socket::GetFd() const noexcept { return fd_; }

Socket::Socket() { logger_ = Logger::GetInstance()->GetLogger(); }

Socket::Socket(int fd)
  : fd_(fd)
{
  logger_ = Logger::GetInstance()->GetLogger();
}

Socket::~Socket()
{
  if (fd_) close(fd_);

  connected_ = false;
}

bool operator==(const Socket& lhs, const Socket& rhs)
{
  return lhs.fd_ == rhs.fd_;
}

} // namespace TL