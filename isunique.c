#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Brute Force: O(n^2)
int isUnique(char * input)
{
	int length = strlen(input);
	int i, j, result = 1;
	for (i = 0 ; i < length ; i++) {
    		for (j = 0 ; j < i ; j++) {
        			if (input[i] == input[j]) {
            				result = 0;
            				break;
        			}
    		}
	}
	return result;
}

int main()
{
    // Assume that the string has less than 10 characters
	char input[10] = {};
    printf("Enter the string: ");
    scanf("%s", input);

	int length = strlen(input);
	int result = isUnique(input);
	if (result == 0) {
		printf("The string is not unique.\n");
	}
	else {
		printf("The string is unique.\n");
	}
	return 0;
}
