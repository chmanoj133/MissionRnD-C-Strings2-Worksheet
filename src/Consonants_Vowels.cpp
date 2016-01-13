/*
OVERVIEW: Given a string, Count the number of consonants and vowels and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts (*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers ,copy values into those .
*/

#include <stddef.h>

int len(char *str);
void start_count(char a, int *consonants, int *vowels);
void recur_count(char *str, int *consonants, int *vowels, int i, int j);

//	TWO METHODS: 1. Without Recursion
//				 2. With Recursion

/*
// way-1: without recursion
void count_vowels_and_consonants(char *str,int *consonants, int *vowels)
{
	int i, v = 0, c = 0;

	if (str != NULL)
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				v++;
			else if (str[i] >= 'a' && str[i] <= 'z')
				c++;
			else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
				v++;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				c++;
		}

	*consonants = c;
	*vowels = v;
}

*/


// way-2: with recursion
void count_vowels_and_consonants(char *str, int *consonants, int *vowels)
{
	int c = 0, v = 0;
	if (str != NULL)
		recur_count(str, &c, &v, 0, len(str) - 1);
	*consonants = c;
	*vowels = v;
}

void recur_count(char *str, int *consonants, int *vowels, int i, int j)
{
	int mid;
	if (i == j)
		start_count(str[i], consonants, vowels);
	if (i < j)
	{
		mid = (i + j) / 2;
		recur_count(str, consonants, vowels, i, mid);
		recur_count(str, consonants, vowels, mid + 1, j);
	}
}

void start_count(char a, int *consonants, int *vowels)
{
	int c = 0, v = 0;

	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		*vowels = *vowels + 1;
	else if (a >= 'a' && a <= 'z')
		*consonants = *consonants + 1;
	else if (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
		*vowels = *vowels + 1;
	else if (a >= 'A' && a <= 'Z')
		*consonants = *consonants + 1;
}

int len(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}