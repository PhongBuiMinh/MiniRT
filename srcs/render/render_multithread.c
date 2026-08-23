/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_multithread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:30:01 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/23 16:03:21 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*render_rows(void *arg)
{
	t_render_job	*job;
	t_ray			ray;
	t_tuple			color;
	int				y;
	int				x;

	job = arg;
	y = job->start_y;
	while (y < job->end_y)
	{
		x = 0;
		while (x < job->camera->h_size)
		{
			ray = ray_for_pixel(job->camera, x, y);
			color = color_at(job->world, ray, &job->error);
			write_pixel(job->canvas, x, y, color);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	init_jobs(t_render_job *jobs, t_canvas *canvas,
		t_camera *camera, t_world *world)
{
	int	threads_count;
	int	rows_per_thread;
	int	i;

	threads_count = sysconf(_SC_NPROCESSORS_ONLN);
	rows_per_thread = (camera->v_size + threads_count - 1)
		/ threads_count;
	i = 0;
	while (i < threads_count)
	{
		jobs[i].canvas = canvas;
		jobs[i].camera = camera;
		jobs[i].world = world;
		jobs[i].start_y = i * rows_per_thread;
		jobs[i].end_y = min((i + 1) * rows_per_thread, camera->v_size);
		jobs[i].error = false;
		i++;
	}
}

void	join_threads(pthread_t *threads, t_render_job *jobs,
		int threads_count, bool *error)
{
	int	i;

	i = 0;
	while (i < threads_count)
	{
		if (pthread_join(threads[i], NULL) != 0)
			*error = true;
		if (jobs[i].error)
			*error = true;
		i++;
	}
}

void	start_threads(pthread_t *threads, t_render_job *jobs,
		int threads_count, bool *error)
{
	int	i;

	i = 0;
	while (i < threads_count)
	{
		if (pthread_create(&threads[i], NULL, render_rows, &jobs[i]) != 0)
		{
			*error = true;
			join_threads(threads, jobs, i, error);
			return ;
		}
		i++;
	}
}

void	render_multithread(t_canvas *canvas, t_camera *camera,
		t_world *world, bool *error)
{
	t_render_job	*jobs;
	pthread_t		*threads;
	int				threads_count;

	threads_count = sysconf(_SC_NPROCESSORS_ONLN);
	threads = malloc(sizeof(pthread_t) * threads_count);
	jobs = malloc(sizeof(t_render_job) * threads_count);
	if (!threads || !jobs)
		return (free(threads), free(jobs));
	init_jobs(jobs, canvas, camera, world);
	start_threads(threads, jobs, threads_count, error);
	if (*error)
		return ;
	join_threads(threads, jobs, threads_count, error);
}
