//
// Created by gabrielreis on 07/11/23.
//

#include "ArgumentParser.h"
#include "Utils.h"

void ArgumentParser::RegisterFlag(const std::string& flag) {
    if(!flag.empty()) {
        map_Flags[flag] = false;
    }
}

bool ArgumentParser::GetFlag(const std::string& flag) const {
    if(!flag.empty()) {
        auto flagIt = map_Flags.find(flag);
        if(flagIt != std::end(map_Flags)) {
            return flagIt->second;
        }
    }
    return false;
}

void ArgumentParser::Parse(int argc, char* argv[]) {
    if(argc > 1) {
        for(int i = 1; i < argc; ++i) {
            std::string arg = Utils::ToLower(argv[i]);

            // verify arg contain -...'
            if(arg.length() >= 3) {
                if(arg[0] == '-') {
                    arg = arg.substr(1);
                    if(arg.find_first_of('=')) {
                        const size_t equalSignPos = arg.find('=');
                        if(equalSignPos != std::string::npos) {
                            std::string optionName = arg.substr(0, equalSignPos);
                            std::string optionValue = arg.substr(equalSignPos + 1);

                            auto optionIt = map_Options.find(optionName);
                            if(optionIt != std::end(map_Options)) {
                                optionIt->second = optionValue;
                            }
                        }
                    }
                    else {
                        auto flagIt = map_Flags.find(arg);
                        if(flagIt != std::end(map_Flags)) {
                            flagIt->second = true;
                        }
                    }
                }
            }
        }
    }
}

void ArgumentParser::RegisterOption(const std::string& option) {
    if(!option.empty()) {
        map_Options[option] = "";
    }
}

const std::string& ArgumentParser::GetOption(const std::string& option) const {
    if(!option.empty()) {
        auto optionIt = map_Options.find(option);
        if (optionIt != std::end(map_Options)) {
            return optionIt->second;
        }
    }

    static std::string emptyOption = "";
    return emptyOption;
}