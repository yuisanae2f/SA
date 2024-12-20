#include <stdio.h>
#include <filesystem>
#include <SA.h>
#include <string.h>
#include <vector>
#include <iostream>

#pragma region _
int _main(int argc, const std::vector<std::string>& argv);
int main(int argc, const char* argv[]) {
    std::vector<std::string> _argv(argc);
    if(argc >= 1)
    for(int i = 0; i < argc; i++) 
    _argv[i] = argv[i];
    else return 1;
    return _main(argc, _argv);
}
#pragma endregion

char g_buff[2] = {0, };
std::string g_TAR_IN, g_TAR_OUT;

int _main(int argc, const std::vector<std::string>& argv) {

    if(argc < 1) return 1;
    if(argc == 1) {
        puts("Choose an operation you're willing to do");
        puts("- File separating [s]");
        puts("- File merging [m]");    

        scanf("%c", g_buff);
        switch(g_buff[0]) {
            case 's': {
                puts("Choose a file you're willing to read.");
                std::cin >> g_TAR_IN;
                #include <SA_File.h>
                SA_File tar_in(g_TAR_IN.c_str(), "r");

                puts("Choose a directory you're willing to copy the separates.");
                std::cin >> g_TAR_OUT;

            } break;
            case 'm': {
                std::cin >> g_TAR_IN;
            } break;
            default: goto __non_imp;
        }
    } else {
        __non_imp:
        puts("Not implemented yet, sorry.\n");
        return 1;
    }

    return 0;
}