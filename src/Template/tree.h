#ifndef GRYPHON_TREE_H
#define GRYPHON_TREE_H

#include <vector>
#include "element.h"

namespace Template
{
    class GGLTree
    {
      private:
        std::vector<Element*> _elements;
      public:
        Element *new_element();
        std::vector<Element*> *elements();
    };
}

#endif
