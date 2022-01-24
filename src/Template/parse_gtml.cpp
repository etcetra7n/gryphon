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
            file.close();
            return 1;
        }
        buffer << file.rdbuf();
        file.close();

        Parser::Parser parser(buffer.str());

        if(parser.active())
        {
            parser.parse_till("gtml");
            uint32_t file_major_version = parser.parse_int32();
            uint32_t file_minor_version = parser.parse_int32();
            uint32_t file_patch_version = parser.parse_int32();
            uint64_t size = parser.parse_int64();
            document->reserve_space(size);
            for (uint64_t i = 0; i < size; i++)
            {
                Element *e = document->new_element();
                e->set_name(parser.parse_till("\0"));
                e->set_value(parser.parse_till("\0"));
                while(parser.next_char() != '\0')
                {
                    std::string name = parser.parse_till("\0");
                    std::string value = parser.parse_till("\0");
                    e->add_attr(name, value);
                }
                parser.jump(1);
                e->set_parent(document->getElementByIndex(parser.parse_int64()));
            }

        }
        else
        {
            return 1;
        }
        return 0;
    }
}
