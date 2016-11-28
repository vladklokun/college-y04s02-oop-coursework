#include <iostream>

#ifndef BLUMBLUMSHUB_HPP
#define BLUMBLUMSHUB_HPP
#include "BlumBlumShub.hpp"
#endif

std::vector<int> genKey(size_t len);
std::vector<int> stringToIntArr(std::string str);
std::vector<int> XOR(std::vector<int> msg, std::vector<int> key);
std::vector<int> strToHex(std::string s);
bool isValidHex(std::string s);

