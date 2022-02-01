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
            parser.ignoreTill("gtml");
            parser.parseInt32();
            parser.parseInt32();
            parser.parseInt32();
            uint64_t size = Parser::ntoh64(parser.parseInt64());
            
            document->reserveSpace(size);
            
            for (uint64_t i = 0; i < size; i++)
            {
                Element *e = document->createElement();
                e->setName(parser.parseTill(NULL_BYTE));
                e->setValue(parser.parseTill(NULL_BYTE));
                while(parser.nextChar() != 0x00)
                {
                    std::string name = parser.parseTill(NULL_BYTE);
                    std::string value = parser.parseTill(NULL_BYTE);
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
