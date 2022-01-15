#include <stdint.h>
#include "endian.h"

namespace Parser
{
    uint8_t endian()
    {
        uint16_t _tnum = 0x0001;
        return (reinterpret_cast<char*>(&_tnum))[0]? LITTLE_ENDIAN : BIG_ENDIAN;
    }
}
