/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:37:22 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/22 18:03:20 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fatal(char *msg, t_program *prog)
{
	if (prog)
		cleanup_program(prog);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}


void	fatal_line(char *line, int line_no, t_program *prog)
{
	size_t	len;

	if (prog)
		cleanup_program(prog);
	ft_putstr_fd("Error\nParse error at line ", 2);
	ft_putnbr_fd(line_no, 2);
	ft_putstr_fd(":\n    ", 2);
	ft_putstr_fd(line, 2);
	len = ft_strlen(line);
	if (len == 0 || line[len - 1] != '\n')
		ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
