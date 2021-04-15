#include "gtest/gtest.h"
#include <iostream>

#include "../../src/server/Server.cpp"

TEST(test1, StartServer) {

    int result;

    EXPECT_EQ(result, 0);
}

TEST(test2, StopServer) {

     int result;

    EXPECT_EQ(result, NULL);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
