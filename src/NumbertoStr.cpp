/*
OVERVIEW: Given a float number ,Convert it into a string

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <stdlib.h>

void number_to_str(float number, char *str, int afterdecimal){
	if ((number) && afterdecimal >= 0)
	{

		int num_part = 0, power = 1;
		int flt_part = 0, index = 0, num_length = 0, decimal_index = 0, temp = 0;
		if (number<0)
		{
			str[0] = '-';
			str++;
			number = number*-1;
		}
		num_part = number;
		for (int i = 0; i<afterdecimal; i++)
		{
			power *= 10;
		}
		flt_part = (number - num_part)*power;
		temp = num_part;
		while (temp)
		{
			num_length++;
			temp = temp / 10;
		}
		printf("%d\n", num_length);
		decimal_index = num_length;
		while (num_part)
		{
			index = num_length;
			str[index - 1] = num_part % 10 + '0';
			num_length--;
			num_part = num_part / 10;
		}
		if (flt_part>0)
		{

			str[decimal_index] = '.';
			index = decimal_index + afterdecimal;
			str[index + 1] = '\0';
			while (flt_part)
			{
				str[index] = flt_part % 10 + '0';
				index--;
				flt_part = flt_part / 10;
			}
		}
	}
}
