#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

using namespace std;
using ::testing::_;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

class Foo {
public:
    // Virtual method to be mocked
    virtual bool testFunction(vector<int>& v, int& d) = 0;
};

class MockFoo : public Foo {
public:
    MOCK_METHOD(bool, testFunction, (vector<int>& v, int& d), (override));
};

TEST(MockReferenceParamsTest, TestFunctionMocking) {
    MockFoo mockFoo;

    vector<int> v = {1, 2, 3};  // Example initial vector
    vector<int> expectedV = {4, 5, 6};  // Expected vector after the call
    int d = 0;  // Initial integer value
    int expectedD = 10;  // Expected integer value after the call

    // Set expectations
    EXPECT_CALL(mockFoo, testFunction(_, _))
        .WillOnce(DoAll(
            SetArgReferee<0>(expectedV),  // Set the first reference argument (vector<int>&)
            SetArgReferee<1>(expectedD),  // Set the second reference argument (int&)
            Return(true)  // Return true from the function
        ));

    // Act
    bool result = mockFoo.testFunction(v, d);

    // Assert
    EXPECT_TRUE(result);
    EXPECT_EQ(v, expectedV);
    EXPECT_EQ(d, expectedD);
}
