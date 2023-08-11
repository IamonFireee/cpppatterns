#pragma once

#include <cmath>
#include <memory>
#include <map>
#include <string>
#include <functional>
namespace cdp {
namespace factory {

class Point {
  friend class PointFactory;

 protected:
  // 隐藏构造函数
  Point(const float x, const float y) : x{x}, y{y} {}

 public:
  // 1. 工厂方法
  static Point NewCartesian(float x, float y) { return {x, y}; }
  static Point NewPloar(float r, float theta) { return {r * cos(theta), r * sin(theta)}; }

  // 2。 内部工厂类
  class PointFactoryInternal {
   public:
    static Point NewCartesian(float x, float y) { return {x, y}; }
    static Point NewPloar(float r, float theta) { return {r * cos(theta), r * sin(theta)}; }
  };

 private:
  float x;
  float y;
};

// 3. 工厂类
class PointFactory {
 public:
  static Point NewCartesian(float x, float y) { return {x, y}; }
  static Point NewPloar(float r, float theta) { return {r * cos(theta), r * sin(theta)}; }

};

// 4. 抽象工厂
struct HotDrink {
  virtual void prepare(int volume) = 0;
};

struct Tea: HotDrink {
  void prepare(int volume) override { return; }
};

struct Coffee: HotDrink {
  void prepare(int volume) override { return; }
};

struct HotDrinkFactory {
  virtual std::unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory {
  std::unique_ptr<HotDrink> make() const { return std::make_unique<Tea>(); }
};

struct CoffeeFactory : HotDrinkFactory {
  std::unique_ptr<HotDrink> make() const { return std::make_unique<Coffee>(); }
};

// 4.1 一种实现
class DrinkFactory {
 private:
  std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;

 public:
  DrinkFactory() {
    hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
    hot_factories["tea"] = std::make_unique<TeaFactory>();
  }
  
  std::unique_ptr<HotDrink> make_drink(const std::string &name) {
    auto drink = hot_factories[name]->make();
    // 将容量等公共属性抽离出来
    drink->prepare(200);
    return drink;
  }
};

// 4.2 另一种实现
class AnotherDrinkFactory {
 private:
  std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> hot_factories;

 public:
  AnotherDrinkFactory() {
    hot_factories["coffee"] = []() {
      auto c = std::make_unique<Coffee>();
      c->prepare(200);
      return c;
    };
    hot_factories["tea"] = []() {
      auto t = std::make_unique<Tea>();
      t->prepare(200);
      return t;
    };
  }

  std::unique_ptr<HotDrink> make_drink(const std::string& name) { return hot_factories[name](); }
};

void UsageExmapleForFactoryMethod();
void UsageExmapleForFactoryInternal();
void UsageExmapleForFactory();
void UsageExmapleForAbstractFactory();

}  // namespace factory
}  // namespace cdp
