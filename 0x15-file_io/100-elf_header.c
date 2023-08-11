#include <stdio.h>
#include "main.h"
#include <elf.h>

/**
 * check_elf - checks if a file is an elf file
 * @e_ident: pointer to an array containig the 
 * numbers of elf
 * Return: nothing
 */
void check_elf(unsigned char *e_ident)
{
	int j = 0;

	while (j < 4)
	{
		if ((int)e_ident[j] != 127 && e_ident[j] != 'E' && e_ident[j]
				!= 'L' && e_ident[j] != 'F')
		{

			dprintf(STDERR_FILENO, "Error: Not a valid  ELF file\n");

			exit(98);

		}
		
		j++;

	}
}


/**
 * print_magic: prints a magic number
 * @e_ident: pointer to an array of the ELF magic numbers
 * Return: nothing
 */
void print_magic(unsigned char *e_ident)
{
	int x = 0;

	printf("  Magic:  ");

	while (x < EI_NIDENT)
	{
		printf("%02x", e_ident[x]);
		if (x == EI_NIDENT -1)
			printf("\n");
		else
			printf(" ");
		x++;
	}
}

/**
 * print_class - prints the class of elf header
 * @e_ident: pointer to the array of elf class
 * Return: nothing
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
	        printf("ELF64\n");
	        break;
	default:
	        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	 }
}

/**
 * print_data - prints the data of elf header
 * @e_ident: pointer to array of elf data
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data: ");
	
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - prints version of elf header
 * @e_ident: pointer to array containing version
 * Return: nothing
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version: e_ident[EI_VERSION]  ");

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - prints OS/ABI of elf header
 * @e_ident: pointer to array containing the elf version
 * Return: nothing
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
              printf("UNIX - System V\n");
	      break;
	case ELFOSABI_HPUX:
	      printf("UNIX - HP-UX\n");
	      break;
	case ELFOSABI_NETBSD:
	      printf("UNIX - NetBSD\n");
	      break;
	case ELFOSABI_LINUX:
	      printf("UNIX - Linux\n");
	      break;
	case ELFOSABI_SOLARIS:
	      printf("unix - Solaris\n");
	      break;
	case ELFOSABI_IRIX:
	      printf("UNIX - IRIX\n");
	      break;
	case ELFOSABI_FREEBSD:
	      printf("UNIX - FreeBSD\n");
	      break;
	case ELFOSABI_TRU64:
	      printf("UNIX - TRU64\n");
	      break;
	case ELFOSABI_ARM:
	      printf("ARM\n");
	      break;
	case ELFOSABI_STANDALONE:
	      printf("Standalone App\n");
	      break;
	default:
	      printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - prints ABI Version of elf header
 * @e_ident: pointer to array containing the ABI version
 * Return: nothing
 */
void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}



/**
 * print_types - prints the type of elf header
 * @e_type: the elf type
 * @e_ident: pointer to array containing the types
 * Return: nothing
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	printf(" Type: ");

	if (e_ident[EI_CLASS] == ELFCLASS32 ||
		e_ident[EI_CLASS] == ELFCLASS64)
	{
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocation file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
	}
}




/**
 * print_entry - prints the entry point of elf header
 * @e_entry: address of the elf entry point
 * @e_ident: pointer to array containing the entry point
 * Return: nothing
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("Entry point address: ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0XFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}


/**
 * close_elf - Closes the ELF header file
 * @elf: file descriptor of the elf header file
 * Return: nothing
 */
void close_elf(int elf)
{
      if (close(elf) == -1)
      {
	      dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
	      exit(98);
      }
}




/**
 * main: displays the content of ELF header file
 * @argc: the argument count
 * @argv: pointer to arrays of arguments
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int fd, r;

	Elf64_Ehdr *header;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(fd, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: '%s': No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("EL Header: \n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(fd);

	return (0);
}
