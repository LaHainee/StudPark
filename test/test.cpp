#include "gtest/gtest.h"
#include <iostream>
#include "Post.h"

TEST(test1, add_post) {
    Post::AddPost("head", "body", 1, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

