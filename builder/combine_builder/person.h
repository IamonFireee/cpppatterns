#pragma once
#include <string>

namespace cdp {
namespace builder {

class PersonBuilder;

struct Person {
  std::string street_address;
  std::string post_code;
  std::string city;
  std::string company_name;
  std::string position;
  int annual_income = 0;
  static PersonBuilder build();
};

} // namespace builder
} // namespace cdp
