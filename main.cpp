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
    void RegisterFlag(const std::string& flag) {
        if(!flag.empty()) {
            map_Flags[flag] = false;
        }
    }

    bool GetFlag(const std::string& flag) const {
        if(!flag.empty()) {
            auto flagIt = map_Flags.find(flag);
            if(flagIt != std::end(map_Flags)) {
                return flagIt->second;
            }
        }
        return false;
    }

    void Parse(int argc, char* argv[]) {
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

private:
    std::map<std::string, bool> map_Flags;
};


int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "pt_BR");

    ArgumentParser argParser;
    argParser.RegisterFlag("rename");
    argParser.RegisterFlag("convert");
    argParser.RegisterFlag("resize");
    argParser.RegisterFlag("scale");

    argParser.Parse(argc, argv);

    std::cout << std::boolalpha << "Rename: " << argParser.GetFlag("rename") << std::endl;
    std::cout << std::boolalpha << "Convert: " << argParser.GetFlag("convert") << std::endl;
    std::cout << std::boolalpha << "Resize: " << argParser.GetFlag("resize") << std::endl;
    std::cout << std::boolalpha << "Scale: " << argParser.GetFlag("scale") << std::endl;
    return 0;
}
