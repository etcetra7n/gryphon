#ifndef GRYPHON_ROLL_H
#define GRYPHON_ROLL_H

#include <stdint.h>
#include <vector>

#define INT32_AT   0x0000000000000000
#define UINT32_AT  0x0000000000000001
#define INT64_AT   0x0000000000000002
#define UINT64_AT  0x0000000000000003
#define FLOAT32_AT 0x0000000000000004
#define FLOAT64_AT 0x0000000000000005

namespace Data
{
    class Roll
    {
      private:
        uint64_t                          _dimension;
        uint64_t                          _size;
        std::vector<uint32_t>             _rtype;
        std::vector<std::vector<void*>*>  _axlist;
      public:
                                          Roll();
        uint64_t                          size() const;
        uint64_t                          dimension() const;
        std::vector<uint32_t>             rtype() const;
        void                              setAxis(uint64_t, std::vector<void*>&);
        void                              setSize(uint64_t);
        void                              setDimension(uint64_t);
    };
}

#endif
