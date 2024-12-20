#include <stdio.h>
#include <ae2f/Cast.h>
#include <ae2f/Call.h>
#include <stdint.h>
#include <stdlib.h>

static char _Buff[
    #include "../include_bin/_SA_FILE_SIZE.h"
];

ae2f_SHAREDEXPORT 
void SA_sep(
    FILE* in, 
    FILE* out, 
    long oidx, 
    long seplen
) {
    if (!(in && out)) return;

    fseek(in, 0, SEEK_END);
    const long in_len = ftell(in);

    long 
    istart = oidx * seplen,
    iend = istart + seplen;

    if (istart >= in_len) return;
    if (iend > in_len) iend = in_len;

    fseek(in, istart, SEEK_SET);
    int ch; // '___'을 'ch'로 변경하여 의미를 명확히 함
    const size_t got = fread(_Buff, 1, sizeof(_Buff), in);
    fwrite(_Buff, 1, got, out);

    return;
}

ae2f_extern ae2f_SHAREDCALL
void SA_add(
    FILE* out, 
    FILE** in,
    size_t olen
) {
    if(!(in && out)) return;
    fseek(out, 0, SEEK_END);
    int ch;
    size_t got;

    for(size_t i = 0; i < olen; i++) {
        if(!in[i]) continue;
        fseek(in[i], 0, SEEK_SET);
        got = fread(_Buff, 1, sizeof(_Buff), in[i]);
        fwrite(_Buff, 1, got, out);
    }
}