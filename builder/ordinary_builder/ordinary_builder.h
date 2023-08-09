#pragma once

#include <vector>
#include <string>
#include <memory>
/**
 * cpp design patterns
*/
namespace cdp {
namespace builder {

class SimpleHtmlBuilder;

/**
 * the object we want build
*/
struct HtmlElement {
  std::string name;
  std::string text;
  std::vector<HtmlElement> elements;
  const int indent_size = 2;
  std::string str(int indent = 0) const {
    // 省略
    return "";
  }

  static std::unique_ptr<SimpleHtmlBuilder> build(const std::string& root_name) {
    return std::make_unique<SimpleHtmlBuilder>(root_name);
  }

 protected:
  friend class SimpleHtmlBuilder;
  HtmlElement() {}
  HtmlElement(const std::string& name, const std::string& text)
      : name(name), text(text) {}
};

struct SimpleHtmlBuilder {
  SimpleHtmlBuilder(const std::string& root_name) { root.name = root_name; }

  /**
   * 这里返回builder的引用，实现更流畅的使用体验
  */
  SimpleHtmlBuilder& add_child(const std::string& child_name, const std::string& child_text) {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return *this;
  }

  operator HtmlElement() { return root; }

  HtmlElement build() const { return root; }

  std::string str() const { return root.str(); }
 private:
  HtmlElement root;
};

void UsageExampleForSimpleBuilder();

} // namespace builder
} // namespace cdp
