#ifndef MSGMANIP_H
#define MSGMANIP_H
#include "msgmanip.hpp"
#endif

#ifndef BLUMBLUMSHUB_HPP
#define BLUMBLUMSHUB_HPP
#include "BlumBlumShub.hpp"
#endif

std::vector<int> genKey(size_t len)
{
	BlumBlumShub rng;
	std::vector<int> key(len);
	
	for (size_t i = 0; i < key.size(); ++i) {
		key[i] = rng.getRandInt();
	}

	return key;
}

std::vector<int> stringToIntArr(std::string str)
{
	std::vector<int> stringAsHexArr(str.size());

	for (size_t i = 0; i < str.size(); ++i ) {
		stringAsHexArr[i] = static_cast<int>(str[i]);
	}
	std::cout << "String converted to IntArr successfully.\n";

	return stringAsHexArr;	
}

std::vector<int> strToHex(std::string s)
{
	std::vector<int> hex( s.size() / 2 );
	char * sp = const_cast<char *>( s.c_str() );
	for (size_t i = 0; i < s.size(); ++i) {
		sscanf(sp, "%02x", &hex[i]);
		sp += 2;
	}

	return hex;
}

std::vector<int> XOR(std::vector<int> msg, std::vector<int> key)
{
	std::vector<int> encMsg(msg.size());

	for (size_t i = 0; i < encMsg.size(); ++i) {
		encMsg[i] = msg[i] ^ key[i];
	}

	return encMsg;
}

bool isValidHex(std::string s)
{
	for (auto i: s)
		if ( (i < '0' || i > '9') && (i < 'a' || i > 'f') ) //check char validity
			return false;
	
	return (s.size() % 2 == 0); //function reaches this here only if char validity check passed
}
