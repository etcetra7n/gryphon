#ifndef GRYPHON_PARSER_PARSER_H
#define GRYPHON_PARSER_PARSER_H

#include <stdint.h>
#include <string>

#define NULL_BYTE std::string("\0", 1)

namespace Parser
{
    class Parser
    {
      private:
        std::string             _rstr;
        std::string::size_type  _cursor;
      public:
                                Parser(const std::string&);
        bool                    active();
        int32_t                 parseInt32();
        int64_t                 parseInt64();
        char                    nextChar();
        char                    nextGlyph();
        bool                    follows(const std::string&);
        std::string             parseWord();
        std::string             parseTill(const std::string&);
        void                    ignoreTill(const std::string&);
        void                    jump(std::string::size_type n);
    };
    
    std::string trimEnds(const std::string&);
}

#endif
