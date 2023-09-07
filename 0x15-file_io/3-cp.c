#include "main.h"

/**
 * main - Copies the contents of a file into another file.
 * @argc: Number of arguments passed.
 * @argv: Argument vector arry.
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	int src_fd, dest_fd, bytes_read;
	char buffer[1024];

	/* Check for the correct number of command-line arguments */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Open the source file for reading */
	src_fd = open(argv[1], O_RDONLY);
	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]);
		exit(98);
	}

	/* Open or create the destination file for writing */
	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	/* Copy data from source to destination */
	while ((bytes_read = read(src_fd, buffer, 1024)) > 0)
	{
		if (dest_fd < 0 || (write(dest_fd, buffer, bytes_read) != bytes_read))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]);
		exit(98);
	}

	/* Close the source and destination file descriptors */
	if (close(src_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd);
		exit(100);
	}

	if (close(dest_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		exit(100);
	}

	return (0);
}

