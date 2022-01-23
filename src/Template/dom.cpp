#include <stdint.h>
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

    Element *Dom::getElementByIndex(uint64_t index)
    {
        return _elements[index];
    }

    void Dom::reserve_space(uint64_t size)
    {
        _elements.reserve(size);
    }

    std::vector<Element*> Dom::elements() const
    {
        return _elements;
    }
}
