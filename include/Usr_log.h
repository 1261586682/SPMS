#ifndef USR_LOG_H_
#define USR_LOG_H_

#include <string>
#include <iostream>

class Teacher
{
private:
    std::string T_name;
    std::string T_password;
    std::string T_id;

public:
    Teacher();
    std::string get_id();
    std::string get_password();
    std::string get_name();
    Teacher(const std::string &name, const std::string &password);
    friend std::ofstream &operator<<(std::ofstream &fout, const Teacher &T);
    friend std::ifstream &operator>>(std::ifstream &fin, Teacher &T);
    ~Teacher();
};
class Student
{
private:
    std::string S_name;
    std::string S_password;
    std::string S_id;

public:
    Student();
    std::string get_id();
    std::string get_password();
    std::string get_name();
    Student(const std::string &name, const std::string &password);
    friend std::ofstream &operator<<(std::ofstream &fout, const Student &T);
    friend std::ifstream &operator>>(std::ifstream &fin, Student &T);
    ~Student();
};

#endif