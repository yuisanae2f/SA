#include <stdio.h>
#include <filesystem>
#include <SA.h>
#include <string>
#include <vector>
#include <iostream>
#include <_SA_NameGen.hpp>
#include <algorithm>
#include <_SA_StrGetPostNum.h>


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
        puts("Choose an operation you're willing to do.");
        puts("By entering one character, you could choose it.");
        puts("- File separating [s]");
        puts("- File adding [a]");

        scanf("%c", g_buff); getchar();

        #include <_SA_File.hpp>
        namespace fs = std::filesystem;
        switch(g_buff[0]) {
            case 's': {
                puts("Choose a file you're willing to read.");
                std::getline(std::cin, g_TAR_IN);

                _SA_File tar_in(g_TAR_IN.c_str(), "rb");
                std::filesystem::path filename_raw(g_TAR_IN);

                if(!tar_in.f) 
                goto __target_not_found;

                puts("Choose a directory you're willing to copy the separates.");
                std::getline(std::cin, g_TAR_OUT);

                if(!fs::exists(g_TAR_OUT))
                if(!fs::create_directory(g_TAR_OUT))
                goto __oper_failed;

                std::string* ___SA_NameGen_Str = reinterpret_cast<std::string*>(_SA_NameGen_Str);
                for(
                    long 
                    tarinfcount = tar_in.FileCount(), 
                    i = 0; i < tarinfcount; i++
                ) {
                    _SA_NameGen(filename_raw.filename().string().c_str(), i);
                    std::string _v = g_TAR_OUT + "/" + ___SA_NameGen_Str[0];
                    _SA_File out(_v.c_str(), "wb");
                    SA_sep(tar_in.f, out.f, i, _SA_File_SIZE);
                }

                puts("Your file has been separated.");
            } goto __done_succesfully;
            case 'a': {
                puts("Choose a directory to iterate so it could generate the original.");
                std::getline(std::cin, g_TAR_IN);
                puts("Choose a output file's name.");
                std::getline(std::cin, g_TAR_OUT);
                if(!fs::exists(g_TAR_IN))
                goto __target_not_found;

                std::vector<fs::path> files;

                for (const auto& entry : fs::directory_iterator(g_TAR_IN)) {
                    if (entry.is_regular_file()) {
                        files.push_back(entry.path());
                    }
                }

                std::sort(files.begin(), files.end(), [](const fs::path& a, const fs::path& b) {
                    return _SA_StrGetPostNum(a.string().c_str()) < _SA_StrGetPostNum(b.string().c_str());
                });

                _SA_File out(g_TAR_OUT.c_str(), "wb");

                for (const auto& file : files) {
                    _SA_File f(file.string().c_str(), "rb");
                    SA_add(out.f, &f.f, 1);
                    puts(file.filename().string().c_str());
                }

            } goto __done_succesfully;
            default: goto __non_imp;
        }
    } else {
        /// @todo Implement this shit
        /// It is to iterate the @par argv and do as the above.
        goto __non_imp;
    }

    __done_succesfully:
    return 0;

    __non_imp:
    puts("Not implemented yet, sorry.");
    return 1;

    __oper_failed:
    puts("Operation went failed.");
    return 2;

    __target_not_found:
    puts("Target file/directory is not found.");
    return 3;
}