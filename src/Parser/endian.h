#ifndef GRYPHON_PARSER_ENDIAN_H
#define GRYPHON_PARSER_ENDIAN_H

#include <stdint.h>

#define BIG_ENDIAN 1
#define LITTLE_ENDIAN 2

namespace Parser
{
    uint8_t endian();
    inline uint32_t hton_32(const uint32_t x)
    {
        return ((endian() == BIG_ENDIAN)? x : __builtin_bswap32(x));
    }
    inline uint64_t hton_64(const uint64_t x)
    {
        return ((endian() == BIG_ENDIAN)? x : __builtin_bswap64(x));
    }
}

#endif
