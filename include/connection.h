#ifndef CNCTCONFIG_H_
#define CNCTCONFIG_H_

#include <mysql.h>
#include<string>
std::string getcfg();
bool connect(MYSQL &);
void close(MYSQL &);
#endif