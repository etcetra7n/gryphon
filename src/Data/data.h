#ifndef GRYPHON_DATA_H
#define GRYPHON_DATA_H

#include "gryphon.h"

namespace Data
{
    class Data
    {
      private:
        uint32_t _dtype;
        std::vector<uint32_t> _uint32;
      public:
        Data();
        uint32_t dtype();
        std::vector<uint32_t> data();
    };
}

#endif
