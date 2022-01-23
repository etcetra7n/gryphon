#ifndef GRYPHON_PARSER_PARSER_H
#define GRYPHON_PARSER_PARSER_H

#include <stdint.h>
#include <string>

namespace Parser
{
    class Parser
    {
      private:
        std::string _rstr;
        std::string::size_type _cursor;
      public:
        Parser(const std::string&);
        bool active();
        int32_t parse_int32();
        int64_t parse_int64();
        char next_char();
        char next_glyph();
        bool begins_with(const std::string&);
        std::string parse_word();
        std::string parse_till(const std::string&);
        void ignore_till(const std::string&);
        void jump(std::string::size_type n);
    };
}

#endif
