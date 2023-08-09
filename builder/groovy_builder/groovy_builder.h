#pragma once
#include <string>
#include <iostream>
#include <vector>
namespace cdp {
namespace builder {

/**
 * the object we want build
*/
struct Tag {
  std::string name;
  std::string text;
  std::vector<Tag> children;
  std::vector<std::pair<std::string, std::string>> attributes;
  friend std::ostream& operator<<(std::ostream& os, const Tag& tag) {
    // 省略
    return os;
  }

 protected:
  Tag(const std::string& name, const std::string& text)
      : name{name}, text{text} {}
  Tag(const std::string& name, const std::vector<Tag>& children)
      : name{name}, children{children} {}
};


struct P : public Tag {
  explicit P(const std::string& text) : Tag{"p", text} {}
  P(std::initializer_list<Tag> children) : Tag("p", children) {}
};

struct IMG : public Tag {
  explicit IMG(const std::string& url) : Tag{"img", ""} {
    attributes.emplace_back(std::make_pair("src", url));
  }
};

void UsageExampleForGroovyBuilder();

} // namespace builder
} // namespace cdp
