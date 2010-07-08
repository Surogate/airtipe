/* 
 * File:   main.cpp
 * Author: errata
 *
 * Created on July 7, 2010, 2:58 PM
 */

#include <iostream>

#include "WTimerManager.hpp"
#include <windows.h>
/*
 * 
 */
int main(void) {
    int t = 0;
    WTimerManager time;
    ITimerManager::timeHdl titi = time.setTimer();
    mtime toto = time.GetActualTime();
    if (!toto.valid)
        std::cout << "error" << std::endl;
    std::cout << "second " << toto.sec << std::endl;
    std::cout << "usecond " << toto.msec << std::endl;
    Sleep(2);
    ITimerManager::timeHdl tata = time.setTimer();
    toto = time.GetUnTimeBetween(tata, titi);
    if (!toto.valid)
        std::cout << "error" << std::endl;
    std::cout << "second " << toto.sec << std::endl;
    std::cout << "usecond " << toto.msec << std::endl;
    return (0);
}

