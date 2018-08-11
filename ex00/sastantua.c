/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 12:29:57 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/12 01:34:13 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

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

void	sastantua(int size)
{
	int		floor;
	int		base;
	int		length;
	int		height;
	int		l;
	int		c;
	int		i_floor;
	int		floor_height;
	int		incremental_length;
	int		door_size;

	if (size > 0)
	{
		door_size = size;
		if (door_size % 2 == 0)
			door_size -= 1;
		base = 3;
		floor_height = 3;
		i_floor = floor_height - 1;
		height = base * size;
		floor = 0;
		incremental_length = 0;
		while (++floor < size)
		{
			height += floor;
			incremental_length += ((floor - 1) / 2) * 2;
		}
		length = base + (height - 1) * 2 + (size - 1) * 4 + incremental_length;
		l = -1;
		floor = 0;
		while (++l < height)
		{
			c = -1;
			while (++c < length)
			{
				if (c < (length - base) / 2)
					ft_putchar(' ');
				else if (c >= (length - base) / 2 + base)
					break ;
				else if (c == (length - base) / 2)
					ft_putchar('/');
				else if (c == (length - base) / 2 + base - 1)
					ft_putchar('\\');
				else if (l == height - door_size / 2 - 1 &&
						c == length / 2 + door_size / 2 - 1 &&
						door_size / 2 > 0 &&
						c != length / 2)
					ft_putchar('$');
				else if (c >= length / 2 - door_size / 2 &&
						c <= length / 2 + door_size / 2 &&
						l >= height - door_size &&
						l <= height)
					ft_putchar('|');
				else
					ft_putchar('*');
			}
			if (i_floor == 0)
			{
				floor++;
				floor_height = floor_height + 1;
				i_floor = floor_height - 1;
				base += 4 + ((floor - 1) / 2) * 2;
			}
			else
				i_floor--;
			base += 2;
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
