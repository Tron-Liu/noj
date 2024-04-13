#pragma once

#include <string>
#include <unordered_map>

namespace TL {

const char SECTION_START_CHAR = '[';
const char SECTION_END_CHAR = '[';

class Section {
private:
  std::string name;
  std::unordered_map<std::string, std::string> keys;
public:
  std::string key(std::string) const;
};

} // namespace TL
