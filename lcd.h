#ifndef LCDKATA_LCD_H
#define LCDKATA_LCD_H

#include <vector>
#include <string>

namespace LCDKata {
    class LCDDisplay {
    public:
        std::vector<std::string> operator()(unsigned int number) const;
        std::vector<std::string> operator()(std::string) const;
    };
}


#endif //  LCDKATA_LCD_H