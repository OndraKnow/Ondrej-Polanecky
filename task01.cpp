#include <stdio.h>
#include <stdlib.h>
char result[64];
const char* toUpper(const char* input) {
	
	int counter = 0;
	while (*input != '\0'  && counter <63) {
		if (*input < 123 && *input >96) {
			result[counter] = *input - 32;
			++counter;
		}
		else {
			result[counter] = *input;
			++counter;
		}

		++input;

	}
	return result;

}

int main() {
	const char* input = "Hello, World!";
	puts(toUpper(input)); // should print HELLO, WORLD!
}