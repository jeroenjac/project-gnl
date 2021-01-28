#include <stdio.h>

void fun(void)
{
	static int x = 0;	// need to initialize variable here to have 'static' behavior

	x = 0;			// this does not 'work'
	x++;
	printf("var = %i\n", x);
}

int	main(void)
{
	fun();
	fun();
	fun();
	return (0);
}
