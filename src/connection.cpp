#include "connection.h"
#include <fstream>
#include <iostream>
#include <direct.h>
char host[200];
char user[200];
char password[200];
char database[200];
std::string getcfg()
{
    std::string s;
    s = getcwd(nullptr, 0);
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == '\\')
            s[i] = '/';
    s += "/cfg/cnctconfig.txt";
    return s;
}
bool connect(MYSQL &mysql)
{
    using namespace std;
    string pwd = getcfg();
    ifstream input;
    input.open(pwd);
    input >> host >> user >> password>>database;
    if (!mysql_real_connect(&mysql, host, user, password, database, 3306, 0, 0))
    {
        cout << mysql_error(&mysql) << endl;
        return false;
    }
    else
        cout << "Successfully connected to the database!" << endl;
    return true;
}
void close(MYSQL &mysql)
{
    mysql_close(&mysql);
}