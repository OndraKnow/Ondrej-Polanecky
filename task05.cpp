#include <iostream>

struct Button{
    virtual void waitForButton() = 0;
    virtual void hello() = 0;
    
    void printhello(){
        while (true)
        {
            waitForButton();
            hello();
        }   
    }
};

struct ButtonPC:Button{
    void waitForButton(){
        while(getchar()!='\n');
    }
    
    void hello(){
        puts("hello");
    }
};

int main( int argc, char ** argv ){
    ButtonPC mujButton;
    mujButton.printhello();
}
