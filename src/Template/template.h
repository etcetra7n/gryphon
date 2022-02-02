#ifndef GRYPHON_TEMPLATE_TEMPLATE_H
#define GRYPHON_TEMPLATE_TEMPLATE_H

#include <string>
#include "Template/dom.h"

namespace Template
{
    int parseGTML(Dom *, const std::string &);
    int composeGTML(Dom *, const std::string &);
}

#endif
