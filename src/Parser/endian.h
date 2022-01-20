#ifndef GRYPHON_PARSER_ENDIAN_H
#define GRYPHON_PARSER_ENDIAN_H

#include <stdint.h>

#define BIG_ENDIAN_ORDER 1
#define LITTLE_ENDIAN_ORDER 2

#ifdef __GNUC__
#define BSWAP32(x) (__builtin_bswap32(x))
#define BSWAP64(x) (__builtin_bswap64(x))
#else
#define BSWAP32(x) (_byteswap_ulong(x))
#define BSWAP64(x) (_byteswap_uint64(x))
#endif

namespace Parser
{
    uint8_t endian();
    inline uint32_t hton_32(const uint32_t x)
    {
        return ((endian() == BIG_ENDIAN_ORDER)? x : BSWAP32(x));
    }
    inline uint64_t hton_64(const uint64_t x)
    {
        return ((endian() == BIG_ENDIAN_ORDER)? x : BSWAP64(x));
    }
}

#endif
