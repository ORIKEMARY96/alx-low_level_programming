#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 *
 * Return: pointer of an array of chars
 */
char *str_concat(char *s1, char *s2)
{
	char *strout;
	unsigned int i, j, len1, len2;

	len1 = 0;

	len2 = 0;

	while (s1 && s1[len1] != '\0')
		len1++;
	while (s2 && s2[len2] != '\0')
		len2++;

	strout = malloc(sizeof(char) * (len1 + len2 + 1));
        if (strout == NULL)
		return (NULL);
	i = 0;
	j = 0;

        if (s1 == NULL)
	{
		return (NULL);

	   for (i = 0; i < len1; i++)
	   {
               strout[i] = s1[i];
	   }

	}
	 if (s2 == NULL)
	 {

	 for (j = 0; j < len1 + len2; j++)
	 {
            strout[j] = s2[j];
	 }
	 return (NULL);
	 }
	 strout[i] = '\0';
	 return (strout);
}
