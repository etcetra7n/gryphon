#include "Template/element.h"
#include "Template/template.h"
#include <iostream>

namespace Template
{
    Element *Template::new_element()
    {
        _elements.push_back(new Element());
        return _elements[_elements.size()-1];
    }

    std::vector<Element*> *Template::elements()
    {
        return &_elements;
    }
}
