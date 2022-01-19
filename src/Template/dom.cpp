#include <vector>
#include "Template/dom.h"

namespace Template
{
    Element *Dom::new_element()
    {
        Element *new_elem = new Element();
        _elements.push_back(new_elem);
        return new_elem;
    }

    std::vector<Element*> Dom::elements()
    {
        return _elements;
    }
}
