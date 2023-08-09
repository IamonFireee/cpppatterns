#pragma once
#include <utility>
#include "person.h"

namespace cdp {
namespace builder {

class PersonAddressBuilder;
class PersonJobBuilder;


class PersonBuilderBase {
 protected:
  Person& person;
  explicit PersonBuilderBase(Person& person) : person{person} {}

 public:
  operator Person() { return std::move(person); }
  // builder facets
  virtual PersonAddressBuilder lives() const;
  virtual PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase {
 public:
  PersonBuilder() : PersonBuilderBase{p} {}
private:
  Person p;
};

void UsageExampleForCombineBuilder();


} // namespace builder
} // namespace cdp
