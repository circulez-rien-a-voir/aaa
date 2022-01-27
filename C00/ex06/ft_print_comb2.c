#include <unistd.h>

void ft_format_comb2(char comb[5], int i, int j)
{
	int x;
	
	x = 0;

	while(x < 5)
	{
		write(1, &comb[x], 1);
		x++;
	}
	if(i - j == 1 && i + j == 197)
	{
	}
	else
	{
		write(1, ", ", 2);
	}
}


void ft_print_comb2(void)
{
	char comb[5];
	int i;
	int j;
	
	i = 0;
	j = 0;
	comb[2] = ' ';

	while(i < 100)
	{	
		comb[0] = i / 10 + '0';
		comb[1] = i % 10 + '0';
		while(j < 100)
		{
			comb[3] = j / 10 + '0';
			comb[4] = j % 10 + '0';
			if ( i != j)
			{
				ft_format_comb2(comb, i, j);
			}
			j++;	
		}
		i++;
		j = 0;
	}
}

int main(void)
{
	ft_print_comb2();
}
