#include <stdlib.h>
#include <stdio.h>

/**
 * print_opcodes - print the opcodes of this program
 * @a: address of the main function
 * @n: number of bytes to print
 *
 * Return: void
 */
void print_opcodes(char *a, int n)
{
	if (a == NULL)
		return;
int i;

for (i = 0; i < n; i++)
{
printf("%x", a[i]);
if (i < n - 1)
printf(" ");
}
printf("\n");

}

/**
 * main - prints the opcodes of its own main function
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: O
 */
int main(int argc, char *argv[])
{
	int bytes, i;
	char *arr;

	if (arr == NULL)
		return;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	arr = (char *)main;

	for (i = 0; i < bytes; i++)
	{
		if (i == bytes - 1)
		{
			printf("%x\n", arr[i]);
			break;
		}
		printf("%x ", arr[i]);
	}
	return (0);
}
