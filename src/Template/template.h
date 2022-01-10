#ifndef GRYPHON_TEMPLATE_TEMPLATE_H
#define GRYPHON_TEMPLATE_TEMPLATE_H

#include <vector>
#include "Template/element.h"

namespace Template
{
    class Template
    {
      private:
        std::vector<Element*> _elements;
      public:
        Element *new_element();
        std::vector<Element*> *elements();
    };
}

#endif
