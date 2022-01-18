#ifndef GRYPHON_TEMPLATE_GTEMPLATE_H
#define GRYPHON_TEMPLATE_GTEMPLATE_H

#include <vector>
#include <string>
#include <map>
#include "Template/element.h"

namespace Template
{
    class Gtemplate : public Element
    {
      private:
        std::vector<Element*> _elements;
      public:
        Element *new_element();
        std::vector<Element*> elements();
    };
}

#endif
