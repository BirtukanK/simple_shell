#include "shell.h"
/**
 * _strdup - copy of the string given as a parameter
 * @str: unsigned int
 * Return: char pointer
 */

char *_strdup(const char *str)
{
	unsigned int counter1, counter2;
	char *strCopy;

	counter1 = 0;
	counter2 = 0;

	if (str == NULL)
	{
		return (0);
	}

	while (str[counter1] != '\0')
	{
		counter1++;
	}

	strCopy = malloc(sizeof(char) * (counter1 + 1));
	if (strCopy == NULL)
	{
		return (NULL);
	}

	while (counter2 < counter1)
	{
		strCopy[counter2] = str[counter2];
		counter2++;
	}

	strCopy[counter2] = '\0';

	return (strCopy);
}

/**
 * _strcmp - compare strings
 * @str1: arg char
 * @str2: arg char
 * Return: string to stdout
 */


int _strcmp(char *str1, char *str2)
{

	int index;

	for (index = 0; str1[index] != '\0' || str2[index] != '\0'; index++)
	{
		if (str1[index] != str2[index])
		{
			return (str1[index] - str2[index]);
		}
	}
		return (0);
}
/**
 * _strlen - returns the length of a string
 * @str: arg str
 * Return: String length
 */

int _strlen(char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
		return (length);
}

/**
 * _strcat - Adds two strings
 * @s1: First string to add
 * @s2: Second string to add
 * Return: Always temp
 */
char *_strcat(char *s1, char *s2)
{
	int i, j, k, size;
	char *temp;

	i = 0;
	j = 0;
	k = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;

	size = i + j + 1;
	temp = malloc(size * sizeof(char));
	if (temp == NULL)
		return (NULL);

	j = 0;

	while (k < size)
	{
		if (k < i)
		{
			temp[k] = s1[k];
		}
		else
		{
			temp[k] = s2[j];
			j++;
		}
		k++;
	}

	temp[k - 1] = '\0';
	return (temp);
}
/**
 * _strcpy - Prints a string
 * @dest: Destination
 * @src: Source
 * Return: Always dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
