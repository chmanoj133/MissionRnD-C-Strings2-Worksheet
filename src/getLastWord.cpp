/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str)
{
	int i, len, space_count = 0, index1 = 0, index2 = 0, flag = 0;
	char *last_word;

	if (str == NULL || str == "")
		return "";

	for (len = 0; str[len] != '\0'; len++);

	for (i = len - 1; i >= 0; i--)
	{
		if (str[i] != ' ' && str[i] != '.' && flag == 0){
			index2 = i;
			flag = 1;
		}
		if (flag == 1 && str[i] == ' '){
			index1 = i + 1;
			break;
		}
	}
	
	if (index1 == 0 && index2 == 0 && flag == 0)
		return "";

	last_word = (char*)malloc((index2 - index1 + 1)*sizeof(char));

	for (i = index1; i <= index2; i++)
		last_word[i - index1] = str[i];
	
	last_word[i - index1] = '\0';

	return last_word;
}
