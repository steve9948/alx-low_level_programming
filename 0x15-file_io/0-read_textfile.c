#include "main.h"

/**
* read_textfile - Reads a file and prints it to standard output
* @filename: name of the file being read
* @letters: number of letters to be printed
*
* Return: 0 if file cannot be opened or read
* 0 if filename is NULL
* 0 if write failes orthe expected number of bytes
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf = malloc(sizeof(char) * letters + 2);
	ssize_t bytes_read, output;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	bytes_read = read(fd, (void *)buf, letters);

	if (bytes_read == -1)
		return (0);

	output = write(STDOUT_FILENO, (const void *)buf, bytes_read);

	close(fd);
	free(buf);

	return (output);
}
