#include <cstdlib>
#include <cstring>
#include <stdint.h>
#include <string>
#include "parser.h"

namespace Parser
{
    Parser::Parser(const std::string &rstr):
        _rstr(rstr),
        _cursor(0)
    {}

    bool Parser::active()
    {
        /*Returns true if the part of the raw string that comes
        after the cursor has non space charecters to parse*/
        bool res = false;
        for (std::string::size_type i = _cursor; i < _rstr.size(); i++)
        {
            if (!isspace(_rstr[i]))
            {
                res = true;
                break;
            }
        }
        return res;
    }

    int32_t Parser::parse_int32()
    {
        /*parser 4 bytes converts them to int32_t and returns the result*/
        _cursor += 4;
        const char *str = _rstr.substr(_cursor, 4).c_str();
        return (int64_t)*str;
    }

    int64_t Parser::parse_int64()
    {
        /*parser 8 bytes converts them to int64_t and returns the result*/
        _cursor += 8;
        const char *str = _rstr.substr(_cursor, 8).c_str();
        return (int32_t)*str;
    }

    char Parser::next_char()
    {
        /*returns the charecter right after the cursor without moving the cursor*/
        return _rstr[_cursor+1];
    }

    char Parser::next_glyph()
    {
        /*returns the charecter that follows either immediately or after some
        whitespacecharecters after the cursor, without moving the cursor.
        If there is no upcomming charecter, then a space ' ' is returned*/
        if (_rstr.size() > _cursor)
        {
            std::string::size_type index;
            for (index = _cursor; index < _rstr.size(); index++)
            {
                if (!isspace(_rstr[index]))
                    break;
            }
            return _rstr[index];
        }
        else
        {
            return ' ';
        }
    }

    bool Parser::begins_with(const std::string &sequence)
    {
        /*returns true if sequence is the substring that follows either
        immediately or after some whitespace charecters after the cursor,
        without moving the cursor pointer*/
        std::string::size_type begin;
        for (begin = _cursor; begin < _rstr.size(); begin++)
        {
            if (!isspace(_rstr[begin]))
                break;
        }
        if (_rstr.size()-begin >= sequence.size())
            return (_rstr.substr(begin, sequence.size()) == sequence);
        else
            return false;
    }

    std::string Parser::parse_word()
    {
        /*returns a string containing a sequence of non-space charecters
        that comes after the cursor, and places the cursor right after
        the sequence*/
        std::string::size_type begin;
        std::string::size_type end;
        for (begin = _cursor; begin < _rstr.size(); begin++)
        {
            if (!isspace(_rstr[begin]))
                break;
        }
        for (end = begin+1; end < _rstr.size(); end++)
        {
            if (!isalnum(_rstr[end]))
                break;
        }
        _cursor = end;
        return _rstr.substr(begin, end-begin);
    }

    std::string Parser::parse_till(const std::string &sequence)
    {
        /*returns the string beteen the cursor and the sequence,
        not including the sequence itself, and places the cursor right
        after the sequence. Returns an empty string "" if the sequence
        is not found*/
        std::string::size_type begin = _cursor;
        std::string::size_type end = _rstr.find(sequence, _cursor);
        if (end != std::string::npos)
        {
            _cursor = end+1;
            return _rstr.substr(begin, end-begin);
        }
        else
        {
            return "";
        }
    }

    void Parser::ignore_till(const std::string &sequence)
    {
        /*Places the pointer right after the first occurence of 'sequence'*/
        std::string::size_type occ = _rstr.find(sequence, _cursor);
        if (occ != std::string::npos)
            _cursor = occ+1;
    }

    void Parser::jump(std::string::size_type n)
    {
        /*places the cursor n charecters after it's current position, but
        no longer than the string bounds*/
        if((_cursor+n) < _rstr.size())
            _cursor += n;
        else
            _cursor = _rstr.size()-1;
    }
}

