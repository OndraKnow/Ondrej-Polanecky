
#include <ncurses.h>
struct hra
{
    virtual bool checkWin() = 0;
    virtual void makeMove() = 0;
    virtual void printResult() = 0;
    
    bool turn = true;
    
    void startGame(){
        while(checkWin() == false){
            turn = !turn;
            makeMove();
        }
        printResult();
    }
};


struct mojeHra : hra
{
    char p1;
    char p2;
    
    int turnCount;
    mojeHra(){
        turnCount = 0;
    }
    virtual bool checkWin(){
        if(turnCount < 2){
            return false;
        }
        else{
            return true;
        }
    }
    virtual void makeMove(){
        if(turn){
            p1 = getch();
        }
        else{
            p2 = getch();
        }
        turnCount++;
    }

    virtual void printResult(){
        if (p1 + 10 <= p2 and p1 - 10 >= p2 ){
            printf("vyhral hrac 1 s pismenem %c",p1);
        }
        else
        {
            printf("vyhral hrac 2 s pismenem %c",p2);
        }
        
    }
};





int main(int argc, char *argv[]){
    initscr();
    mojeHra mojehra;
    mojehra.startGame();
}