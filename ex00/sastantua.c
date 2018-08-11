/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 12:29:57 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/11 16:56:55 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	sastantua(int size)
{
	int		floor;
	int		base;
	int		length;
	int		height;
	int		l;
	int		c;

	if (size > 0)
	{
		base = 3;
		height = base * size;
		floor = 0;
		while (++floor < size)
			height += floor;
		length = base + height * 2 + (size - 1) * 6;
		l = -1;
		floor = 0;
		while (++l < height)
		{
			c = -1;
			while (++c < length)
			{
				if (c < (length - base) / 2 || c >= (length - base) / 2 + base)
					ft_putchar(' ');
				else
					ft_putchar('*');
			}
			base += 2;
			ft_putchar('\n');
		}
	}
}

int		main(int argc, char *argv[])
{
	int i;

	i = argv[1] - 
	sastantua(argv[1]);
	return (0);
}
