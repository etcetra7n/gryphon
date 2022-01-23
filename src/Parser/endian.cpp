#include <stdint.h>
#include "endian.h"

namespace Parser
{
    constexpr uint8_t endian()
    {
        uint16_t _tnum = 0x0001;
        return (reinterpret_cast<char*>(&_tnum))[1]? BIG_ENDIAN_ORDER : LITTLE_ENDIAN_ORDER;
    }
}
