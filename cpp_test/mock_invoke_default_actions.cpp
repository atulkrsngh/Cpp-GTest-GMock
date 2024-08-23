#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::Invoke;
using ::testing::DoDefault;

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

struct testABC {
    bool dummyLogin(string a, string b) {
        return true;
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
    testABC dbTest;
    ON_CALL(mdb, login2(_, _)).WillByDefault(Invoke(&dbTest, &testABC::dummyLogin));
    EXPECT_CALL(mdb, login2(_, _)).Times(AtLeast(1)).WillOnce(DoDefault());
    int retValue = db.init("Terminator", "I will be back"); // Act
    EXPECT_EQ(retValue, 1);
}

/*

ON_CALL: Sets up a default action for the login2 method on the mock object mdb. This means that, unless explicitly 
overridden by an EXPECT_CALL, when login2 is called, it will execute dummyLogin method from testABC class (dbTest object).
WillByDefault(Invoke(...)): Specifies that by default, calling login2 should invoke the dummyLogin method on the dbTest 
object.

EXPECT_CALL: Sets up an expectation for login2 method to be called at least once with any arguments.
WillOnce(DoDefault()): Specifies that the first time login2 is called, it should perform the default action that has 
been set up for it (in this case, via ON_CALL).

*/
