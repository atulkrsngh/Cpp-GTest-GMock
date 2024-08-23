#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DataBaseConnect {
public:
    virtual bool login(string username, string password) {
        return true;
    }
    virtual bool login2(string username, string password) {
        return true;
    }
    virtual bool logout(string username) {
        return true;
    }
    virtual int fetchRecord() {
        return -1;
    }
};

class MockDB : public DataBaseConnect { // Mock for database connect class
public:
    MOCK_METHOD0(fetchRecord, int());
    MOCK_METHOD2(login, bool(string username, string password));
    MOCK_METHOD2(login2, bool(string username, string password));
    MOCK_METHOD1(logout, bool(string username));
};

class myDataBase {
    DataBaseConnect& dbc;
public:
    myDataBase(DataBaseConnect& _dbc): dbc(_dbc) {}
    int init(string username, string password) {
        int rValue = rand()%2;
        if(rValue == 0) {
            if(dbc.login(username, password) != true) {
                if(dbc.login(username, password) != true) {
                    return -1;
                }
            } else {
                return 1;
            }
        } else {
            return dbc.login2(username, password);
        }
        return -1;
    }
};

TEST(myDBTest, logintest) {
    //Arrange
    MockDB mdb;
    myDataBase db(mdb);
    // EXPECT_CALL(mdb, login(_, _).Times(AtLeast(1))).WillRepeatedly(Return(true));
    // EXPECT_CALL(mdb, login(_, _).Times(1)).WillOnce(Return(true));
    ON_CALL(mdb, login(_, _)).WillByDefault(Return(true));
    ON_CALL(mdb, login2(_, _)).WillByDefault(Return(true));
    int retValue = db.init("Terminator", "I will be back"); // Act
    EXPECT_EQ(retValue, 1); // Assert
}

/*

Flexibility: ON_CALL gives you flexibility to set up default behaviors that help the function under test execute 
correctly, even if those behaviors are not the primary focus of the test.

Non-Strict Behavior: ON_CALL does not impose strict requirements on method calls (like number of times or specific 
arguments). This means you can use it to provide supportive behavior without making the test dependent on exact calls.

Supplementary Actions: Use ON_CALL when you want to do something extra or need a generic setup that isn't directly 
tested but supports the overall testing environment.

EXPECT_CALL is used when you need to verify specific behaviors, enforce certain conditions, or ensure that a method 
is called a specific number of times with specific arguments. It’s stricter and is used to check interactions with 
the mock object directly as part of the test's assertions.

Use ON_CALL to set up default behaviours or perform supplementary actions that aren't the main focus of your test.
Use EXPECT_CALL to assert specific behaviors, interactions, or conditions that are central to what you are testing.

*/
