/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:54:58 by fbui-min          #+#    #+#             */
/*   Updated: 2026/06/05 19:55:03 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	material_default(void)
{
	t_material m;

	m.color = color(1.0, 1.0, 1.0);
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}
