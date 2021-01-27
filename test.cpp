#include <stdlib.h>
#include <queue>
#include "gtest/gtest.h"
#include "modules/functions/functions.h"
#include "modules/Data/Data.h"

std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type> > pqData;
Data test_data;

TEST(CheckCommandTest, Positive){
    EXPECT_EQ(CheckCommand("1:1", test_data), 0);
    EXPECT_EQ(CheckCommand("123:123", test_data), 0);
    EXPECT_EQ(CheckCommand("0:0", test_data), 0);
}

TEST(CheckCommandTest, Negative){
    EXPECT_EQ(CheckCommand("abc", test_data), -1);
    EXPECT_EQ(CheckCommand("abc:abc", test_data), -1);
    EXPECT_EQ(CheckCommand("abc:1", test_data), -1);
    EXPECT_EQ(CheckCommand("1:abc", test_data), -1);
    EXPECT_EQ(CheckCommand("123:123:123", test_data), -1);
    EXPECT_EQ(CheckCommand(":", test_data), -1);
    EXPECT_EQ(CheckCommand("", test_data), -1);
    EXPECT_EQ(CheckCommand("123", test_data), -1);
}
