#include "lcd.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(LCDTest, BaseTest) {
    using std::string;

    // Given
    LCDKata::LCDDisplay converter;
    // When
    auto res = converter(12345);
    // Then
    for (string line : res) {
        std::cout << line << std::endl;
    }
    ASSERT_EQ(3, res.size());
    ASSERT_EQ("    _  _     _ ", res[0]);
    ASSERT_EQ("  | _| _||_||_ ", res[1]);
    ASSERT_EQ("  ||_  _|  | _|", res[2]);
}

TEST(LCDTest, BigNum) {
    using std::string;

    // Given
    LCDKata::LCDDisplay converter;
    // When
    auto res = converter("1234567890");
    // Then
    for (string line : res) {
        std::cout << line << std::endl;
    }
    ASSERT_EQ(3, res.size());
    ASSERT_EQ("    _  _     _  _  _  _  _  _ ", res[0]);
    ASSERT_EQ("  | _| _||_||_ |_   ||_||_|| |", res[1]);
    ASSERT_EQ("  ||_  _|  | _||_|  ||_| _||_|", res[2]);
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
