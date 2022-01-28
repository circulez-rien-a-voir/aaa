#include <unistd.h>

int length_of_int(int nb)
{
	int length;
	
	length = 0;

	if(nb < 0)	
	{
		nb *= -1;
	}
	while(nb)
	{
		nb /= 10;
		length++;
	}
	length += '0';
	write(1, "length: ", 8);
	write(1, &length, 1);
	write(1, "   ", 3);
	return (length);
}

void ft_putnbr(int nb)
{
	int length;
	char temp_char;
	int temp_int;
	int i;
	//int j;
	
	length = length_of_int(nb);
	//length = 4;
	//j = length;

	while (length > 0)
	{
		i = length - 1;
		temp_int = nb;
		
		while ( i > 0)
		{	
			//write(1, " i= ", 4);
			//write(1, &i, 1);
			//write(1, ", ", 2);
			temp_int /= 10;	
			i--;
		} 
		temp_char = temp_int % 10 + '0'; 
		write(1, &temp_char, 1);
		length--;
	}
}

int main(void)
{
	ft_putnbr(1234);
}
