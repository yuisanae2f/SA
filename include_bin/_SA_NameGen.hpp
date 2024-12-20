#ifndef _SA_NameGen_hpp
#define _SA_NameGen_hpp

#include <ae2f/Cast.h>

/// @return pointer of std::string which is already set.
ae2f_extern void* _SA_NameGen_Str;

ae2f_extern void _SA_NameGen(
    const char* filename,
    long index
);

#endif