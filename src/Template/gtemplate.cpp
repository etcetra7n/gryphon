#include <iostream>
#include <vector>
#include "Template/element.h"
#include "Template/gtemplate.h"

namespace Template
{
    Element *Gtemplate::new_element()
    {
        Element *new_elem = new Element();
        _elements.push_back(new_elem);
        return new_elem;
    }

    std::vector<Element*> Gtemplate::elements()
    {
        return _elements;
    }
}
