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
    ASSERT_EQ(3, res.size());
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
