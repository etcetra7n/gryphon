#include <string>
#include "trim_ends.h"

namespace Parser
{
    std::string trim_ends(const std::string str)
    {
        std::string::size_type begin;
        std::string::size_type end;
        for (begin = 0; begin < str.size(); begin++)
        {
            if (!isspace(str[begin]))
                break;
        }
        for (end = str.size()-1; end >= begin; end--)
        {
            if (!isspace(str[end]))
                break;
        }
        return str.substr(begin, end-begin+1);
    }
}
