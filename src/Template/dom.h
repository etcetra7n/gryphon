#ifndef GRYPHON_TEMPLATE_DOM_H
#define GRYPHON_TEMPLATE_DOM_H

#include <stdint.h>
#include <vector>
#include <string>
#include <map>

namespace Template
{
    class Element
    {
      private:
        std::string                           _name;
        std::string                           _value;
        std::map<std::string, std::string>    _attr;
        Element*                              _parent;
        std::vector<Element*>                 _children;
      public:
                                              Element();
        std::string                           name() const;
        std::string                           value() const;
        std::map<std::string, std::string>    attributes() const;
        std::vector<Element*>                 children() const;
        Element*                              parent() const;
        void                                  set_name(const std::string&);
        void                                  set_value(const std::string&);
        void                                  add_attr(const std::string&, const std::string&);
        void                                  set_parent(Element*);
        void                                  append_child(Element*);
    };

    class Dom
    {
      private:
        std::vector<Element*>                 _elements;
      public:
        void                                  reserve_space(uint64_t);
        Element*                              getElementByIndex(uint64_t);
        Element*                              new_element();
        std::vector<Element*>                 elements() const;
    };
}

#endif
