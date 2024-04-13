#include "iniParser.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

namespace TL {

void IniParser::print() { std::cout << "hello world" << std::endl; }

bool IniParser::readInitFile() {
  std::ifstream file(fileName_, std::ios::in);
  if (!file.is_open()) {
    std::cout << "ini file open failed." << std::endl;
    return false;
  }

  char buf[1024] = {0};
  while (file.getline(buf, sizeof(buf))) {
    parseLine(buf, strlen(buf));
  }
  file.close();

  return true;
}

void IniParser::parseLine(char *buf, int len) {
  char ret[1024];
  memset(ret, '\0', 1024);

  for (int i = 0; i < len; i++) {
    int start = 0;
    int end = 0;
    if (buf[i] == SECTION_START_CHAR) {
      start = i;

    } else if (buf[i] == SECTION_END_CHAR) {
      end = i;
    } else {
    }
  }
  std::cout << len << std::endl;
  std::cout << buf << std::endl;
}

IniParser::IniParser(std::string fileName) : fileName_(fileName) {
  readInitFile();
}

} // namespace TL