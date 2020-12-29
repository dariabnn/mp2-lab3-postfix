#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

template <class T>
class TStack
{
    T* pMem;
    int size;
    int top;
public:
    TStack(int _size = 1)
    {
        size = _size;
        top = -1;
        if ((size < 1) || (size > MaxStackSize))
            throw size;
        pMem = new T[size];
    }

    TStack(const TStack& tmp)
    {
        size = tmp.size;
        top = tmp.top;
        pMem = new T[size];
        for (int i = 0; i < size; i++)
            pMem[i] = tmp.pMem[i];
    }

    ~TStack()
    {
        delete[] pMem;
    }

    void push(T element)
    {
        if (full())
            throw "full";
        top++;
        pMem[top] = element;
    }

    T pop()
    {
        if (empty())
            throw "empty";
        top--;
        return pMem[top + 1];
    }

    bool empty()
    {
        return top == -1;
    }

    bool full()
    {
        return top == (size - 1);
    }

    T get_element()
    {
        return pMem[top];
    }
};

#endif
