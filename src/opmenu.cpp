#include "connection.h"
#include "Usr_log.h"
#include "Login.h"
#include "opmenu.h"
#include "op.h"
#include "mysql.h"
#include <iostream>

void T_op()
{
    using namespace std;
    cout << "Connect to the database..." << endl;
    MYSQL mysql;
    mysql_init(&mysql);
    if (connect(mysql))
    {
        system("cls");
        cout << "welcome! " << Get_Usr_T().get_name() << endl;
    }
    cout << "1:Grade Query Accurately" << endl
         << "2:Grade Query ALL" << endl
         << "3:Grade Update" << endl
         << "4:Grade Insert" << endl
         << "5:Grade Delete" << endl
         << "6:Grade Delete ALL" << endl
         << "7:quit" << endl;
    int op = 5;
    while (cin >> op)
    {
        system("cls");
        if (op == 1)
            query(mysql);
        else if (op == 3)
            update(mysql);
        else if (op == 4)
            insert(mysql);
        else if (op == 5)
            del(mysql);
        else if (op == 2)
            query_all(mysql);
        else if (op == 6)
            del_all(mysql);
        else if (op == 7)
        {
            close(mysql);
            return;
        }
        cout << "1:Grade Query Accurately" << endl
             << "2:Grade Query ALL" << endl
             << "3:Grade Update" << endl
             << "4:Grade Insert" << endl
             << "5:Grade Delete" << endl
             << "6:Grade Delete ALL" << endl
             << "7:quit" << endl;
    }
    close(mysql);
    return;
}
void S_op()
{
    using namespace std;
    cout << "Connect to the database..." << endl;
    MYSQL mysql;
    mysql_init(&mysql);
    if (connect(mysql))
    {
        system("cls");
        cout << "welcome! " << Get_Usr_S().get_name() << endl;
    }
    cout << "1:Grade Query Accurately" << endl
         << "2:quit" << endl;
    int op = 2;
    while (cin >> op)
    {
        system("cls");
        if (op == 1)
        {
            query(mysql);
        }
        else if (op == 2)
        {
            close(mysql);
            return;
        }
        cout << "1:Grade Query Accurately" << endl
             << "2:quit" << endl;
    }
    close(mysql);
    return;
}