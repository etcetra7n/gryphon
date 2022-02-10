#include "Data/roll.h"

#include <stdint.h>
#include <vector>

namespace Data
{
    Roll::Roll(uint64_t dimension, uint64_t size, const std::vector<uint32_t> &rtype):
        _dimension(dimension),
        _size(size),
        _rtype(rtype)
    {
        _axlist.reserve(dimension);
        for (uint64_t i=0; i<dimension; i++)
            _axlist[i]->reserve(size);
    }

    uint64_t Roll::size() const
        { return _size; }

    uint64_t Roll::dimension() const
        { return _dimension; }

    std::vector<uint32_t> Roll::rtype() const
        { return _rtype; }

    void Roll::setAxis(uint64_t index, std::vector<void*> &axis)
        { _axlist[index] = &axis; }
}
