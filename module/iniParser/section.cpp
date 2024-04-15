#include "section.h"
#include <string>
#include <utility>

namespace TL {

std::string Section::Value(const std::string& key) const noexcept
{
  auto iter = options_.find(key);
  if (iter != options_.end())
    return iter->second;
  else
    return "";
}

void Section::Insert(std::string&& key, std::string&& value) noexcept
{
  options_.insert(std::pair<std::string, std::string>(key, value));
}

void Section::SetName(std::string name) { name_ = name; }

Section::Section(const std::string& name)
  : name_(name)
{
}

Section::Section() { }

} // namespace TL