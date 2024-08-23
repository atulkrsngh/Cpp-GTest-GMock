#include <gtest/gtest.h>

class myClass {
    int baseValue;
public:
    myClass(int _bv) : baseValue(_bv) {}
    void increment(int byValue) {
        baseValue += byValue;
    }
    int getValue() const {
        return baseValue;
    }
};

struct myClassTest : public ::testing::Test {
    myClass *mc;
    void SetUp() override {
        mc = new myClass(100);
    }
    void TearDown() override {
        delete mc;
    }
};

TEST_F(myClassTest, Increment_by_5) {
    mc->increment(5);
    EXPECT_EQ(mc->getValue(), 105);
}

TEST_F(myClassTest, Increment_by_10) {
    mc->increment(10);
    EXPECT_EQ(mc->getValue(), 110);
}
