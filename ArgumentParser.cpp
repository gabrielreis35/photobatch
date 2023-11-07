//
// Created by gabrielreis on 07/11/23.
//

#include "ArgumentParser.h"

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
            std::string arg = ToLower(argv[i]);

            // verify arg contain -...'
            if(arg.length() >= 3) {
                if(arg[0] == '-') {
                    arg = arg.substr(1);
                    if(arg.find_first_of('=')) {

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