/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int indexing(char *str, int index);

char ** commonWords(char *str1, char *str2) {

	if (str1&&str2)
	{
		int i = 0, j = 0, wrd_count = 0, temp = 0, ele_index = 0;
		char **arr;
		arr = (char **)malloc(sizeof(char));
		for (int s = 0; str1[s] != '\0'; s++)
		{

			arr[wrd_count] = (char *)malloc(sizeof(char));
			while (str1[i] == ' ')
				i++;
			//if the string is full of spaces
			if (str1[i] == '\0')
				return NULL;
			temp = i;
			for (j = 0; str2[j] != '\0'; j++)
			{

				if (str1[i] == str2[j] && str1[i] != '\0' && str1[i] != ' ')
				{
					arr[wrd_count] = (char *)realloc(arr[wrd_count], ele_index + 1 * sizeof(char));
					arr[wrd_count][ele_index] = str1[i];
					ele_index++;
					i++;
				}
				else if ((str2[j] == ' ' && str1[i] == '\0') || (str1[i] == ' ' && str2[j] == ' '))
				{
					arr[wrd_count][ele_index] = '\0';
					ele_index = 0;
					wrd_count++;
					//printf("%s",arr[wrd_count]);
					//printf("%d", wrd_count);
					break;
				}
				else
				{
					arr[wrd_count] = (char *)realloc(arr[wrd_count], sizeof(char)* 0);
					i = temp;
					ele_index = 0;
					j = indexing(str2, j);
					if (j == NULL)
						break;

				}
			}
			if (str2[j] == '\0' && str1[i] == ' ' || str2[j] == '\0' && str1[i] == '\0')
			{
				arr[wrd_count][ele_index] = '\0';
				wrd_count++;
				//printf("%d", wrd_count);
				ele_index = 0;
			}
			i = indexing(str1, i);
			j = 0;
			if (i == 0)
				break;
		}
		if (wrd_count == 0)
			return NULL;
		arr[wrd_count] = '\0';
		/*	for (int i = 0; i < wrd_count; i++)
		{
		printf("%s", arr[i]);
		}*/
		return arr;
	}
	else
		return NULL;
}
int indexing(char *str, int index)
{
	while (str[index] != '\0')
	{
		if (str[index] == ' ' && str[index + 1] != ' ')
		{
			return index;
		}
		index++;
	}
	//if j is to be positioned at end of the string
	return NULL;
}