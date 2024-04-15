#include "iniParser.h"
#include "section.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <memory>
#include <ostream>
#include <string>
#include <utility>

namespace TL {

namespace fs = std::filesystem;

IniParser* IniParser::instance_ = nullptr;

IniParser* IniParser::GetInstance()
{
  if (instance_ == nullptr) {
    auto binaryPath         = fs::current_path();
    std::string projectPath = binaryPath.parent_path().parent_path();
    std::string iniFileName = "conf.ini";

    instance_ = new IniParser(projectPath, iniFileName);

    return instance_;
  }

  return instance_;
}

std::shared_ptr<Section>
IniParser::GetSection(const std::string& name) const noexcept
{
  auto iter = iniData_.find(name);
  if (iter != iniData_.end()) {
    return iter->second;
  }

  return nullptr;
}

bool IniParser::LoadConfig()
{
  std::ifstream file(filePath_ + '/' + fileName_, std::ios::in);
  if (!file.is_open()) {
    std::cout << "ini file open failed." << std::endl;
    return false;
  }

  char buf[BUFFER_SIZE]            = { 0 };
  std::shared_ptr<Section> section = nullptr;

  std::string key;
  std::string value;
  std::string name;

  while (file.getline(buf, sizeof(buf))) {
    LineType lineType = LineType::DEFAULT;
    char temp[BUFFER_SIZE];
    memset(temp, '\0', BUFFER_SIZE);
    int j = 0;

    int len = strlen(buf);
    for (int i = 0; i < len; i++) {
      if (buf[i] == SECTION_START_CHAR) {
        section  = std::make_shared<Section>();
        lineType = LineType::SECTION;
        continue;
      }
      if (buf[i] == SECTION_END_CHAR && lineType == LineType::SECTION) {
        name = temp;
        section->SetName(name);
        continue;
      }
      if (buf[i] == OPTION_SPLIT_CHAR) {
        key = temp;
        memset(temp, '\0', BUFFER_SIZE);
        j        = 0;
        lineType = LineType::OPTION;
        continue;
      }
      if (buf[i] == COMMENT_CHAR) {
        lineType = LineType::COMMENT;
        break;
      }
      if (buf[i] == SPACE_CHAR) {
        continue;
      }

      // not special char
      temp[j++] = buf[i];
    }
    temp[j] = '\0';

    if (lineType == LineType::OPTION) {
      value = temp;

      if (section != nullptr) {
        section->Insert(std::move(key), std::move(value));
        iniData_.insert(std::make_pair(name, section));
      }
    }
  }
  file.close();

  return true;
}

IniParser::IniParser(const std::string& filePath, const std::string& fileName)
  : filePath_(filePath)
  , fileName_(fileName)
{
  LoadConfig();
}

} // namespace TL