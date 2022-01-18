#ifndef GRYPHON_TEMPLATE_GTEMPLATE_H
#define GRYPHON_TEMPLATE_GTEMPLATE_H

#include <vector>

namespace Template
{
    class Element;
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
