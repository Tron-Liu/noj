#pragma once

#include "section.h"
#include <string>
#include <vector>

namespace TL {

class IniParser {
public:
  IniParser(std::string fileName);
  void print();

private:
  std::string fileName_;
  std::vector<Section> sections_;

  bool readInitFile();
  void parseLine(char *buf, int len);
};

} // namespace TL
