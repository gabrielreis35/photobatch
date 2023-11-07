//
// Created by gabrielreis on 07/11/23.
//
#pragma once

#include <iostream>
#include <map>
#include <algorithm>

/*
 * Example:
 *  ArgumentParser argParser; - call function
 *  argParser.RegisterFlag("rename"); - register flag
 *  argParser.Parse(argc, argv); - parse flag
 *  std::cout << std::boolalpha << "Rename: " << argParser.GetFlag("rename") << std::endl; - call flag registered
 */

class ArgumentParser {
public:
    void RegisterFlag(const std::string& flag);
    bool GetFlag(const std::string& flag) const;
    void Parse(int argc, char* argv[]);

    void RegisterOption(const std::string& option);
    const std::string& GetOption(const std::string& option) const;

private:
    std::map<std::string, bool> map_Flags;
    std::map<std::string, std::string> map_Options;
};
