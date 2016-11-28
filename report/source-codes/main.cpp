#include <iostream>
#include <iomanip> /* std::setfill */

#ifndef BLUMBLUMSHUB_HPP
#define BLUMBLUMSHUB_HPP
#include "BlumBlumShub.hpp"
#endif

#include "msgmanip.hpp"

int main(void)
{
	char mode = '0';

	std::cout << "Welcome! Do you want to (e)ncrypt or (d)ecrypt your message?\n";
	std::cin.get(mode);

	switch (mode) {
		case 'e' :
		{
			std::string msg = "";
			std::vector<int> msgHex;
			std::vector<int> key;
			std::vector<int> encMsg;

			std::cout << "Please enter your message:\n";
			if ( std::getline(std::cin >> std::ws, msg) ) {
				std::cout << "Your message as ASCII:\n" << msg << '\n';
				msgHex.resize( msg.size() );
				msgHex = stringToIntArr(msg);
				std::cout << "Your message in HEX:\n";
				for (auto i: msgHex)
					std::cout << std::hex << std::setfill('0') << std::setw(2) << i;
				std::cout << '\n';
	
				key.resize( msg.size() );
				key = genKey( key.size() );
	
				std::cout << "Generated key:\n";
				for (auto i: key)
					std::cout << std::hex << std::setfill('0') << std::setw(2) << i;
				std::cout << '\n';
	
				encMsg.resize( msg.size() );
				encMsg = XOR(msgHex, key);
	
				std::cout << "Encrypted message:\n";
				for (auto i: encMsg)
					std::cout << std::hex << std::setfill('0') << std::setw(2) << i;
				std::cout << '\n';

				break;
			} else {
				std::cerr << "Getline failed. Exiting.\n";
				
				return 1;
			}

		}
		case 'd':
		{
			std::string encMsg = "";
			std::string key = "";

			std::cout << "Please enter the encrypted message:\n";
			if ( std::getline(std::cin >> std::ws, encMsg) && isValidHex(encMsg) ) {
				std::cout << "Your message:\n" << encMsg << '\n';
				std::cout << "Please enter the key:\n";

				if ( std::getline(std::cin, key) && isValidHex(key) ) {
					std::vector<int> encMsgHex;
					std::vector<int> keyHex;
					std::vector<int> decMsg; /* decrypted Message */

					std::cout << "Your key:\n" << key << '\n';
					/* TODO: add hexstring conversion. */
					keyHex.resize( key.size() / 2);
					keyHex = strToHex(key);
					
					encMsgHex.resize( encMsg.size() / 2 );
					encMsgHex = strToHex(encMsg);

					decMsg.resize( encMsg.size() / 2);
					decMsg = XOR(encMsgHex, keyHex);
					for (auto i: decMsg)
						std::cout << static_cast<char>(i);
					std::cout << '\n';

				} else {
					std::cerr << "Unable to read key. It is probably not a valid HEX string.\nPlease re-check and try again.\nAborting.\n";
					return 1;
				}
			} else {
				std::cerr << "Unable to read encrypted message. It is probably not a valid HEX string.\nPlease re-check and try again.\nAborting.\n";
			}
			break;
		}

		default:
			std::cerr << "Unsupported mode. Please retry after exit.\n";
			return 1;
	}

	return 0;
}

