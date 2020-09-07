#ifndef _quit_screen_hpp
#define _quit_screen_hpp
#include "screen_base.hpp"

class QuitScreen: public ScreenBase{
    public:
    void display(){
        exit(0);
    }
    QuitScreen(){
        description = "Quit";
    }
};

#endif