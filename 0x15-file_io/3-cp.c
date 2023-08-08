#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int open_source_file(const char *src_filename);
int open_dest_file(const char *dest_filename);
void close_file(int fd);
int read_and_write(int fd_from, int fd_to);
int copy_file(const char *src_filename, const char *dest_filename);

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

int open_source_file(const char *src_filename)
{
	int fd_from = open(src_filename, O_RDONLY);

	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src_filename);

	return (fd_from);
}

int open_dest_file(const char *dest_filename)
{
	int fd_to = open(dest_filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", dest_filename);

	return (fd_to);
}

void close_file(int fd)
{
	if (fd != -1 && close(fd) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
}

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
