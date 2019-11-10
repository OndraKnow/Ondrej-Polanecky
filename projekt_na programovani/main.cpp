#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
HANDLE  hConsole;
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;
void colorPrint(int* arr, int size, int* colorArr) {
	for (int i = size - 1; i >= 0; i--) {
		for (int j = size - 1; j >= 0; j--) {
			printf(" ");
			if (colorArr[0] == j) {
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
			}
			if (colorArr[1] == j) {
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			}
			int value = arr[j];
			if (value > i) {
				printf("#");
			}
			else {
				printf(" ");
			}
			SetConsoleTextAttribute(hConsole, saved_attributes);
		}
		printf("\n");
	}
}

void fillArray(int* array, int size) {
	for (int i = 0; i < size; i++){
		array[i] = i + 1;
	}
}

void printArray(int* array,int size) {
	for (int i = size-1; i >= 0; i--){
		for (int j = size-1; j >=0; j--){
			printf(" ");
			int value = array[j];
			if (value > i) {
				printf("#");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}


void shuffle(int* array,int size) {
	for (int i = 0; i < size; i++) {
		int tempor = array[i];
		int r = rand() % size;

		array[i] = array[r];
		array[r] = tempor;
		system("cls");
		printArray(array, size);
		Sleep(2);
	}
}

void solve(int* array, int size) {
	for (int i = 0; i < size; i++) {
		int min = 1000;
		int index;
		for (int j = i; j < size; j++) {
			if (array[j] < min) {
				min = array[j];
				index = j;
			}
			int colors[2];

			colors[0] = i;
			colors[1] = j;
			system("cls");
			colorPrint(array, size, colors);
			Sleep(5);

		}
		int tempor = array[i];
		array[i] = array[index];
		array[index] = tempor;
	}
}



int main(int argc, char** argv) {

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	int *arr;
	srand(time(NULL));
	const int sizeArray = atoi(argv[1]);
	arr = (int*)malloc(sizeArray * sizeof(int));
	
	fillArray(arr,sizeArray);
	printArray(arr,sizeArray);
	Sleep(2000);
	shuffle(arr, sizeArray);
	Sleep(1000);
	solve(arr, sizeArray);

	
}


