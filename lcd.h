#ifndef LCDKATA_LCD_H
#define LCDKATA_LCD_H

#include <vector>
#include <string>

namespace LCDKata {
    class LCDDisplay {
    public:
        const std::vector<std::string> operator()(const unsigned int number) const;
    };
}


#endif //  LCDKATA_LCD_H