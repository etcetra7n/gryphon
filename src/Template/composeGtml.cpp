#include "Template/template.h"

#include <vector>
#include <string>
#include <algorithm>
#include <ios>
#include <fstream>

#include "Template/gtml.h"
#include "Parser/endian.h"

namespace Template
{
    int composeGtml(Dom *document, const std::string &filepath)
    {
        std::ofstream file(filepath, std::ios::out | std::ios::binary);
        if(!file.good())
        {
            file.close();
            return 1;
        }

        std::vector<Element*> elements = document->elements();
        uint32_t major_version = Parser::hton32(GRYPHON_GTML_MAJOR_VERSION);
        uint32_t minor_version = Parser::hton32(GRYPHON_GTML_MINOR_VERSION);
        uint32_t patch_version = Parser::hton32(GRYPHON_GTML_PATCH_VERSION);
        uint64_t size = Parser::hton64(elements.size());
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
                std::vector<Element*>::size_type j = i;
                for (; j<=i; j--)
                {
                    if (elements[j] == elements[i]->parent())
                    {
                        break;
                    }
                }
                uint64_t parent_index = Parser::hton64(j+1);
                file.write(reinterpret_cast<char*>(&parent_index), sizeof(parent_index));
            }
            else
            {
                file.write("\0\0\0\0\0\0\0\0", 8);
            }
        }
        file.close();
        return 0;
    }
}
