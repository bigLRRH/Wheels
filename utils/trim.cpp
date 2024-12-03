#include <string>
#include <algorithm>
#include <cctype>

std::string trim_left(std::string s)
{
    s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), [](unsigned char c)
                                        { return std::isspace(c); }));
    return s;
}

std::string trim_right(std::string s)
{
    s.erase(std::find_if_not(s.rbegin(), s.rend(), [](unsigned char c)
                             { return std::isspace(c); })
                .base(),
            s.end());
    return s;
}

std::string trim(std::string s)
{
    return trim_left(trim_right(std::move(s)));
}