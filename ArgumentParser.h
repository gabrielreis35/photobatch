//
// Created by gabrielreis on 07/11/23.
//
#pragma once

#include <iostream>
#include <map>
#include <algorithm>

std::string ToLower(std::string str) {
    std::transform(std::begin(str), std::end(str), std::begin(str),
                   [](unsigned char c) {
                       return std::tolower(c);
                   });
    return str;
}

class ArgumentParser {
public:
    void RegisterFlag(const std::string& flag);
    bool GetFlag(const std::string& flag) const;
    void Parse(int argc, char* argv[]);

private:
    std::map<std::string, bool> map_Flags;
};
