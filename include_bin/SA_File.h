#ifndef SA_File_h
#define SA_File_h

#include <stdio.h>
#include <string>

struct SA_File {
    FILE* f;
    constexpr SA_File() : f(0) {}

    inline SA_File(
        const char *__restrict__ __filename, 
        const char *__restrict__ __modes
    ) : f(0) {
        if(__filename) {
            f = fopen(__filename, __modes);
        }
    }

    inline ~SA_File() {
        if(f) fclose(f);
    }
};

#endif