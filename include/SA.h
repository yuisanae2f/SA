#ifndef SA_H
#define SA_H

#include <stdio.h>
#include <ae2f/Call.h>
#include <ae2f/Cast.h>

ae2f_extern ae2f_SHAREDCALL 
void SA_sep(
    FILE* in, 
    FILE* out, 
    long oidx, 
    long seplen
);

ae2f_extern ae2f_SHAREDCALL
void SA_add(
    FILE* out, 
    FILE** in, 
    long olen
);

#endif