#include "buildin.h"
#include<vector>
#include<string>
using namespace std;
const char* builtin_str[] = {
    "cd",
    "help",
    "exit"
};
int ash_cd(std::vector<string> args)
{
    if (args[1].empty()) {
        fprintf(stderr, "lsh: expected argument to \"cd\"\n");
    }
    else {
        if (_chdir(args[1].c_str()) != 0) {
            perror("lsh");
        }
    }
    return 1;
}

int ash_help( std::vector<string> args)
{
    int i;
    printf("albedo's aSH\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

    for (i = 0; i < ash_num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int ash_exit( std::vector<string> args)
{
    return 0;
}
int ash_num_builtins() {
    return sizeof(builtin_str) / sizeof(char*);
}