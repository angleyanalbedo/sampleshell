// sampleshell.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "buildin.h"
#define PROCESSOR_EXIT 0

void myShell();
int shellExcute(std::vector<std::string>);
int shellLaunch(char* args);
std::string readLine();
std::vector<std::string> splitLine(std::string);
std::vector<std::string> splitString(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::string::size_type start = 0;
    std::string::size_type end = input.find(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(input.substr(start, end - start));
        start = end + 1;
        end = input.find(delimiter, start);
    }

    tokens.push_back(input.substr(start));

    return tokens;
}
std::string vectorToString(const std::vector<std::string>& vec, const std::string& separator)
{
    std::string result;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        result += vec[i];
        if (i != vec.size() - 1)
        {
            result += separator;
        }
    }
    return result;
}

// TODO: 在此处引用程序需要的其他标头。
