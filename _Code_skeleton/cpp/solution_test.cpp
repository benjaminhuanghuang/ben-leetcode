/*
{TITLE}

Level: {LEVEL}

{URL}
*/
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "solution.cpp"


TEST(testsuit, tests)
{
    Solution s;
    vector<int> nums{2, 7, 11, 15};
    vector<int> res = s.twoSum(nums, 9);
    EXPECT_THAT(array, ElementsAre(0,1));
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}