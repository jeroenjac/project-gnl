#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 10

int		main(void)
{
	int		fd;
	char	buf[BUFSIZE + 1];
	char	*file = "textfile.txt";
	ssize_t	rd;

	//Part 1
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);	//error
	rd = 1;
	while (rd > 0)
	{
		bzero(buf, BUFSIZE + 1);
		rd = read(fd, buf, BUFSIZE);
		write(1, buf, BUFSIZE);
	}
	close (fd);
	
	//Part 2
	fd = open(file, O_WRONLY | O_APPEND);
	write(fd, "extra", 5);
	close(fd);

	return (0);
}
