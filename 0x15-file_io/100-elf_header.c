#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * main - Displays information contained in the ELF header of a given ELF file.
 * @argc: The number of arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: Always 0 on success, or exit with status code 98 on error.
 */
int main(int argc, char **argv)
{
	int fd, i;
	Elf64_Ehdr header;
	ssize_t read_result;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]), exit(98);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Cannot open file %s\n", argv[1]), exit(98);

	read_result = read(fd, &header, sizeof(header));
	if (read_result != sizeof(header))
		dprintf(STDERR_FILENO, "Cannot read ELF %s\n", argv[1]), close(fd), exit(98);

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 ||
	    header.e_ident[EI_MAG3] != ELFMAG3)
		dprintf(STDERR_FILENO, "E %s not ELF file\n", argv[1]), close(fd), exit(98);

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header.e_ident[i]);
	printf("\nClass: %s\n",
	       (header.e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("Data: %s\n",
	       (header.e_ident[EI_DATA] == ELFDATA2LSB) ? "lilE" : "Unknow encoding");
	printf("Version: %d\n", header.e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", header.e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
	printf("Type: %d\n", header.e_type);
	printf("Entry point address: 0x%lx\n", (unsigned long)header.e_entry);

	close(fd);
	return (0);
}
