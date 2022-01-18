#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include "Template/gtemplate.h"

namespace Template
{
    Element::Element()
    {
        _parent = nullptr;
    }

    std::string Element::name()
    {
        return _name;
    }

    std::string Element::value()
    {
        return _value;
    }

    std::map<std::string, std::string> Element::attributes()
    {
        return _attr;
    }

    std::vector<Element*> Element::children()
    {
        return _children;
    }

    Element *Element::parent()
    {
        return _parent;
    }

    void Element::set_name(const std::string name)
    {
        _name = name;
    }

    void Element::set_value(const std::string value)
    {
        _value = value;
    }

    void Element::add_attr(const std::string name, const std::string value)
    {
        _attr.insert({name, value});
    }

    void Element::append_child(Element* child)
    {
        _children.push_back(child);
        child->_parent = this;
    }

    Element *Gtemplate::new_element()
    {
        Element *new_elem = new Element();
        _elements.push_back(new_elem);
        return new_elem;
    }

    std::vector<Element*> Gtemplate::elements()
    {
        return _elements;
    }
}
