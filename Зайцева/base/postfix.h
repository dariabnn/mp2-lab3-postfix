#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
    string infix;
    string postfix;
public:
    TPostfix()
    {
        infix = "a+b";
    }

    TPostfix(string s)
    {
        infix = s;
    }

    string GetInfix() { return infix; }
    string GetPostfix() { return postfix; }
    string ToPostfix();
    double Calculate(); // Ввод переменных, вычисление по постфиксной форме
    bool ChechOper(char element); //проверить оператор/операнд
    int GetPriority(char oper); // получить приоритет операции
};


#endif
