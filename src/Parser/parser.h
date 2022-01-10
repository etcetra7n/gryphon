#ifndef GRYPHON_TEMPLATE_PARSER_H
#define GRYPHON_TEMPLATE_PARSER_H

#include <string>

namespace Parser
{
    class Parser
    {
      private:
        std::string _raw_str;
        std::string::size_type _cursor;
      public:
        Parser(const std::string);
        bool active();
        void ignore_till(const std::string);
        std::string parse_till(const std::string);
        std::string parse_alpha();
        bool begins_with(const std::string);
        char next_non_space_char();
    };
}

#endif
