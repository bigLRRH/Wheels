#include<iostream>

template<typename T>
void print(T & t)
{
    std::cout<<"左值"<<std::endl;
}

template<typename T>
void print(T && t)
{
    std::cout<<"右值"<<std::endl;
}

template<typename T>
void testForward(T && v)
{
    print(v);
    print(std::forward<T>(v));
    print(std::move(v));
}

int main()
{
    testForward(1);
    std::cout << "======================" << std::endl;
    int x = 1;
    testForward(x);    
    return 0;
}
