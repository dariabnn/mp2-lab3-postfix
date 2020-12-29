#include <iostream>
#include "postfix.h"
#include "stack.h"
using namespace std;
string TPostfix::ToPostfix()
{
    postfix = "";
    TStack<char> operations_stach(20);
    for (int i = 0; i < infix.length(); i++)
    {
        if (ChechOper(infix[i]))
        {
            if (infix[i] == ')' || infix[i] == '(')
            {
                if (infix[i] == '(')
                    operations_stach.push(infix[i]);
                else
                {
                    while (operations_stach.get_element() != '(')
                        postfix.push_back(operations_stach.pop());
                    operations_stach.pop();
                }
            }
            else
            {
                if (operations_stach.empty()) //если пустой стек, добавляем оператор
                    operations_stach.push(infix[i]);
                else // проверка приоритета
                { //не скобки, не пустой, приоритет последнего оператора стека не меньше текущего
                    while ((GetPriority(operations_stach.get_element()) >= GetPriority(infix[i])) && operations_stach.get_element() != '(' && operations_stach.get_element() != ')' && !operations_stach.empty())
                        postfix.push_back(operations_stach.pop());
                    operations_stach.push(infix[i]);
                }
            }
        }
        else
            postfix.push_back(infix[i]);
    }
    while (!operations_stach.empty())
        postfix.push_back(operations_stach.pop());
    return postfix;
}

double TPostfix::Calculate()
{
    const int N = 20;
    TStack<double> values(N);
    string arr_elem = "";
    bool flag = true;
    double arr_value[N];
    double elem = 0;
    const double n = 0;
    double result = 0;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (ChechOper(postfix[i]))
        {
            result = values.pop();
            if (values.empty())
                values.push(n);
            if (postfix[i] == '+')
                result += values.pop();
            if (postfix[i] == '-')
                result = values.pop() - result;
            if (postfix[i] == '*')
                result = result * values.pop();
            if (postfix[i] == '/')
            {
                if (result == 0)
                    throw "division by zero";
                result = values.pop() / result;
            }
            values.push(result);
        }
        else //инициализация без повторения введенных параметров
        {
            for (int q = 0; q < arr_elem.length(); q++)
            {
                if (postfix[i] == arr_elem[q])
                {
                    values.push(arr_value[q]);
                    flag = false;
                }
            }
            if (flag)
            {
                cout << "Введите величину: " << postfix[i] << endl;
                cin >> elem;
                arr_elem.push_back(postfix[i]);
                arr_value[arr_elem.length() - 1] = elem;
                values.push(elem);
            }
            flag = true;
        }
    }
    return values.pop();
}

bool TPostfix::ChechOper(char element)
{
    const int N = 6;
    char operations[N] = { '+', '-', '*', '/', '(', ')' };
    for (int i = 0; i < N; i++)
        if (element == operations[i])
            return true;
    return false;
}

int TPostfix::GetPriority(char oper)
{
    const int N = 4;
    char operations[N] = { '+', '-', '*', '/' };
    char priority[N] = { 1, 1, 2, 2 };
    for (int i = 0; i < N; i++)
        if (oper == operations[i])
            return priority[i];
    return 3;
}
