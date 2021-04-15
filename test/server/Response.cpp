#include "gtest/gtest.h"

#include "../../src/server/Response.cpp"

TEST(test1, ErrorChecking) {

    int result;

    EXPECT_EQ(result, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
