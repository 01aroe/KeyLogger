#ifndef BASE64_H
#define BASE64_H

#include <vector>
#include <string>

namespace Base64
{
    std::string base64_encode(const std::string &);

    const std::string &SALT1 = "LM::TB::BB"; //these can be anything, only you know these
    const std::string &SALT2 = "_:/_77";
    const std::string &SALT3 = "line=wowC++";

    std::string EncryptB64 (std::string s)
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

}



#endif // BASE64_H
