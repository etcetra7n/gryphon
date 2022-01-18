#ifndef GRYPHON_TEMPLATE_ELEMENT_H
#define GRYPHON_TEMPLATE_ELEMENT_H

#include <vector>
#include <string>
#include <map>

namespace Template
{
    class Element
    {
      private:
        std::string _name;
        std::string _value;
        std::map<std::string, std::string> _attr;
        Element *_parent;
        std::vector<Element*> _children;
      public:
        Element();
        std::string name();
        std::string value();
        std::map<std::string, std::string> attributes();
        std::vector<Element*> children();
        Element *parent();
        void set_name(const std::string);
        void set_value(const std::string);
        void add_attr(const std::string, const std::string);
        void append_child(Element*);
    };
}

#endif
