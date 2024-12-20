#include <_SA_NameGen.hpp>
#include <string>

static std::string __s;
extern "C" void* _SA_NameGen_Str = (void*)&__s;

/// @return pointer of std::string 
ae2f_extern void _SA_NameGen(
    const char* filename,
    long index
) {
    __s = "out..";
    __s += filename;
    __s += "..";
    __s += std::to_string(index);
    __s += "\0";
}