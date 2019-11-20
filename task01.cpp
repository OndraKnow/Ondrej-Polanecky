#include <stdio.h>
#include <stdlib.h>
const char* toUpper(const char* input) {
	static char result[255];
	int counter = 0;
	while (*input != '\0'  ) {
		if (counter >= 254){
			puts("Vysledek Nebude kompletni");
			return result;
		}
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