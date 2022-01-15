#include "Template/element.h"
#include "Template/gtemplate.h"

namespace Template
{
    Element *Gtemplate::new_element()
    {
        _elements.push_back(Element());
        return &_elements[_elements.size()-1];
    }

    std::vector<Element> Gtemplate::elements()
    {
        return std::copy(_elements.begin(), _elements.end();
    }
}
