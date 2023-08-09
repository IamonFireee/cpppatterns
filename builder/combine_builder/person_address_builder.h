#pragma once
#include "person_builder.h"

namespace cdp {
namespace builder {
  
class PersonJobBuilder : public PersonBuilderBase {
 public:
  explicit PersonJobBuilder(Person& person) : PersonBuilderBase{person} {}
  
  PersonJobBuilder& company(const std::string& company) {
    person.company_name = company;
    return *this;
  }

  PersonJobBuilder& position(const std::string& position) {
    person.position = position;
    return *this;
  }
};

} // namespace bulder
} // namespace cdp
