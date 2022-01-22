#include <stdint.h>
#include <string>
#include <fstream>
#include <sstream>
#include "Parser/parser.h"
#include "Template/dom.h"
#include "gryphon.h"

namespace Template
{
    int parse_gtml(Dom *document, const std::string &filepath)
    {
        std::ifstream file(filepath, std::ios::in);
        std::stringstream buffer;
        if(!file.good())
        {
            return 1;
        }
        buffer << file.rdbuf();
        file.close();
        
        Parser::Parser parser(buffer.str());
        
        if(parser.active())
        {
            parser.parse_till("gtml");
            /*
            uint32_t file_major_version = parser.parse_int32()
            uint32_t file_minor_version = parser.parse_int32()
            uint32_t file_patch_version = parser.parse_int32()
            uint64_t size = parser.parse_int64()
            for (uint64_t i = 0; i < size; i++)
            {
                ;//TODO
            }
            */
        }
        else
        {
            return 1;
        }
        
        return 0;
    }
}

