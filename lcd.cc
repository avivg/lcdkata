#include "lcd.h"

const std::vector<std::string> LCDKata::LCDDisplay::operator()(const unsigned int number) const {
    (void) number; // Appease -Werror=unused-parameter
    std::vector<std::string> res;
    for (int i = 0; i < 3; i++) {
        res.push_back("");
    }
    return res;
}