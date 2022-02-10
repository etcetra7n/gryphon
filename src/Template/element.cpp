#include "Template/dom.h"

#include <cstdlib>
#include <vector>
#include <string>
#include <map>

namespace Template
{
    Element::Element():
        _parent(nullptr)
    {}

    std::string Element::name() const
        { return _name; }
    std::string Element::value() const
        { return _value; }
    std::map<std::string, std::string> Element::attributes() const
        { return _attr; }
    std::vector<Element*> Element::children() const
        { return _children; }
    Element *Element::parent() const
        { return _parent; }
    void Element::setName(const std::string &name)
        { _name = name; }
    void Element::setValue(const std::string &value)
        { _value = value; }
    void Element::setAttribute(const std::string &name, const std::string &value)
        { _attr.insert({name, value}); }
    void Element::setParent(Element *parent)
        { _parent = parent; }
    void Element::appendChild(Element* child)
    {
        _children.push_back(child);
        child->_parent = this;
    }
}
