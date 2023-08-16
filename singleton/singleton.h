#pragma once
#include <string>
namespace cdp {
namespace singleton {

class Singleton {
 private:
  // 将构造函数隐藏起来
  Singleton() {}
 public:
  static Singleton* GetInstance();
  // 禁用拷贝构造和拷贝复制
  Singleton(const Singleton& other) = delete;
  Singleton& operator=(const Singleton& other) = delete;
};

void UsageExampleForSingleton();

} // namespace singleton
} // namespace cdp
