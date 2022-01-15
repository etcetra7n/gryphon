#ifndef GRYPHON_DATA_H
#define GRYPHON_DATA_H

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
        Data();
        uint32_t type();
        std::vector<uint32_t> data();
    };
}

#endif
