#include "Template/dom.h"

#include <stdint.h>
#include <vector>

namespace Template
{
    Element *Dom::createElement()
    {
        Element *new_elem = new Element();
        _elements.push_back(new_elem);
        return new_elem;
    }

    Element *Dom::getElementByIndex(uint64_t index)
    {
        return _elements[index];
    }

    void Dom::reserveSpace(std::vector<Element*>::size_type size)
    {
        _elements.reserve(size);
    }

    std::vector<Element*> Dom::elements() const
    {
        return _elements;
    }
}
