#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

namespace TL {

const char SECTION_START_CHAR = '[';
const char SECTION_END_CHAR   = ']';
const char OPTION_SPLIT_CHAR  = '=';
const char COMMENT_CHAR       = ';';
const char SPACE_CHAR         = ' ';

class Section {
private:
  std::string name_;
  std::unordered_map<std::string, std::string> options_;

public:
  std::string Value(const std::string& key) const noexcept;
  void Insert(std::string&& key, std::string&& value) noexcept;
  void SetName(std::string name);

  Section(const std::string& name);
  Section();
};

} // namespace TL
