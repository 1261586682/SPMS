#ifndef OP_H_
#define OP_H_
#include "mysql.h"

void query_all(MYSQL &mysql);
void query(MYSQL &mysql);
void insert(MYSQL &mysql);
void update(MYSQL &mysql);
void del(MYSQL &mysql);
void del_all(MYSQL &mysql);

#endif