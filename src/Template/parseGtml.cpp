#include <stdint.h>
#include <string>
#include <fstream>
#include <sstream>
#include "Parser/parser.h"
#include "Template/dom.h"
#include "gryphon.h"

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
            uint32_t file_major_version = parser.parseInt32();
            uint32_t file_minor_version = parser.parseInt32();
            uint32_t file_patch_version = parser.parseInt32();
            uint64_t size = parser.parseInt64();
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
                e->setParent(document->getElementByIndex(parser.parseInt64()));
            }
        }
        else
        {
            return 1;
        }
        return 0;
    }
}
