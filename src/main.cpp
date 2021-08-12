#include <iostream>
#include "Usr_log.h"
#include "Login.h"
#include "opmenu.h"

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    while (true)
    {
        State flag;
        flag = welcome();
        if (flag == QUIT)
            return 0;
        else if (flag == TEACHER)
            T_op();
        else if (flag == STUDENT)
            S_op();
    }
    return 0;
}