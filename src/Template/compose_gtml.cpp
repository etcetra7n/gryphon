#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <ios>
#include <algorithm>
#include <iostream>
#include "Template/gtml.h"
#include "Template/element.h"
#include "Template/template.h"
#include "gryphon.h"

//Writing a binary file, consistent across systems, requires standardized 
//endianness. So we will make sure the data is written in big endian

uint16_t _tnum = 0x0001;
const bool big_endian = (reinterpret_cast<char*>(&_tnum))[0]? 0 : 1;

inline uint32_t hton_32(const uint32_t x)
{
    return big_endian? x : __builtin_bswap32(x);
}
inline uint64_t hton_64(const uint64_t x)
{
    return big_endian? x : __builtin_bswap64(x);
}

namespace Template
{
    int compose_gtml(Template *tml, const std::string filepath)
    {
        std::ofstream file(filepath, std::ios::out | std::ios::binary);
        if(!file.good())
        {
            return 1;
        }
        
        std::vector<Element*> elements = *(tml->elements());
        uint32_t major_version = hton_32(GRYPHON_GTML_MAJOR_VERSION);
        uint32_t minor_version = hton_32(GRYPHON_GTML_MINOR_VERSION);
        uint32_t patch_version = hton_32(GRYPHON_GTML_PATCH_VERSION);
        uint64_t size = hton_64(elements.size());
        file.write("gtml", 4);
        file.write(reinterpret_cast<char*>(&major_version), sizeof(major_version));
        file.write(reinterpret_cast<char*>(&minor_version), sizeof(minor_version));
        file.write(reinterpret_cast<char*>(&patch_version), sizeof(patch_version));
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        
        for (std::vector<Element*>::size_type i = 0; i < elements.size(); i++)
        {
            std::string name = elements[i]->name();
            std::string value = elements[i]->value();
            file.write(name.c_str(), name.size()+1);
            file.write(value.c_str(), value.size()+1);
            for(auto m : elements[i]->attributes())
            {
                file.write(m.first.c_str(), m.first.size()+1);
                file.write(m.second.c_str(), m.second.size()+1);
            }
            file.write("\0", 1);
            if(elements[i]->parent() != nullptr)
            {
                auto loc = std::find(elements.begin(), elements.begin()+i, elements[i]->parent());
                uint64_t parent_index = hton_64(std::distance(elements.begin(), loc)+1);
                file.write(reinterpret_cast<char*>(&parent_index), sizeof(parent_index));
            }
            else
            {
                file.write("\0\0\0\0\0\0\0\0", 8);
            }
        }
        return 0;
    }
}
