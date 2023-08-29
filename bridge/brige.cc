#include "bridge.h"

namespace cdp {
namespace bridge {

class Person::PersonImpl {
 public:
  void greet(const Person* p) {
    // implement this
  }
};

Person::Person() : impl(new PersonImpl) {}

Person::~Person() { delete impl; }

void Person::greet() { impl->greet(this); }

} // namespace bridge
} // namespace cd