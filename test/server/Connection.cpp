#include "gtest/gtest.h"

#include "../../src/server/Connection.cpp"

TEST(test1, SendResponse) {

    int result;

    EXPECT_EQ(result, 0);
}

TEST(test2, ListenSocket) {

    int result;

    EXPECT_EQ(result, 0);
}

TEST(test3, WriteSocket) {

    int result;

    EXPECT_EQ(result, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
