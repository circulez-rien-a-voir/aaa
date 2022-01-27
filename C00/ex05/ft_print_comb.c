#include <unistd.h>

void	ft_write_comb (char first_digit, char second_digit, char last_digit)
{
	write(1, &first_digit, 1);
	write(1, &second_digit, 1);
	write(1, &last_digit, 1);
	write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int i;
	char comb[3];

	i = 12;

	while (i < 789)
	{	
		comb[1] =((i < 100) ? i / 10 : (i/10) % 10) + '0';
		comb[0] = i / 100 + '0';
		comb[2] = i % 10 + '0';

		if (	comb[0] != comb[1] && comb[0] != comb[2] &&	
				comb[1] != comb[2] && comb[0] < comb[1] &&
				comb[1] < comb[2] )
		{
			ft_write_comb(comb[0], comb[1], comb[2]);
		}
		i++;
	}
	write(1, "789", 3);
}
int main(void)
{
	ft_print_comb();
	return (0);
}
