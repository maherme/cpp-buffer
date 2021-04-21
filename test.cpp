#include <stdlib.h>
#include <iostream>
#include <queue>
#include "gtest/gtest.h"
#include "modules/functions/functions.h"
#include "modules/Data/Data.h"
#include "modules/PQueue/PQueue.h"

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
        PQueue pqData;
        EXPECT_EQ(pqData.check_command("1:1"), 0);
        EXPECT_EQ(pqData.check_command("123:123"), 0);
        EXPECT_EQ(pqData.check_command("0:0"), 0);
    }

    /* Test for checking wrong commands.
    *
    */
    TEST_F(TestCppBuffer, CheckCommandTest2){
        PQueue pqData;
        EXPECT_EQ(pqData.check_command("abc"), -1);
        EXPECT_EQ(pqData.check_command("abc:abc"), -1);
        EXPECT_EQ(pqData.check_command("abc:1"), -1);
        EXPECT_EQ(pqData.check_command("1:abc"), -1);
        EXPECT_EQ(pqData.check_command("123:123:123"), -1);
        EXPECT_EQ(pqData.check_command(":"), -1);
        EXPECT_EQ(pqData.check_command(""), -1);
        EXPECT_EQ(pqData.check_command("123"), -1);
    }

    /* Test for checking empty buffer.
    *
    */
    TEST_F(TestCppBuffer, PrintTest1){
        PQueue pqData;
        std::string expected{"Error: buffer is empty\n"};
        pqData.print();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking base functionality.
    *
    */
    TEST_F(TestCppBuffer, PrintTest2){
        PQueue pqData;
        pqData.check_command("123:1");
        pqData.check_command("456:2");
        pqData.check_command("321:3");
        pqData.check_command("654:0");
        std::string expected{"654\n123\n456\n321\n"};
        pqData.print();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking empty buffer.
    *
    */
    TEST_F(TestCppBuffer, GetTest1){
        PQueue pqData;
        std::string expected{"Error: buffer is empty\n"};
        pqData.get();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking base functionality.
    *
    */
    TEST_F(TestCppBuffer, GetTest2){
        PQueue pqData;
        pqData.check_command("123:1");
        std::string expected{"123\n"};
        pqData.get();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking priority.
    *
    */
    TEST_F(TestCppBuffer, GetTest3){
        PQueue pqData;
        pqData.check_command("123:1");
        pqData.check_command("321:0");
        std::string expected{"321\n"};
        pqData.get();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking same priority case.
    *
    */
    TEST_F(TestCppBuffer, GetTest4){
        PQueue pqData;
        pqData.check_command("123:1");
        pqData.check_command("321:1");
        std::string expected{"123\n"};
        pqData.get();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking empty buffer.
    *
    */
    TEST_F(TestCppBuffer, RemoveTest1){
        PQueue pqData;
        std::string expected{"Error: buffer is empty\n"};
        pqData.remove();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for checking base functionality.
    *
    */
    TEST_F(TestCppBuffer, RemoveTest2){
        PQueue pqData;
        pqData.check_command("123:1");
        std::string expected{"123 will be removed\n"};
        pqData.remove();
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    /* Test for a more complete program flow.
    *
    */
    TEST_F(TestCppBuffer, ProgramTest1){
        PQueue pqData;
        int i = 0;

        pqData.check_command("2:2");
        pqData.check_command("3:2");
        pqData.check_command("4:2");
        pqData.check_command("5:2");
        pqData.check_command("1:0");
        pqData.check_command("6:3");
        pqData.get();
        std::string expected{"1\n"};
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);

        for(i=0; i<10; i++){
            buffer.str(std::string());
            pqData.print();
            expected = "1\n2\n3\n4\n5\n6\n";
            actual = buffer.str();
            EXPECT_EQ(expected, actual);
        }

        buffer.str(std::string());
        pqData.remove();
        expected = "1 will be removed\n";
        actual = buffer.str();
        EXPECT_EQ(expected, actual);

        buffer.str(std::string());
        pqData.print();
        expected = "2\n3\n4\n5\n6\n";
        actual = buffer.str();
        EXPECT_EQ(expected, actual);
    }
} /* end namespace */
