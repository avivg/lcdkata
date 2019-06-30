#include "lcd.h"

#include <sstream>

std::vector<std::string> LCDKata::LCDDisplay::operator()(unsigned int number) const {
    std::ostringstream numstrstream;
    numstrstream << number;
    return (*this)(numstrstream.str());
}

std::vector<std::string> LCDKata::LCDDisplay::operator()(std::string numstr) const {
    using std::vector;
    using std::string;
    vector<vector<string>> digits_repr;
    vector<string> res;

    for (char c: numstr) {
        digits_repr.push_back(digit_repr(c));
    }
    for (size_t i = 0; i < digits_repr[0].size(); i++) {
        std::ostringstream linestream;
        for (size_t j = 0; j < digits_repr.size(); j++) {
            linestream << digits_repr[j][i];
        }
        res.push_back(linestream.str());
    }
    return res;
}

std::vector<std::string> LCDKata::LCDDisplay::digit_repr(char digit) const {
    (void) digit;
    std::vector<std::string> ret;
    switch (digit) {
    case '0':
        ret.push_back(" _ ");
        ret.push_back("| |");
        ret.push_back("|_|");
        break;
    case '1':
        ret.push_back("   ");
        ret.push_back("  |");
        ret.push_back("  |");
        break;
    case '2':
        ret.push_back(" _ ");
        ret.push_back(" _|");
        ret.push_back("|_ ");
        break;
    case '3':
        ret.push_back(" _ ");
        ret.push_back(" _|");
        ret.push_back(" _|");
        break;
    case '4':
        ret.push_back("   ");
        ret.push_back("|_|");
        ret.push_back("  |");
        break;
    case '5':
        ret.push_back(" _ ");
        ret.push_back("|_ ");
        ret.push_back(" _|");
        break;
    case '6':
        ret.push_back(" _ ");
        ret.push_back("|_ ");
        ret.push_back("|_|");
        break;
    case '7':
        ret.push_back(" _ ");
        ret.push_back("  |");
        ret.push_back("  |");
        break;
    case '8':
        ret.push_back(" _ ");
        ret.push_back("|_|");
        ret.push_back("|_|");
        break;
    case '9':
        ret.push_back(" _ ");
        ret.push_back("|_|");
        ret.push_back(" _|");
        break;
    }
    return ret;    
}