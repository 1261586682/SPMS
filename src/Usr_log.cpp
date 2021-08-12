#include <string>
#include <fstream>
#include <ctime>
#include "Usr_log.h"

Teacher::Teacher() {}
Teacher::Teacher(const std::string &name, const std::string &password)
{
    T_id = "T_" + std::to_string(std::time(NULL));
    T_name = name;
    T_password = password;
}
std::string Teacher::get_id()
{
    return T_id;
}
std::string Teacher::get_password()
{
    return T_password;
}
Teacher::~Teacher() {}
std::string Teacher::get_name()
{
    return T_name;
}
std::ofstream &operator<<(std::ofstream &fout, const Teacher &T)
{
    fout << T.T_name << ' ' << T.T_id << ' ' << T.T_password << std::endl;
    return fout;
}
std::ifstream &operator>>(std::ifstream &fin, Teacher &T)
{
    fin >> T.T_name >> T.T_id >> T.T_password;
    return fin;
}

Student::Student() {}
Student::Student(const std::string &name, const std::string &password)
{
    S_id = "S_" + std::to_string(std::time(NULL));
    S_name = name;
    S_password = password;
}
std::string Student::get_name()
{
    return S_name;
}
std::string Student::get_id()
{
    return S_id;
}
std::string Student::get_password()
{
    return S_password;
}
Student::~Student() {}
std::ofstream &operator<<(std::ofstream &fout, const Student &S)
{
    fout << S.S_name << ' ' << S.S_id << ' ' << S.S_password << std::endl;
    return fout;
}
std::ifstream &operator>>(std::ifstream &fin, Student &S)
{
    fin >> S.S_name >> S.S_id >> S.S_password;
    return fin;
}