/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:07:14 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:09:11 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "matrices.h"
# include "light.h"

typedef struct s_sphere
{
	t_matrix	transformation;
	t_material	material;
	int			id;
}	t_sphere;

t_sphere	sphere(int id);
void		set_transformation(t_sphere *sphere, t_matrix transformation);

#endif