#include "lcd.h"
#include <sstream>

using dig_part_t = const char*;
using digit_t = std::vector<dig_part_t>;

static digit_t digit_repr(char digit);

std::vector<std::string> LCDKata::LCDDisplay::operator()(unsigned int number) const {
    std::ostringstream numstrstream;
    numstrstream << number;
    return (*this)(numstrstream.str());
}

std::vector<std::string> LCDKata::LCDDisplay::operator()(std::string numstr) const {
    std::vector<digit_t> digits_repr;
    std::vector<std::string> res;

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

static const char *dig_rep[][3] = {
    [0] = {
        " _ ",
        "| |",
        "|_|"
    },
    [1] = {
        "   ",
        "  |",
        "  |"
    },
    [2] = {
        " _ ",
        " _|",
        "|_ "
    },
    [3] = {
        " _ ",
        " _|",
        " _|"
    },
    [4] = {
        "   ",
        "|_|",
        "  |"
    },
    [5] = {
        " _ ",
        "|_ ",
        " _|"
    },
    [6] = {
        " _ ",
        "|_ ",
        "|_|"
    },
    [7] = {
        " _ ",
        "  |",
        "  |"
    },
    [8] = {
        " _ ",
        "|_|",
        "|_|"
    },
    [9] = {
        " _ ",
        "|_|",
        " _|"
    },
};

static digit_t digit_repr(char digit) {
    digit_t ret;
    for (int i = 0; i < 3; i++) {
        ret.push_back(dig_rep[static_cast<size_t>(digit - '0')][i]);
    }
    return ret;    
}