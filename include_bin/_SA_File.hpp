#ifndef _SA_File_h
#define _SA_File_h

#include <stdio.h>

constexpr long _SA_File_SIZE = 
#include "_SA_FILE_SIZE.h"
;;

struct _SA_File {
    FILE* f;
    
    constexpr _SA_File() : f(0) {}

    inline _SA_File(
        const char *__restrict__ __filename, 
        const char *__restrict__ __modes
    ) : f(0) {
        if(__filename) {
            f = fopen(__filename, __modes);
        }
    }
    
    /// @warning Could return EOF
    inline long FileLen() const {
        fseek(f, 0, SEEK_END);
        long d = ftell(f);
        fseek(f, 0, SEEK_SET);
        return d;
    }

    inline long FileCount() const {
        long d = FileLen();
        if(d == EOF) return 0;
        return d / _SA_File_SIZE + 1;
    }

    inline ~_SA_File() {
        if(f) fclose(f);
    }
};

#endif
