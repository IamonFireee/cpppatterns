#include "singleton.h"
#include <mutex>
namespace cdp {
namespace singleton {

Singleton* instance = nullptr;
std::mutex instance_mutex;

Singleton* Singleton::GetInstance() {
  std::lock_guard<std::mutex> lock(instance_mutex);
  if (instance == nullptr) {
    instance = new Singleton();
  }
  return instance;
}

void UsageExampleForSingleton() { 
  auto* instance = Singleton::GetInstance(); 
}

} // namespace singleton
} // namespace cdp
