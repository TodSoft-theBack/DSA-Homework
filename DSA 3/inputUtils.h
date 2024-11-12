#include <bits/stdc++.h>
#include <string> 
#include <algorithm> 
#include <cctype> 
#include <functional>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);

std::string ltrim(const std::string &str)
{
    std::string s(str);

    s.erase(
        s.begin(),
        find_if
        (
            s.begin(), 
            s.end(), 
            [](int ch){ return !std::isspace(ch); }
        )
    );

    return s;
}

std::string rtrim(const std::string &str) 
{
    std::string s(str);

    s.erase
    (
        find_if
        (
            s.rbegin(), 
            s.rend(), 
            [](int ch){ return !std::isspace(ch); }
        ).base(),
        s.end()
    );

    return s;
}

