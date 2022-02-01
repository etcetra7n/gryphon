#ifndef GRYPHON_TEMPLATE_TEMPLATE_H
#define GRYPHON_TEMPLATE_TEMPLATE_H

#include <string>
#include "Template/dom.h"

namespace Template
{
    int parseGtml(Dom *, const std::string &);
    int composeGtml(Dom *, const std::string &);
}

#endif
