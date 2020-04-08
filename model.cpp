#include <stdio.h>
#include <stdlib.h>

class Model
{
private:
    FILE *fptr;
public:
    Model(){};

    void vlozDoKosiku(int id,const char* name, int price){
        fptr = fopen("kosik.csv","a");
        if(fptr == NULL){
            printf("Error!");   
            exit(1);             
        }
        fprintf(fptr,"%d;%s;%d\n",id,name,price);
        fclose(fptr);
    };
    char* vypisVse(){
        fptr = fopen("data.csv","r");
        static char buff[1024];
        int counter = 0;
        while(1) {
            char c = fgetc(fptr);
            if (counter == 1023){
                return buff;
            }
            if( feof(fptr) ) {
                buff[counter] = '\0';
                return buff; 
                break ;
            }
            if(c == ';'){
                buff[counter] = ' ';
            }
            else{
                buff[counter] = c;
            }
            counter++;
            
        }
    };
    char* vypisKosik(){
        fptr = fopen("kosik.csv","r");
        static char buff[1024];
        int counter = 0;
        while(1) {
            char c = fgetc(fptr);
            if (counter == 1023){
                return buff;
            }
            if( feof(fptr) ) {
                buff[counter] = '\0';
                return buff; 
                break ;
            }
            if(c == ';'){
                buff[counter] = ' ';
            }
            else{
                buff[counter] = c;
            }
            counter++;
            
        }
    };
};

int main(int argc, char *argv[]){
    Model model = Model();
    model.vlozDoKosiku(5,"klavesnice",250);
}

