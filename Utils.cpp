//
// Created by gabrielreis on 07/11/23.
//
#include "Utils.h"

std::string Utils::ToLower(std::string str) {
    std::transform(std::begin(str), std::end(str), std::begin(str),
                   [](unsigned char c) {
                       return std::tolower(c);
                   });
    return str;
}