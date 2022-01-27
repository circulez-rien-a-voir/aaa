#include <unistd.h>

void	test(void)
{
	char a;
	char b;
	char comp[2];

	a = '9';
	b = '3';
	comp[0] = a;
	comp[1] = b;

	write (1, &comp, 2);
	
}

int		main(void)
{
	test();
	return(0);
}
