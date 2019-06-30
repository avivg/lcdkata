#include "lcd.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(LCDTest, BaseTest) {
    // Given
    LCDKata::LCDDisplay converter;
    // When
    auto res = converter(12345);
    // Then
    for (std::string line : res) {
        std::cout << line << std::endl;
    }
    ASSERT_EQ("    _  _     _ ", res[0]);
    ASSERT_EQ("  | _| _||_||_ ", res[1]);
    ASSERT_EQ("  ||_  _|  | _|", res[2]);
}

TEST(LCDTest, BigNum) {
    // Given
    LCDKata::LCDDisplay converter;
    // When
    auto res = converter("1234567890");
    // Then
    for (std::string line : res) {
        std::cout << line << std::endl;
    }
    ASSERT_EQ("    _  _     _  _  _  _  _  _ ", res[0]);
    ASSERT_EQ("  | _| _||_||_ |_   ||_||_|| |", res[1]);
    ASSERT_EQ("  ||_  _|  | _||_|  ||_| _||_|", res[2]);
}

TEST(LCDTest, Zero) {
    // Given
    LCDKata::LCDDisplay converter;
    // When
    auto res = converter(0);
    // Then
    for (std::string line : res) {
        std::cout << line << std::endl;
    }
    ASSERT_EQ(" _ ", res[0]);
    ASSERT_EQ("| |", res[1]);
    ASSERT_EQ("|_|", res[2]);
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
