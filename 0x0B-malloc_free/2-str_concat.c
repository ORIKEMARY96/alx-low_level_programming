#include "main.h"
#include <stdlib.h>

/**
 *  *str_concat - concatenate two strings
 *  @s1: string to concatenate
 *  @s2: other string to concatenate
 *  Return: pointer to the new string or NULL
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

	if (s1 == NULL)
	{


	for (i = 0; i < len1; i++)
	{

	  strout[i] = s1[i];
	}


           return (NULL);
	}
        
        if (s2 == NULL)
	{
	for (j = 0; j < len1 + len2 + 1; j++)
	{
	  strout[j] = s2[j];
	}

          return (NULL);
	}
	
	return (strout);

}

