#include "db_stu.h"
#include <string>
#include <iostream>

db_student::db_student()
{
    db_id = "";
    db_name = "";
    db_class = "";
    db_chinese = 0;
    db_math = 0;
    db_english = 0;
}
db_student::db_student(const std::string &a, const std::string &b, const std::string &c, const int &d, const int &e, const int &f)
{
    db_id = a;
    db_name = b;
    db_class = c;
    db_chinese = d;
    db_math = e;
    db_english = f;
}
std::ostream &operator<<(std::ostream &out, const db_student &stu)
{
    out << stu.db_id << std::endl
        << stu.db_name << std::endl
        << stu.db_class << std::endl
        << stu.db_chinese << std::endl
        << stu.db_math << std::endl
        << stu.db_english << std::endl;
    return out;
}
std::istream &operator>>(std::istream &in, db_student &stu)
{
    in >> stu.db_id >> stu.db_name >> stu.db_class >> stu.db_chinese >> stu.db_math >> stu.db_english;
    return in;
}
db_student::~db_student() {}
const std::string &db_student::get_id() { return db_id; }
const std::string &db_student::get_name() { return db_name; }
const std::string &db_student::get_class() { return db_class; }
const int &db_student::get_chinese() { return db_chinese; }
const int &db_student::get_math() { return db_math; }
const int &db_student::get_english() { return db_english; }