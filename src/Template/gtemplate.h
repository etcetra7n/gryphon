#ifndef GRYPHON_TEMPLATE_GTEMPLATE_H
#define GRYPHON_TEMPLATE_GTEMPLATE_H

#include <vector>
#include "Template/element.h"

namespace Template
{
    class Gtemplate
    {
      private:
        std::vector<Element*> _elements;
      public:
        Element *new_element();
        std::vector<Element*> elements();
    };
}

#endif
