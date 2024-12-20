#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <regex>

extern "C" long _SA_StrGetPostNum(const char* __name) {
    std::string filename = __name;
    std::regex regex("\\d+$");
    std::smatch match;
    if (std::regex_search(filename, match, regex)) {
        return std::stol(match.str(0));
    }
    return -1;
}