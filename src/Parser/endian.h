#ifndef GRYPHON_PARSER_ENDIAN_H
#define GRYPHON_PARSER_ENDIAN_H

#include <stdint.h>

#define BIG_ENDIAN_ORDER 1
#define LITTLE_ENDIAN_ORDER 2

namespace Parser
{
    uint8_t endian();
    inline uint32_t hton_32(const uint32_t x)
    {
        return ((endian() == BIG_ENDIAN_ORDER)? x : __builtin_bswap32(x));
    }
    inline uint64_t hton_64(const uint64_t x)
    {
        return ((endian() == BIG_ENDIAN_ORDER)? x : __builtin_bswap64(x));
    }
}

#endif
