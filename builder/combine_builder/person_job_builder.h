#pragma once
#include "person_builder.h"

namespace cdp {
namespace builder {

class PersonAddressBuilder : public PersonBuilderBase {
 public:
  explicit PersonAddressBuilder(Person& person) : PersonBuilderBase{person} {}
  PersonAddressBuilder& at(std::string street_address) {
    person.street_address = street_address;
    return *this;
  }

  PersonAddressBuilder& with_postcode(std::string post_code) { 
    person.post_code = post_code;
    return *this;
  }

  PersonAddressBuilder& in(std::string city) { 
    person.city = city;
    return *this;
  }
};

} // namespace bulder
} // namespace cdp
