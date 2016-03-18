/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
#include <stdlib.h>
void str_reverse(char *input, int start, int end);


void str_words_in_rev(char *input, int len){
	int space_pointer = 0, end_pointer = len - 1;
	if ((input) && len >= 0)
	{

		for (int i = len - 1; i >= 0; i--)
		{
			if (input[i - 1] == ' ' || i == 0)
			{
				space_pointer = i;
				str_reverse(input, i, end_pointer);
				while (input[i - 1] == ' ')
				{
					i--;
				}
				end_pointer = i - 1;

			}

		}
		str_reverse(input, 0, len - 1);
	}
}
void str_reverse(char *input, int start, int end)
{
	int looping_count = ((end + 1) - start) / 2;
	char temp;
	for (int j = 0; j<looping_count; j++)
	{
		temp = input[start];
		input[start] = input[end];
		input[end] = temp;
		start++;
		end--;
	}
}