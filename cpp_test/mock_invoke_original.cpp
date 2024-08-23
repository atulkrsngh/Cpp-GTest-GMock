#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::Invoke;

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
    MockDB mdb;
    myDataBase db(mdb);
    DataBaseConnect dbTest;
    EXPECT_CALL(mdb, login2(_, _)).Times(AtLeast(1)).WillOnce(Invoke(&dbTest, &DataBaseConnect::login));
    int retValue = db.init("Terminator", "I will be back"); // Act
    EXPECT_EQ(retValue, 1);
}

/*

The line WillOnce(Invoke(&dbTest, &DataBaseConnect::login)) instructs the mock framework to redirect the call 
from mdb.login2 to the real method dbTest.login. This means, in effect, you're using the real behavior of the 
login method when login2 is invoked on the mock object.

the first time the login2 method is called on the mock object mdb, it will not execute the mock’s default behavior 
(which would usually do nothing or return a default value). Instead, it calls the login method of the real object 
dbTest, which is an instance of DataBaseConnect.

*/
