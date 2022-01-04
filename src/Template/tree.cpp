#include "element.h"
#include "tree.h"
#include <iostream>

namespace Template
{
    Element *GGLTree::new_element()
    {
        _elements.push_back(new Element());
        return _elements[_elements.size()-1];
    }

    std::vector<Element*> *GGLTree::elements()
    {
        return &_elements;
    }
}
