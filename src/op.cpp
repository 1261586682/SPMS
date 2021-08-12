#include <string>
#include <iostream>
#include "db_stu.h"
#include "mysql.h"

std::string p2string(std::string now)
{
    return "\'" + now + "\'";
}
void query_all(MYSQL &mysql)
{
    using namespace std;
    system("cls");
    string q = "select * from student;";
    mysql_query(&mysql, q.c_str());
    MYSQL_RES *res;
    MYSQL_ROW row;
    MYSQL_FIELD *fd;
    int cols = mysql_field_count(&mysql);
    if (!cols)
    {
        cout << "No result!" << endl;
        cin.get();
        cin.get();
        system("cls");
        return;
    }
    res = mysql_store_result(&mysql);
    while (fd = mysql_fetch_field(res))
    {
        cout.setf(ios::left);
        cout.width(15);
        cout << fd->name << " ";
    }
    cout << endl;
    while (row = mysql_fetch_row(res))
    {
        for (int i = 0; i < cols; ++i)
        {
            cout.setf(ios::left);
            cout.width(15);
            cout << row[i] << " ";
        }
        cout << endl;
    }
    mysql_free_result(res);
    cin.get();
    cin.get();
    system("cls");
    return;
}
void query(MYSQL &mysql)
{
    using namespace std;
    db_student stu;
    string id;
    cout << "Please enter student ID:" << endl;
    cin >> id;
    system("cls");
    string q = "select * from student where id = \'" + id + '\'';
    mysql_query(&mysql, q.c_str());
    MYSQL_RES *res;
    MYSQL_ROW row;
    MYSQL_FIELD *fd;
    int cols = mysql_field_count(&mysql);
    if (!cols)
    {
        cout << "No result!" << endl;
        cin.get();
        cin.get();
        system("cls");
        return;
    }
    res = mysql_store_result(&mysql);
    while (fd = mysql_fetch_field(res))
    {
        cout.setf(ios::left);
        cout.width(15);
        cout << fd->name << " ";
    }
    cout << endl;
    while (row = mysql_fetch_row(res))
    {
        for (int i = 0; i < cols; ++i)
        {
            cout.setf(ios::left);
            cout.width(15);
            cout << row[i] << " ";
        }
        cout << endl;
    }
    mysql_free_result(res);
    cin.get();
    cin.get();
    system("cls");
    return;
}
void insert(MYSQL &mysql)
{
    using namespace std;
    int cnt = 0;
    cout << "Please enter the number of information£º" << endl;
    cin >> cnt;
    cout << "Please enter student information:" << endl;
    cout << "Divided by spaces and Default for 0 and all lengths of string are less than 14." << endl;
    cout << "id name class chinese math english:" << endl;
    db_student now;
    int sum = 0;
    while (cnt--)
    {
        cin >> now;
        string q = "insert into student(id, name, class, chinese, math, english) values(" + p2string(now.get_id()) + ", " + p2string(now.get_name()) + ", " + p2string(now.get_class()) + ", " + to_string(now.get_chinese()) + ", " + to_string(now.get_math()) + ", " + to_string(now.get_english()) + ");";
        mysql_query(&mysql, q.c_str());
        sum += mysql_affected_rows(&mysql);
    }
    cout << sum << " rows of records have been successfully inserted!" << endl;
    cin.get();
    cin.get();
    system("cls");
    return;
}
void update(MYSQL &mysql)
{
    using namespace std;
    cout << "Please enter the student id to be updated:" << endl;
    string id;
    string obj[3] = {"chinese", "math", "quit"};
    int c, score;
    cin >> id;
    cout << "1:chinese 2:math 3:english 4:quit" << endl;
    cin >> c;
    if (c != 1 && c != 2 && c != 3)
    {
        system("cls");
        return;
    }
    cout << "Please enter the updated score:" << endl;
    cin >> score;
    string q = "update student set " + obj[c - 1] + "=" + to_string(score) + " where id=\'" + id + "\';";
    mysql_query(&mysql, q.c_str());
    int cnt = 0;
    cnt += mysql_affected_rows(&mysql);
    cout << cnt << " rows of records have been successfully updated!" << endl;
    cin.get();
    cin.get();
    system("cls");
    return;
}
void del_all(MYSQL &mysql)
{
    using namespace std;
    string q = "truncate student;";
    mysql_query(&mysql, q.c_str());
    cout << "Successfully deleted all!" << endl;
    cin.get();
    system("cls");
}
void del(MYSQL &mysql)
{
    using namespace std;
    int sum = 0;
    int cnt = 0;
    cout << "How many do you want to delete?" << endl;
    cin >> sum;
    cout << "Please enter the student id to be deleted:" << endl;
    while (sum--)
    {
        string id;
        cin >> id;
        string p = "delete from student where id=\'" + id + "\';";
        mysql_query(&mysql, p.c_str());
        cnt += mysql_affected_rows(&mysql);
    }
    cout << cnt << " rows of records have been successfully deleted!" << endl;
    cin.get();
    cin.get();
    system("cls");
    return;
}