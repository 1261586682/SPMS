#include <iostream>
#include <fstream>
#include <ctime>
#include <direct.h>
#include "Usr_log.h"
#include "Login.h"

Teacher Login_T;
Student Login_S;

Teacher &Get_Usr_T()
{
    return Login_T;
}
Student &Get_Usr_S()
{
    return Login_S;
}
std::string getusrls(KIND k)
{
    std::string s;
    s = getcwd(nullptr, 0);
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == '\\')
            s[i] = '/';
    if (k == TEACHER)
        s += "/admins/Teachers_list.txt";
    else
        s += "/admins/Students_list.txt";
    return s;
}
void delay(int secs)
{
    using namespace std;
    clock_t start = clock();
    clock_t interval = secs * CLOCKS_PER_SEC;
    while (clock() - start <= interval)
        ;
    return;
}
bool search(const std::string &id, const std::string &password, KIND k)
{
    using namespace std;
    if (k == TEACHER)
    {
        Teacher tmp;
        ifstream fin;
        string pwd = getusrls(k);
        fin.open(pwd);
        while (fin >> tmp)
        {
            if (tmp.get_id() == id)
            {
                if (tmp.get_password() != password)
                    return false;
                Login_T = tmp;
                return true;
            }
        }
        fin.close();
    }
    else
    {
        Student tmp;
        ifstream fin;
        string pwd = getusrls(k);
        fin.open(pwd);
        while (fin >> tmp)
        {
            if (tmp.get_id() == id)
            {
                if (tmp.get_password() != password)
                    return false;
                Login_S = tmp;
                return true;
            }
        }
        fin.close();
    }
    return false;
}
KIND reg()
{
    using namespace std;
    string name, password, confirm_password;
    KIND k;
    cout << "1.Teacher   or   2.Student" << endl;
    cin >> k;
    k -= 1;
    cin.get();
    system("cls");
    if (k != 0 && k != 1)
        return 2;
    while (!password.length() || password != confirm_password)
    {
        cout << "Please enter your name:" << endl;
        cout << "name: ";
        cin >> name;
        cout << "Please enter your password:" << endl;
        cout << "password: ";
        cin >> password;
        cout << "Please confirm your password:" << endl;
        cout << "password: ";
        cin >> confirm_password;
        cin.get();
        if (password != confirm_password)
        {
            system("cls");
            cout << "The two passwords are inconsistent!\n";
            cin.get();
            system("cls");
            cout << "1.continue register  or  2.quit" << endl;
            int tmp;
            cin >> tmp;
            system("cls");
            if (tmp != 1)
                return 2;
            cin.get();
        }
    }
    system("cls");
    if (k == TEACHER)
    {
        Teacher newusr(name, password);
        ofstream fout;
        string pwd = getusrls(TEACHER);
        fout.open(pwd, ios::app);
        fout << newusr;
        fout.close();
        string id = newusr.get_id();
        cout << "successfully!" << endl;
        cout << "Please remember your id: " << id << endl;
        cout << "You should log in with this id." << endl;
        delay(5);
        cin.get();
        system("cls");
        Login_T = newusr;
        return TEACHER;
    }
    else
    {
        Student newusr(name, password);
        ofstream fout;
        string pwd = getusrls(STUDENT);
        fout.open(pwd, ios::app);
        fout << newusr;
        fout.close();
        string id = newusr.get_id();
        cout << "successfully!" << endl;
        cout << "Please remember your id: " << id << endl;
        cout << "You should log in with this id." << endl;
        delay(5);
        cin.get();
        system("cls");
        Login_S = newusr;
        return STUDENT;
    }
}
KIND login()
{
    using namespace std;
    string id, password;
    cout << "Please enter your id and password:" << endl;
    cout << "id: ";
    cin >> id;
    cout << "password: ";
    cin >> password;
    cin.get();
    bool flag = false;
    if (id.substr(0, 1) == "T")
        flag = search(id, password, 0);
    else
        flag = search(id, password, 1);
    if (!flag)
    {
        cout << "Incorrect id or password!" << endl;
        cin.get();
        system("cls");
        return 2;
    }
    system("cls");
    if (id.substr(0, 1) == "T")
        return TEACHER;
    else
        return STUDENT;
}
State welcome()
{
    using namespace std;
    cout << "1.login" << endl
         << "2.register" << endl
         << "3.quit" << endl;
    char c;
    cin >> c;
    system("cls");
    if (c == '1')
    {
        KIND k = login();
        if (k == TEACHER)
            return TEACHER;
        else if (k == STUDENT)
            return STUDENT;
    }
    else if (c == '2')
    {
        KIND k = reg();
        if (k == TEACHER)
            return TEACHER;
        else if (k == STUDENT)
            return STUDENT;
    }
    else if (c == '3')
        return QUIT;
    return REMAKE;
}