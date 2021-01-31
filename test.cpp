#include <stdlib.h>
#include <iostream>
#include <queue>
#include "gtest/gtest.h"
#include "modules/functions/functions.h"
#include "modules/Data/Data.h"

namespace{

    class TestCppBuffer : public ::testing::Test {
    protected:
        TestCppBuffer() : sbuf{nullptr} {
        }
        ~TestCppBuffer() override = default;
        /* Called before each unit test */
        void SetUp() override {
            sbuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());
        }

        /* Called after each unit test */
        void TearDown() override {
            std::cout.rdbuf(sbuf);
            sbuf = nullptr;
        }

        std::stringstream buffer{};
        std::streambuf *sbuf;
    };

    /* Test for checking right commands.
    *
    */
    TEST_F(TestCppBuffer, CheckCommandTest1){
        std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData;
        EXPECT_EQ(CheckCommand("1:1", pqData), 0);
        EXPECT_EQ(CheckCommand("123:123", pqData), 0);
        EXPECT_EQ(CheckCommand("0:0", pqData), 0);
    }

    /* Test for checking wrong commands.
    *
    */
    TEST_F(TestCppBuffer, CheckCommandTest2){
        std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData;
        EXPECT_EQ(CheckCommand("abc", pqData), -1);
        EXPECT_EQ(CheckCommand("abc:abc", pqData), -1);
        EXPECT_EQ(CheckCommand("abc:1", pqData), -1);
        EXPECT_EQ(CheckCommand("1:abc", pqData), -1);
        EXPECT_EQ(CheckCommand("123:123:123", pqData), -1);
        EXPECT_EQ(CheckCommand(":", pqData), -1);
        EXPECT_EQ(CheckCommand("", pqData), -1);
        EXPECT_EQ(CheckCommand("123", pqData), -1);
    }

    /* Test for checking empty buffer.
    *
    */
    TEST_F(TestCppBuffer, PrintTest1){
        std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData;
        std::string expected{"Error: buffer is empty\n"};
        Print(pqData);
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking base functionality.
    *
    */
    TEST_F(TestCppBuffer, PrintTest2){
        std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData;
        CheckCommand("123:1", pqData);
        CheckCommand("456:2", pqData);
        CheckCommand("321:3", pqData);
        CheckCommand("654:0", pqData);
        std::string expected{"654\n123\n456\n321\n"};
        Print(pqData);
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking empty buffer.
    *
    */
    TEST_F(TestCppBuffer, GetTest1){
        std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData;
        std::string expected{"Error: buffer is empty\n"};
        Get(pqData);
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking base functionality.
    *
    */
    TEST_F(TestCppBuffer, GetTest2){
        std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData;
        CheckCommand("123:1", pqData);
        std::string expected{"123\n"};
        Get(pqData);
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking priority.
    *
    */
    TEST_F(TestCppBuffer, GetTest3){
        std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData;
        CheckCommand("123:1", pqData);
        CheckCommand("321:0", pqData);
        std::string expected{"321\n"};
        Get(pqData);
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking same priority case.
    *
    */
    TEST_F(TestCppBuffer, GetTest4){
        std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData;
        CheckCommand("123:1", pqData);
        CheckCommand("321:1", pqData);
        std::string expected{"123\n"};
        Get(pqData);
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking empty buffer.
    *
    */
    TEST_F(TestCppBuffer, RemoveTest1){
        std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData;
        std::string expected{"Error: buffer is empty\n"};
        Remove(pqData);
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking base functionality.
    *
    */
    TEST_F(TestCppBuffer, RemoveTest2){
        std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData;
        CheckCommand("123:1", pqData);
        std::string expected{"123 will be removed\n"};
        Remove(pqData);
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for a more complete program flow.
    *
    */
    TEST_F(TestCppBuffer, ProgramTest1){
        std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData;
        int i = 0;

        CheckCommand("2:2", pqData);
        CheckCommand("3:2", pqData);
        CheckCommand("4:2", pqData);
        CheckCommand("5:2", pqData);
        CheckCommand("1:0", pqData);
        CheckCommand("6:3", pqData);
        Get(pqData);
        std::string expected{"1\n"};
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);

        for(i=0; i<10; i++){
            buffer.str(std::string());
            Print(pqData);
            expected = "1\n2\n3\n4\n5\n6\n";
            actual = buffer.str();
            EXPECT_EQ(expected, actual);
        }

        buffer.str(std::string());
        Remove(pqData);
        expected = "1 will be removed\n";
        actual = buffer.str();
        EXPECT_EQ(expected, actual);

        buffer.str(std::string());
        Print(pqData);
        expected = "2\n3\n4\n5\n6\n";
        actual = buffer.str();
        EXPECT_EQ(expected, actual);
    }
} /* end namespace */
