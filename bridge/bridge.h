#pragma once
#include <string>
namespace cdp {
namespace bridge {

/**
 * 这个设计模式的诀窍在于将具体实现隐藏到.cc文件而非.h文件中，
 * 好处是将具体实现彻底隐藏起来；如果将实现定义到头文件中，
 * 实现的信息实际还是会暴露出来，另外这么做对二进制兼容实际上
 * 也更方便，也对提高编译速度有帮助
 * 
*/

class Person {
 public:
  std::string name;
  void greet();
  Person();
  ~Person();

 private:
  // 前向声明Person的实现
  class PersonImpl;
  PersonImpl* impl;
};

} // namespace bridge
} // namespace cdp
