#include <stdio.h>
#include <ae2f/Cast.h>
#include <ae2f/Call.h>
#include <stdint.h>
#include <stdlib.h>

ae2f_SHAREDEXPORT 
void SA_sep(
    FILE* in, 
    FILE* out, 
    long oidx, 
    long seplen
) {
    if(!(in && out)) return;
    fseek(in, 0, SEEK_END);
    fseek(out, 0, SEEK_END);
    const long in_len = ftell(in);
    if(in_len == EOF) return;

    long 
    istart = oidx * seplen,
    iend = istart + seplen;

    int ___ = 3;

    if(istart >= in_len) return;
    if(iend > in_len) iend = in_len;

    fseek(in, istart, SEEK_SET);
    for(int i = istart; i < iend && ___ != EOF; i++) {
        ___ = fgetc(in);
        if(___ != EOF)
        fputc(___, out);
    }

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

    for(size_t i = 0; i < olen; i++) {
        if(!in[i]) continue;
        fseek(in[i], 0, SEEK_SET);
        while ((ch = fgetc(in[i])) != EOF) {
            fputc(ch, out);
        }
    }
}