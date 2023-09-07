#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

/**
 * print_elf_header_info - Print information from ELF header.
 * @header: Pointer to the ELF header structure.
 */
void print_elf_header_info(Elf64_Ehdr *header);

/**
 * main - Entry point of the program.
 * @argc: The number of command line arguments.
 * @argv: An array containing the command line arguments.
 * Return: 0 on success, 1 on incorrect usage, 98 on error.
 */
int main(int argc, char *argv[]);

void print_elf_header_info(Elf64_Ehdr *header)
{
	int i;
	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\nClass: %d-bit\n", (header->e_ident[EI_CLASS] == ELFCLASS64) ? 64 : 32);
	printf("Data: %s-endian\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "Little" : "Big");
	printf("Version: %d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", header->e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type: %d\n", header->e_type);
	printf("Entry point address: 0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;
	ssize_t n;
	const char *elf_filename; /* Declare elf_filename at the beginning of the block */

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (1);
	}

	elf_filename = argv[1]; /* Assign the value here */
	fd = open(elf_filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (98);
	}

	n = read(fd, &header, sizeof(header));
	if (n == -1)
	{
		perror("Error reading file");
		close(fd);
		return (98);
	}

	if (n != sizeof(header) || memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		return (98);
	}

	print_elf_header_info(&header);

	close(fd);
	return (0);
}

