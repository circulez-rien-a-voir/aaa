#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putnbr(int nbr)
{
    if (nbr < 0)
    {
        ft_putchar('-');
        ft_putnbr(-nbr);
    }
    else if (nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
    else
    {
        ft_putchar(nbr + '0');
    }
}


unsigned long ten_power(int n){
	unsigned long result;	
	int i;

	i = 0;	
	result = 1;	

	while (i < n)
	{
		result *= 10;
		i++;
	}
	return (result);
}

int is_comb_valid(unsigned long nb)
{
	char used[10];
	int latest_digit;
	int i;
	
	i = 0;
	latest_digit = nb % 10;
		
	while(i <= 10)
	{
		used[i] = 0;
		i++;
	}
	while(nb > 0)
	{
		if (used[nb % 10]) return(0);
		used[nb % 10] = 1;
		nb /= 10;
		if (nb % 10 > latest_digit)
		{
			return(0);
		}
		latest_digit = nb % 10;
	}
	return(1);
}

int is_last_comb(unsigned long nb, int n)
{
	int i;
	int total;

	i = 0;
	total = 0;
	
	while(i < n)
	{
		total += nb %10;
		nb /= 10;
		i++;
	}

	/*	We use the fact that sum of 1+2+3+....+n == ((n)(n-1)) / 2
		The sum of the last combination will always be == n + n+1 + ... + 9 */

	if(total == (9 * n - ((n-1) * n)/2))
	{
		return (1);
	}
	return (0);

}

void ft_print_combn(int n)
{
	char comb[n];
	unsigned long i;
	int last;

	last = 0;	
	i = 1;

	while(i < ten_power(n))
	{
		if(	is_comb_valid(i) &&
			i > ten_power(n-2))
		{
			if(i < ten_power(n-1))
			{
				ft_putchar('0');
			}
			ft_putnbr(i);
			if(!is_last_comb(i, n))
			{
			ft_putchar(',');
			ft_putchar(' ');
			}
		}
		i++;	
	}
}

int main(void)
{
	ft_print_combn(5);
	return(0);
}
