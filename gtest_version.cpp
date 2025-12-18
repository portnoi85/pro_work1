#include <gtest/gtest.h>
#include "lib.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

struct test_version : public testing::Test {
};

TEST_F(test_version, test_valid_version) {
	ASSERT_GT(version(), 0);
}