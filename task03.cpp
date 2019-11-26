/*
  Write a "task03" program for basic adding. It should handle -f, -i and -v parameters

  task03 -f data.txt // outputs sum of numbers in data.txt
  task03 -i // interactive mode: sums numbers from standard input until empty input provided
  task03 4 7 12 // outputs sum of any number of arguments (23 in this case)
  implement verbose mode -v, which outputs additional info about arguments, i.e.
    task03 -f data.txt -v // should print "sum of numbers in data.txt is 13"
    task03 -v -f data.txt // same result
    task03 -v -i // should print like "sum of 7 numbers from standard input is 38"
    task03 2 2 13 6 -v // should print "sum of 4 arguments is 23"
    task03 -v 13 4 // should print "sum of 2 arguments is 17"
*/
#include <cstring>
#include <cstdio>
void interactive(bool verbose){
	//TODO
}

void cliData(bool verbose, char* argv[], int argc){
	//TODO
}

void fileData(bool verbose){
	//TODO
	puts("co");
}

int main(int argc, char* argv[]) {
  bool verbose = false;
  if (strcmp(argv[1],"-v") == 0){
	  verbose = true;
	  if(strcmp(argv[2],"-i") == 0){
		  interactive(verbose);
	  }
	  else if(strcmp(argv[2],"-f") == 0){
		  fileData(verbose);
	  }
	  else{
		  cliData(verbose,argv,argc);
	  }
  }
  
  else if (strcmp(argv[1],"-i") == 0){
	  if (argc > 2){
		  if(strcmp(argv[2],"-v") == 0){
			  verbose = true;
			  interactive(verbose);
		  }  
	  }
	  else{
		  interactive(verbose);
	  }
  }
  
  else if(strcmp(argv[1],"-f") == 0){
	  if (argc > 2){
		  if(strcmp(argv[2],"-v") == 0){
			  verbose = true;
			  fileData(verbose);
		  }  
	  }
	  else{
		  fileData(verbose);
	  }
  }
  
  else{
	  cliData(verbose,argv,argc);
  }
  
  
}