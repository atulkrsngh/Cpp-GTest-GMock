#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::InvokeWithoutArgs;

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

bool dummyLogin () { // Global function
    return true;
}

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
    MockDB mdb;
    myDataBase db(mdb);
    EXPECT_CALL(mdb, login2(_, _)).Times(AtLeast(1)).WillOnce(InvokeWithoutArgs(dummyLogin)); // Invoking global function
    int retValue = db.init("Terminator", "I will be back"); // Act
    EXPECT_EQ(retValue, 1);
}