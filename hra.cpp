<<<<<<< HEAD
#include <conio.h>
#include <cstdio>

=======

#include <ncurses.h>
>>>>>>> f4c6145a12afb991d6b350061dc3db3e281008c4
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

struct mojehra : hra {
    int moves;
    char p1guess, p2guess;

<<<<<<< HEAD
    mojehra() {
      moves = 0;
    }
=======
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
            printf("\nvyhral hrac 1 s pismenem %c",p1);
        }
        else
        {
            printf("\nvyhral hrac 2 s pismenem %c",p2);
        }
    }
};


>>>>>>> f4c6145a12afb991d6b350061dc3db3e281008c4

    virtual bool checkWin() {
      if(moves<2) return false;
      else return true;
    }

    virtual void makeMove() {
      if(turn) p2guess = getch();
      else p1guess = getch();
      moves++;
    }

<<<<<<< HEAD
    virtual void printResult() {
      printf("P1 hadal %c, P2 hadal %c.\n", p1guess, p2guess);
      if(p1guess>p2guess) puts("Vyhral P1");
      else if(p1guess<p2guess) puts("Vyhral P2");
      else puts("Remiza");
    }

};



int main(int argc, char *argv[]){
  mojehra stupidGame;
  stupidGame.startGame();
=======
int main(int argc, char *argv[]){
    initscr();
    mojeHra mojehra;
    mojehra.startGame();
>>>>>>> f4c6145a12afb991d6b350061dc3db3e281008c4
}