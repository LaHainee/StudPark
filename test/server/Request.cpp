#include "gtest/gtest.h"
#include <iostream>

#include "../../src/server/Request.cpp"

TEST(test1, ErrorChecking) {

    int result;

    EXPECT_EQ(result, 0);
}

TEST(test2, ParseCookie) {

    std::string  result;

    EXPECT_EQ(result, NULL);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
