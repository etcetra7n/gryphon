#include "Data/roll.h"

#include <stdint.h>
#include <vector>

namespace Data
{
    Roll::Roll()
    {}

    void Roll::setDimension(uint64_t dimension)
    {
        _dimension = dimension;
        _axlist.reserve(dimension);
    }

    void Roll::setSize(uint64_t size)
    {
        _size = size;
        for (uint64_t i=0; i<_dimension; i++)
            _axlist[i]->reserve(size);
    }

    uint64_t Roll::size() const
        { return _size; }

    uint64_t Roll::dimension() const
        { return _dimension; }

    std::vector<uint32_t> Roll::rtype() const
        { return _rtype; }

    void Roll::setAxis(uint64_t axis, std::vector<void*> &axdata)
        { _axlist[axis] = &axdata; }
}
