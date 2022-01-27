#include <unistd.h>

void	ft_is_negative(int n)
{
	write(1, n < 0 ? "N" : "P", 1);
}

int		main(void)
{
	ft_is_negative(1);
	ft_is_negative(-1000);
	ft_is_negative(0);
	return (0);
}
