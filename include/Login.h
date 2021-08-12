#ifndef LOGIN_H_
#define LOGIN_H_

#include <string>
#include "Usr_log.h"
#define TEACHER 0
#define STUDENT 1
#define REMAKE 2
#define QUIT 3
typedef int State;
typedef int KIND;

Teacher &Get_Usr_T();
Student &Get_Usr_S();
std::string getusrls(KIND k);
void delay(int secs);
bool search(const std::string &id, const std::string &password, KIND k);
KIND reg();
KIND login();
State welcome();

#endif