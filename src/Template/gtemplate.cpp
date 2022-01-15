#include <algorithm>
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
        std::vector<Element> elements_copy;
        elements_copy.reserve(_elements.size());
        std::copy(_elements.begin(), _elements.end(), elements_copy.begin());
        return elements_copy;
    }
}
