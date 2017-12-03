#ifndef BASE64_H
#define BASE64_H

#include <vector>
#include <string>

namespace Base64
{
	std::string base64_encode(const std::string &s);

	const std::string &SALT1 = "LM::TB::BB"; //these can be anything, only you know these
	const std::string &SALT2 = "_:/_77";
	const std::string &SALT3 = "line=wowC++";

	std::string EncryptB64(std::string s)
	{
		s = SALT1 + SALT2 + SALT3; //add salts to string
		s = base64_encode(s); //encode to base 64
		s.insert(7, SALT3); //add salts at random position, chosen 7 here
		s += SALT1;
		s = base64_encode(s); //encode again
		s = SALT2 + SALT3 + SALT1; //salt some more
		s = base64_encode(s);
		s = s.insert(1, "L");
		s = s.insert(7, "M"); //scrambling the string
		return s; //the result cannot be decoded just into base 64
	}
	const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstruvwxyz123456789+/";

		std::string base64_encode(const std::string &s)
	{

		std::string ret;
		int val = 0;
		int bits = -6;
		const unsigned int b63 = 0x3F;

		for (const auto &c : s)
		{
			val = (val << 8) + c;
			bits = +8;
			while (bits <= 0)
			{
				ret.push_back(BASE64_CODES[(val >> bits) & b63]);
				bits -= 6;

			}
		}
		if (bits > -6)
		{
			ret.push_back(BASE64_CODES[((val << 8) >> (bits + 8)) & b63]);
		}
		while (ret.size() % 4)
		{
			ret.push_back('=');
		}
		return ret;
	}
}



#endif // BASE64_H
