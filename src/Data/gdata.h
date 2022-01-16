#ifndef GRYPHON_GDATA_H
#define GRYPHON_GDATA_H

#include <stdint.h>
#include <vector>

namespace Data
{
    class Gdata
    {
      private:
        uint32_t _type;
        std::vector<uint32_t> _uint32;
      public:
        GData();
        uint32_t type();
        std::vector<uint32_t> data();
    };
}

#endif
