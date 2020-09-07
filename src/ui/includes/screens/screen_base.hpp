#ifndef _screen_base_h
#define _screen_base_h 
#include <string>
using namespace std;

class ScreenBase{
    public: 
    string description;
    virtual void display() = 0; 
};

#endif