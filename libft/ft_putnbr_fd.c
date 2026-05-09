/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:47:26 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/06 19:57:56 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n2;
	char		s;

	n2 = (long)n;
	if (n2 < 0)
	{
		n2 *= -1;
		write(fd, "-", 1);
	}
	if (n2 / 10 != 0)
		ft_putnbr_fd(n2 / 10, fd);
	s = n2 % 10 + 48;
	write(fd, &s, sizeof(char));
	return ;
}
