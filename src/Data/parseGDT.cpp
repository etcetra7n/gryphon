#include "Data/data.h"

#include <stdint.h>

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Parser/parser.h"
#include "Parser/endian.h"

namespace Data
{
    int parseGDT(Roll *roll, const std::string &filepath)
    {
        std::ifstream file(filepath, std::ios::in);
        std::stringstream buffer;
        if(!file.good())
        {
            file.close();
            return 1;
        }
        buffer << file.rdbuf();
        file.close();

        Parser::Parser parser(buffer.str());

        if(parser.active())
        {
            parser.ignoreTill("gdt");
            parser.parseInt32();
            parser.parseInt32();
            parser.parseInt32();

            uint64_t dimension = parser.parseInt64();
            roll.setDimension(dimension);
            uint64_t size = parser.parseInt64();
            roll.setSize(size);

            std::vector<uint32_t> rtype(dimension);
            for (uint64_t i=0; i<dimension; i++)
            {
                uint32_t axtype = parser.parseInt32();
                rtype.push_back(axtype);
            }
            roll.setRtype(rtype);

            std::vector<std::string> labels(dimension);
            for (uint64_t i=0; i<dimension; i++)
            {
                std::string label = parser.parseTill(NULL_BYTE);
                labels.push_back(label);
            }
            roll.setLabels(labels);

            for (uint64_t axis=0; axis<dimension; axis++)
            {
                uint64_t itemsize = 0;
                switch(rtype[axis])
                {
                    case INT32_AT:
                        itemsize = INT32_AT_SIZE; break;
                    case UINT32_AT:
                        itemsize = UINT32_AT_SIZE; break;
                    default:
                        return 2;
                }
                axsize = itemsize*size;
                std::string rawdata = parser.parseFor(axsize);
                std::vector<void*> axdata = reinterpret_cast<std::vector<void*>>(rawdata.c_str());
                roll.setAxis(axis, axdata);
            }
        }
        else { return 1; }
        return 0;
    }
}

/*
for (uint64_t axis=0; axis<dimension; axis++)
{
    switch(rtype[axis])
    {
        case INT32_AT:
            typedef int32_t type; break;
        case UINT32_AT:
            typedef uint32_t type; break;
        default:
            return 2;
    }
    std::vector<void*> axdata(size);
    for (uint64_t i=0, i<size; i++)
    {
        type item = parser.parseCustomType(type);
        axdata.push_back(item)
    }
    roll.setAxis(axis, axdata);
}
*/
