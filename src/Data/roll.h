#ifndef GRYPHON_ROLL_H
#define GRYPHON_ROLL_H

#include <stdint.h>
#include <vector>

namespace Data
{
    class Roll
    {
      private:
        uint32_t                            _type;
        std::vector<uint32_t>               _uint32;
      public:
        Roll();
        uint32_t                            type() const;
        std::vector<uint32_t>::size_type    size() const;
        std::vector<uint32_t>               data() const;
    };
}

#endif
