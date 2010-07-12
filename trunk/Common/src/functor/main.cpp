/* 
 * File:   main.cpp
 * Author: errata
 *
 * Created on July 6, 2010, 12:33 PM
 */

#include <iostream>
#include "../../include/Functor.hpp"

class toto {
public:
    void disp_v1(int a)
    {
        std::cout << "disp v 1" << std::endl;
        std::cout << a << std::endl;
    }

    void disp_v2(int a, int b)
    {
        std::cout << "disp v2" << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
    }
};


/*
 * 
 */
int main(void) {

    toto test;

    typedef Functor<toto, void, int> functest;

    functest func_ptr(test, &toto::disp_v1);

    func_ptr.call(10);
    return (0);
}

