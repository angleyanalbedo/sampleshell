#pragma once
#include <iostream>
#include<string>
#include <vector>
#include <direct.h>



int ash_num_builtins();
int ash_cd(std::vector<std::string>);
int ash_help(std::vector<std::string>);
int ash_exit(std::vector<std::string>);