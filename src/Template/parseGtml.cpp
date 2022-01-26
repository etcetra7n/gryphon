#include "gryphon.h"

#include <stdint.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Template/dom.h"
#include "Parser/parser.h"
#include "Parser/endian.h"

namespace Template
{
    int parseGtml(Dom *document, const std::string &filepath)
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
            parser.parseTill("gtml");
            uint32_t file_major_version = Parser::ntoh32(parser.parseInt32());
            uint32_t file_minor_version = Parser::ntoh32(parser.parseInt32());
            uint32_t file_patch_version = Parser::ntoh32(parser.parseInt32());
            uint64_t size = Parser::ntoh64(parser.parseInt64());
            
            std::cout << file_major_version << std::endl;
            std::cout << file_minor_version << std::endl;
            std::cout << file_patch_version << std::endl;
            std::cout << size << std::endl;
            
            exit(0);
            
            document->reserveSpace(size);
            for (uint64_t i = 0; i < size; i++)
            {
                Element *e = document->createElement();
                e->setName(parser.parseTill("\0"));
                e->setValue(parser.parseTill("\0"));
                while(parser.nextChar() != '\0')
                {
                    std::string name = parser.parseTill("\0");
                    std::string value = parser.parseTill("\0");
                    e->setAttribute(name, value);
                }
                parser.jump(1);
                uint64_t parent = Parser::ntoh64(parser.parseInt64());
                e->setParent(document->getElementByIndex(parent));
            }
        }
        else
        {
            return 1;
        }
        return 0;
    }
}
