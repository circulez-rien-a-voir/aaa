#include <unistd.h>

int length_of_int(int nb)
{
	int length;
	
	length = 0;

	if(nb < 0)	
	{
		nb *= -1;
	}
	else if(nb == 0)
	{
		return (1);
	}
	while(nb)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

int is_negative(int nb)
{
	int negative;
	
	negative = 0;
	if (nb < 0)
	{
		negative = 1;		
	}
	return (negative);
}

int abs_value(int nb)
{
	if (nb < 0)
	{
		return (nb * -1);		
	}
	else
	{
		return (nb);	
	}
}

void ft_putnbr(int nb)
{
	int length;
	char temp_char;
	long temp_int;
	int i;
	 	
	length = length_of_int(nb);
	
	write(1, is_negative(nb) ? "-" : "", 1);
	while (length > 0)
	{
		i = length - 1;
		temp_int = abs_value(nb) ;	

		while ( i > 0)
		{	
			temp_int /= 10;	
			i--;
		} 
		temp_char = temp_int  % 10 + '0'; 
		write(1, &temp_char, 1);
		length--;
	}
}

int main(void)
{
	ft_putnbr(123456);
	write(1, "\n",2);
	ft_putnbr(42);
	write(1, "\n",2);
	ft_putnbr(-1);
	write(1, "\n",2);
	ft_putnbr(0);
	write(1, "\n",2);
	ft_putnbr(-32767);
	write(1, "\n",2);
	ft_putnbr(32767);
	return (0);	
}
