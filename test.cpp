#include <stdlib.h>
#include <queue>
#include "gtest/gtest.h"
#include "modules/functions/functions.h"
#include "modules/Data/Data.h"

std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type> > pqData;

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

            while(pqData.empty() != true){
                pqData.pop();
            }
        }

        std::stringstream buffer{};
        std::streambuf *sbuf;
    };

    /* Test for checking right commands.
    *
    */
    TEST_F(TestCppBuffer, CheckCommandTest1){
        Data test_data;
        EXPECT_EQ(CheckCommand("1:1", test_data), 0);
        EXPECT_EQ(CheckCommand("123:123", test_data), 0);
        EXPECT_EQ(CheckCommand("0:0", test_data), 0);
    }

    /* Test for checking wrong commands.
    *
    */
    TEST_F(TestCppBuffer, CheckCommandTest2){
        Data test_data;
        EXPECT_EQ(CheckCommand("abc", test_data), -1);
        EXPECT_EQ(CheckCommand("abc:abc", test_data), -1);
        EXPECT_EQ(CheckCommand("abc:1", test_data), -1);
        EXPECT_EQ(CheckCommand("1:abc", test_data), -1);
        EXPECT_EQ(CheckCommand("123:123:123", test_data), -1);
        EXPECT_EQ(CheckCommand(":", test_data), -1);
        EXPECT_EQ(CheckCommand("", test_data), -1);
        EXPECT_EQ(CheckCommand("123", test_data), -1);
    }

    /* Test for checking empty buffer.
    *
    */
    TEST_F(TestCppBuffer, PrintTest1){
        std::string expected{"Error: buffer is empty\n"};
        Print();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking base functionality.
    *
    */
    TEST_F(TestCppBuffer, PrintTest2){
        Data test_data(123,1,0);
        pqData.push(test_data);
        test_data.setval(456,2,1);
        pqData.push(test_data);
        test_data.setval(321,3,2);
        pqData.push(test_data);
        test_data.setval(654,0,3);
        pqData.push(test_data);
        std::string expected{"654\n123\n456\n321\n"};
        Print();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking empty buffer.
    *
    */
    TEST_F(TestCppBuffer, GetTest1){
        std::string expected{"Error: buffer is empty\n"};
        Get();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking base functionality.
    *
    */
    TEST_F(TestCppBuffer, GetTest2){
        Data test_data(123,1,0);
        pqData.push(test_data);
        std::string expected{"123\n"};
        Get();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking priority.
    *
    */
    TEST_F(TestCppBuffer, GetTest3){
        Data test_data(123,1,0);
        pqData.push(test_data);
        test_data.setval(321,0,1);
        pqData.push(test_data);
        std::string expected{"321\n"};
        Get();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking same priority case.
    *
    */
    TEST_F(TestCppBuffer, GetTest4){
        Data test_data(123,1,0);
        pqData.push(test_data);
        test_data.setval(321,1,1);
        pqData.push(test_data);
        std::string expected{"123\n"};
        Get();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking empty buffer.
    *
    */
    TEST_F(TestCppBuffer, RemoveTest1){
        std::string expected{"Error: buffer is empty\n"};
        Remove();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking base functionality.
    *
    */
    TEST_F(TestCppBuffer, RemoveTest2){
        Data test_data(123,1,0);
        pqData.push(test_data);
        std::string expected{"123 will be removed\n"};
        Remove();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for a more complete program flow.
    *
    */
    TEST_F(TestCppBuffer, ProgramTest1){
        int i = 0;
        Data test_data;

        CheckCommand("2:2", test_data);
        pqData.push(test_data);
        CheckCommand("3:2", test_data);
        pqData.push(test_data);
        CheckCommand("4:2", test_data);
        pqData.push(test_data);
        CheckCommand("5:2", test_data);
        pqData.push(test_data);
        CheckCommand("1:0", test_data);
        pqData.push(test_data);
        CheckCommand("6:3", test_data);
        pqData.push(test_data);
        Get();
        std::string expected{"1\n"};
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);

        for(i=0; i<10; i++){
            buffer.str(std::string());
            Print();
            expected = "1\n2\n3\n4\n5\n6\n";
            actual = buffer.str();
            EXPECT_EQ(expected, actual);
        }

        buffer.str(std::string());
        Remove();
        expected = "1 will be removed\n";
        actual = buffer.str();
        EXPECT_EQ(expected, actual);

        buffer.str(std::string());
        Print();
        expected = "2\n3\n4\n5\n6\n";
        actual = buffer.str();
        EXPECT_EQ(expected, actual);
    }
} /* end namespace */
