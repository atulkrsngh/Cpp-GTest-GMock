#include <gtest/gtest.h>

// Simple Calculator class for demonstration purposes
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }

    static void connectToDB() {
        std::cout << "Connected to database." << std::endl;
    }

    static void disconnectFromDB() {
        std::cout << "Disconnected from database." << std::endl;
    }
};

// Test suite for Calculator class
class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc; // Calculator object to be used in the tests

    // Called before each test in this test suite runs
    void SetUp() override {
        std::cout << "SetUp: Preparing test environment." << std::endl;
    }

    // Called after each test in this test suite runs
    void TearDown() override {
        std::cout << "TearDown: Cleaning up test environment." << std::endl;
    }

    // Called once before any tests in this test suite run
    static void SetUpTestSuite() { // SetUpTestCase is renamed to SetUpTestSuite in latest googletest
        std::cout << "SetUpTestSuite: Setting up test suite environment." << std::endl;
        Calculator::connectToDB(); // Example: Connecting to a database before tests
    }

    // Called once after all tests in this test suite have run
    static void TearDownTestSuite() {
        std::cout << "TearDownTestSuite: Cleaning up test suite environment." << std::endl;
        Calculator::disconnectFromDB(); // Example: Disconnecting from a database after tests
    }
};

// Test cases

TEST_F(CalculatorTest, AddTest) {
    EXPECT_EQ(calc.add(1, 2), 3);
}

TEST_F(CalculatorTest, SubtractTest) {
    EXPECT_EQ(calc.subtract(5, 3), 2);
}

TEST_F(CalculatorTest, AddTestNegative) {
    EXPECT_EQ(calc.add(-1, -1), -2);
}

TEST_F(CalculatorTest, SubtractTestNegative) {
    EXPECT_EQ(calc.subtract(-5, -3), -2);
}
