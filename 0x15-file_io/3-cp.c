#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int open_source_file(const char *src_filename);
int open_dest_file(const char *dest_filename);
void close_file(int fd);
int read_and_write(int fd_from, int fd_to);
int copy_file(const char *src_filename, const char *dest_filename);

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, or exit with error codes 97 to 100.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	if (copy_file(argv[1], argv[2]) == -1)
		exit(98);

	return (0);
}

/**
 * copy_file - Copies the content of a file to another file.
 * @src_filename: The name of the source file.
 * @dest_filename: The name of the destination file.
 *
 * Return: 0 on success, or -1 on failure.
 */
int copy_file(const char *src_filename, const char *dest_filename)
{
	int fd_from, fd_to, ret;

	fd_from = open_source_file(src_filename);
	fd_to = open_dest_file(dest_filename);

	if (fd_from == -1 || fd_to == -1)
	{
		close_file(fd_from);
		close_file(fd_to);
		return (-1);
	}

	ret = read_and_write(fd_from, fd_to);

	close_file(fd_from);
	close_file(fd_to);

	return (ret);
}

/**
 * open_source_file - Opens the source file in read-only mode.
 * @src_filename: The name of the source file.
 *
 * Return: The file descriptor, or -1 on failure.
 */
int open_source_file(const char *src_filename)
{
	int fd_from = open(src_filename, O_RDONLY);

	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src_filename);

	return (fd_from);
}

/**
 * open_dest_file - Opens the destination file in write mode.
 * @dest_filename: The name of the destination file.
 *
 * Return: The file descriptor, or -1 on failure.
 */
int open_dest_file(const char *dest_filename)
{
	int fd_to = open(dest_filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", dest_filename);

	return (fd_to);
}

/**
 * close_file - Closes the file descriptor.
 * @fd: The file descriptor to close.
 */
void close_file(int fd)
{
	if (fd != -1 && close(fd) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
}

/**
 * read_and_write - Reads from source file and writes to destination file.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 *
 * Return: 0 on success, or -1 on failure.
 */
int read_and_write(int fd_from, int fd_to)
{
	ssize_t r, w;
	char buffer[BUF_SIZE];

	while ((r = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
			return (-1);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		return (-1);
	}

	return (0);
}
