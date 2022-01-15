#include "Data/gdata.h"
#include "Template/gtemplate.h"
#include "gryphon.h"

namespace Data
{
    Data *parse_gdt(const std::string filepath)
    {
        return new Gdata;
    }
}
