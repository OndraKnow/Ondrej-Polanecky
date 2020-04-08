#include <conio.h>
#include <cstdio>

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

    mojehra() {
      moves = 0;
    }

    virtual bool checkWin() {
      if(moves<2) return false;
      else return true;
    }

    virtual void makeMove() {
      if(turn) p2guess = getch();
      else p1guess = getch();
      moves++;
    }

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
}