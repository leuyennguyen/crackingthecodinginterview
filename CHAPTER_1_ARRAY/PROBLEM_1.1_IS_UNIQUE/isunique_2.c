/*
	Problem 1.1 IS UNIQUE
	Implement an algorithm to determine if a string has all unique
	characters. What if you cannot use additional data structures?
*/

// Hashing: O(n)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insertKey(char hashTable[], int length, char val) {
	int i = 0, result = 1;
	// Calculate the key of each character using its ASCII
	// 'key' will be an index of that character in the hash table
	int key = (int) val % length;

	// If the slot with index key-th has 0, (empty slot
	// in the hash table), store that character there
	if (hashTable[key] == 0) {
		hashTable[key] = val;
	}
	// If the slot with index key-th does not store 0
	else {
		// If any value stored in key-th index equals to
		// the current-hashing value (the character is repeated),
		// set 'result' to 0 and return
		if (hashTable[key] == val) {
			result = 0;
			return result;
		}
		// Else (in case of collision, two keys mapp to the same
		// index), keep hashing to find a free slot
		else {
			int flag = 1;
			while (flag) {
				key = (key + i*i) % length;
				if (hashTable[key] == 0) {
					hashTable[key] = val;
					flag = 0;
				}
				i++;
			}
		}
	}
	return result;
}

int main()
{
	int result = 1;
	// Assume that the string has less than 10 characters
	char input[10] = {};
	printf("Enter the string: ");
	scanf("%s", input);
	int length = strlen(input);

	char hashTable[length];
	// Initialize each element in 'hashTable' to 0
	memset(hashTable, 0, sizeof(hashTable));

	int i;
	for (i = 0 ; i < length ; i++) {
		result = insertKey(hashTable, length, input[i]);
		if (result == 0) break;
	}
	
	if (result == 0) {
		printf("The string is not unique.\n");
	}
	else {
		printf("The string is unique.\n");
	}
	return 0;
}
