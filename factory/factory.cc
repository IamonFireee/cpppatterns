#include "factory.h"

namespace cdp {
namespace factory {

void UsageExmapleForFactoryMethod() { 
  Point a = Point::NewCartesian(1, 1);
  Point b = Point::NewPloar(1, 1);
}

void UsageExmapleForFactoryInternal() {
  Point a = Point::PointFactoryInternal::NewCartesian(1, 1);
  Point b = Point::PointFactoryInternal::NewPloar(1, 1);
}

void UsageExmapleForFactory() {
  Point a = PointFactory::NewCartesian(1, 1);
  Point b = PointFactory::NewPloar(1, 1);
}

void UsageExmapleForAbstractFactory() {
  DrinkFactory factory;
  auto a = factory.make_drink("tea");

  AnotherDrinkFactory another_factory;
  auto b = factory.make_drink("coffee");
}

} // namespace factory
} // namespace cdp
