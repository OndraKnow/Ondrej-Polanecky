#include <iostream>

struct Button{
    virtual void waitForButton() = 0;
    virtual void output() = 0;
    
    void hello(){
        while (true)
        {
            waitForButton();
            output();
        }   
    }
};

struct ButtonPC:Button{
    void waitForButton(){
        getchar();
    }
    void output(){
        puts("hello");
    }
};

int main( int argc, char ** argv ){

    ButtonPC mujButton;
    mujButton.hello();
}