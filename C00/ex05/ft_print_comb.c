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
	char first_digit;
	char second_digit;
	char last_digit;

	i = 10;

	while (i < 789)
	{	
		if (i < 100)
		{
			second_digit = i / 10 + '0';
		}
		else
		{
			second_digit = (i / 10) % 10 + '0'; 
		}
		first_digit = i / 100 + '0';
		last_digit = i % 10 + '0';

		if (	first_digit != second_digit && first_digit != last_digit &&	
				second_digit != last_digit && first_digit < second_digit &&
				second_digit < last_digit )
		{
			ft_write_comb(first_digit, second_digit, last_digit);
		}
		i++;
	}
	write(1, "789", 4);
}
int main(void)
{
	ft_print_comb();
	return (0);
}
