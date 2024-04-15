#pragma once

#include "section.h"

#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace TL {

const int BUFFER_SIZE = 1024;

class IniParser {
public:
  static IniParser* GetInstance();
  std::shared_ptr<Section> GetSection(const std::string& name) const noexcept;

private:
  static IniParser* instance_;

  std::string fileName_;
  std::string filePath_;
  std::unordered_map<std::string, std::shared_ptr<Section>> iniData_;

  enum LineType { SECTION, COMMENT, OPTION, DEFAULT };

private:
  bool LoadConfig();
  void ParseLine(char* buf);
  std::string&& SectionName(char* buf);

  IniParser(const std::string& filePath, const std::string& fileName);
};

} // namespace TL
