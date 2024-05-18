/**
 * @file socket.h
 * @author Tron-Liu (Tron-Liu@foxmail.com)
 * @brief The socket class
 * @version 0.1
 * @date 2024-05-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "logger.h"

namespace TL {

class Socket {
private:
  int fd_         = 0;
  bool connected_ = false;

  std::shared_ptr<spdlog::logger> logger_;

public:
  /**
   * @brief Create a socket based on IPv4 and TCP
   * 
   * @return true The socket create successfully
   */
  bool Create();

  /**
   * @brief Bind a socket with the given ip and port
   * 
   * @param[in] ip        IP Address
   * @param[in] port      The port for listening
   *
   * @return true         Bind successfully
   */
  bool Bind(std::string ip, int port);

  /**
   * @brief Listen for connection on the socket
   * 
   * @param[in] maxNum    The max number of listening queue
   *
   * @return true         Listen successfully
   */
  bool Listen(int maxNum = 50) const noexcept;

  /**
   * @brief 
   * 
   * @param[out] connfd    Comment
   * @return true         Comment
   */
  bool Accept(std::shared_ptr<Socket>& connfd);

  void Close();

  int Recv(char* buffer);
  int Send();

  /**
   * @brief Get the current socket's file descriptor
   * 
   * @return int   "file descriptor"
   */
  int GetFd() const noexcept;

public:
  Socket();
  Socket(int fd);
  ~Socket();

  friend bool operator==(const Socket& lhs, const Socket& rhs);
};

} // namespace TL
