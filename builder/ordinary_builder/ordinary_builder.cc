#include "ordinary_builder.h"

namespace cdp {
namespace builder {

void UsageExampleForSimpleBuilder() {
  HtmlElement e1 = (*HtmlElement::build("exmaple")).add_child("child1", "child1").add_child("child2", "child2").build();
  /**
   * 通过HtmlElement()方法，这样代码更简洁
  */
  HtmlElement e2 = (*HtmlElement::build("exmaple")).add_child("child1", "child1").add_child("child2", "child2");
}

} // namespace builder
} // namespace cdp
