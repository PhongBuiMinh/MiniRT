/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:01:03 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/08 15:03:38 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define BLUE  "\033[34m"
#define RESET "\033[0m"

typedef struct s_test
{
	char	*name;
	int		(*fn)(void);
}	t_test;