#include <string>
#include "parser.h"

namespace Parser
{
    Parser::Parser(const std::string rstr): 
        _raw_str(rstr), 
        _cursor(0) 
    {}

    bool Parser::active()
    {
        /*Returns true if the part of the raw string that comes
        after the cursor has non space charecters to parse*/
        bool res = false;
        for (std::string::size_type i = _cursor; i < _raw_str.size(); i++)
        {
            if (!isspace(_raw_str[i]))
            {
                res = true;
                break;
            }
        }
        return res;
    }

    void Parser::ignore_till(const std::string sequence)
    {
        /*Places the pointer right after the first occurence of 'sequence'*/
        std::string::size_type occ = _raw_str.find(sequence, _cursor);
        if (occ != std::string::npos)
            _cursor = occ+1;
    }

    std::string Parser::parse_till(const std::string sequence)
    {
        /*returns the string beteen the cursor and the sequence, 
        not including the sequence itself, and places the cursor right
        after the sequence. Returns an empty string "" if the sequence
        is not found*/
        std::string::size_type begin = _cursor;
        std::string::size_type end = _raw_str.find(sequence, _cursor);
        if (end != std::string::npos)
        {
            _cursor = end+1;
            return _raw_str.substr(begin, end-begin);
        }
        else
        {
            return "";
        }
    }

    std::string Parser::parse_alpha()
    {
        /*returns a string containing a sequence of non-space charecters
        that comes after the cursor, and places the cursor right after
        the sequence*/
        std::string::size_type begin;
        std::string::size_type end;
        for (begin = _cursor; begin < _raw_str.size(); begin++)
        {
            if (!isspace(_raw_str[begin]))
            {
                break;
            }
        }
        for (end = begin+1; end < _raw_str.size(); end++)
        {
            if (!isalnum(_raw_str[end]))
                break;
        }
        _cursor = end;
        return _raw_str.substr(begin, end-begin);
    }

    bool Parser::begins_with(const std::string sequence)
    {
        /*returns true if sequence is the substring that follows either 
        immediately or after some whitespace charecters after the cursor,
        without moving the cursor pointer*/
        std::string::size_type begin;
        for (begin = _cursor; begin < _raw_str.size(); begin++)
        {
            if (!isspace(_raw_str[begin]))
                break;
        }
        if (_raw_str.size()-begin >= sequence.size())
            return (_raw_str.substr(begin, sequence.size()) == sequence);
        else 
            return false;
    }

    char Parser::next_non_space_char()
    {
        /*returns the charecter that follows either immediately or after some
        whitespacecharecters after the cursor, without moving the cursor. 
        If there is no upcomming charecter, then a space ' ' is returned*/
        if (_raw_str.size() > _cursor)
        {
            std::string::size_type index;
            for (index = _cursor; index < _raw_str.size(); index++)
            {
                if (!isspace(_raw_str[index]))
                    break;
            }
            return _raw_str[index];
        }
        else
        {
            return ' ';
        }
    }
}
