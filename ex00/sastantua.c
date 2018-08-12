/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 12:29:57 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/12 02:53:15 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		i;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

void	ft_define_var(int size, int *var)
{
	var[7] = size;
	if (var[7] % 2 == 0)
		var[7] -= 1;
	var[5] = 3;
	var[4] = 3;
	var[3] = var[4] - 1;
	var[1] = var[5] * size;
	var[2] = 0;
	var[6] = 0;
	while (++var[2] < size)
	{
		var[1] += var[2];
		var[6] += ((var[2] - 1) / 2) * 2;
	}
	var[0] = var[5] + (var[1] - 1) * 2 + (size - 1) * 4 + var[6];
	var[2] = 0;
}

void	ft_write_line(int c, int l, int *var)
{
	while (++c < var[0])
	{
		if (c < (var[0] - var[5]) / 2)
			ft_putchar(' ');
		else if (c >= (var[0] - var[5]) / 2 + var[5])
			break ;
		else if (c == (var[0] - var[5]) / 2)
			ft_putchar('/');
		else if (c == (var[0] - var[5]) / 2 + var[5] - 1)
			ft_putchar('\\');
		else if (l == var[1] - var[7] / 2 - 1 &&
				c == var[0] / 2 + var[7] / 2 - 1 &&
				var[7] / 2 > 0 &&
				c != var[0] / 2)
			ft_putchar('$');
		else if (c >= var[0] / 2 - var[7] / 2 &&
				c <= var[0] / 2 + var[7] / 2 &&
				l >= var[1] - var[7] &&
				l <= var[1])
			ft_putchar('|');
		else
			ft_putchar('*');
	}
}

/*
** index definition for var[]
** var[0] : length of the longest line (count in characters)
** var[1] : height of the pyramid (count in lines)
** var[2] : index of the current floor
** var[3] : index of the line inside the current floor
** var[4] : height of the current floor (count in lines)
** var[5] : length of the current line (count in characters that are not ' ')
** var[6] : count incremental characters (count in characters)
** var[7] : size of the door (count in characters == in lines)
*/

void	sastantua(int size)
{
	int		l;
	int		c;
	int		var[8];

	if (size > 0)
	{
		ft_define_var(size, var);
		l = -1;
		while (++l < var[1])
		{
			c = -1;
			ft_write_line(c, l, var);
			if (var[3] == 0)
			{
				var[2]++;
				var[4] = var[4] + 1;
				var[3] = var[4] - 1;
				var[5] += 4 + ((var[2] - 1) / 2) * 2;
			}
			else
				var[3]--;
			var[5] += 2;
			ft_putchar('\n');
		}
	}
}

int		main(int argc, char *argv[])
{
	int i;

	if (argc == 2)
	{
		i = ft_atoi(argv[1]);
		sastantua(i);
	}
	return (0);
}
