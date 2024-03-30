#pragma once
#include <mutex>

// 饿汉式
class ClassicSingleton {
 private:
  ClassicSingleton() = default;
  ~ClassicSingleton() = default;
  ClassicSingleton& operator=(const ClassicSingleton& other) = delete;
  ClassicSingleton(const ClassicSingleton& other) = delete;

 private:
  static ClassicSingleton* instance;

 public:
  static ClassicSingleton& getInstance() { return *instance; }
};

// 懒汉式1
class MayersSingleton {
 private:
  MayersSingleton() = default;
  ~MayersSingleton() = default;
  MayersSingleton& operator=(const MayersSingleton& other) = delete;
  MayersSingleton(const MayersSingleton& other) = delete;

 public:
  static MayersSingleton& getInstance() {
    static MayersSingleton instance;
    return instance;
  }
};

// 懒汉式2
class DoubleCheckSingleton {
 private:
  DoubleCheckSingleton() = default;
  ~DoubleCheckSingleton() = default;
  DoubleCheckSingleton& operator=(const DoubleCheckSingleton& other) = delete;
  DoubleCheckSingleton(const DoubleCheckSingleton& other) = delete;

 private:
  static DoubleCheckSingleton* instance;
  static std::mutex mutex;

 public:
  static DoubleCheckSingleton& getInstance() {
    if (instance == nullptr) {
      std::lock_guard<std::mutex> lock(mutex);
      if (instance == nullptr) {
        instance = new DoubleCheckSingleton();
      }
    }
    return *instance;
  }
};