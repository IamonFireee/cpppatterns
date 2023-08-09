#include "person_builder.h"
#include "person_address_builder.h"
#include "person_job_builder.h"

namespace cdp {
namespace builder {

PersonAddressBuilder PersonBuilderBase::lives() const { return PersonAddressBuilder{person}; }

PersonJobBuilder PersonBuilderBase::works() const { return PersonJobBuilder{person}; }

void UsageExampleForCombineBuilder() {
  Person p = Person::build()
                 .lives()
                 .at("123 London Road")
                 .with_postcode("SW1 1GB")
                 .in("London")
                 .works()
                 .company("PragmaSoft")
                 .position("Consultant");
}

} // namespace builder
} // namespace cdp
