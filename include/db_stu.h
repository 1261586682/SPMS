#ifndef DB_STU_H_
#define DB_STU_H_

#include <string>
#include <iostream>
class db_student
{
private:
    std::string db_id;
    std::string db_name;
    std::string db_class;
    int db_chinese;
    int db_math;
    int db_english;

public:
    db_student();
    db_student(const std::string &, const std::string &, const std::string &, const int &, const int &, const int &);
    friend std::ostream &operator<<(std::ostream &out, const db_student &stu);
    friend std::istream &operator>>(std::istream &in, db_student &stu);
    const std::string &get_id();
    const std::string &get_name();
    const std::string &get_class();
    const int &get_chinese();
    const int &get_math();
    const int &get_english();
    ~db_student();
};

#endif