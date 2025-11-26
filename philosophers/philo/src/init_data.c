/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:12:48 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/22 17:03:12 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_rules			*init_data(int argc, char **args);
static int		init_forks(t_rules *rules);
void			free_data(t_rules *rules);

t_rules	*init_data(int argc, char **args)
{
	t_rules	*data;

	data = malloc(sizeof(t_rules));
	if (!data)
		return (NULL);
	data->n_philo = ft_atoi(*(args++));
	data->ms_to_starve = ft_atoi(*(args++));
	data->ms_to_eat = ft_atoi(*(args++));
	data->ms_to_sleep = ft_atoi(*(args++));
	data->max_eat_times = -1;
	if (argc == 6)
		data->max_eat_times = ft_atoi(*(args));
	if (data->n_philo < 1 || data->ms_to_starve < 1
		|| data->ms_to_eat < 1 || data->ms_to_sleep < 1
		|| (argc == 6 && data->max_eat_times < 1))
		return (free(data), NULL);
	data->active = 1;
	pthread_mutex_init(&data->edit_rule, NULL);
	data->start_timestamp = get_time();
	if (init_forks(data))
		return (data);
	return (free(data), NULL);
}

static int	init_forks(t_rules *rules)
{
	int	i;

	i = 0;
	rules->forks = malloc(rules->n_philo * sizeof (pthread_mutex_t));
	if (!rules->forks)
		return (0);
	while (i < rules->n_philo)
	{
		pthread_mutex_init(&(*rules).forks[i], NULL);
		i++;
	}
	return (1);
}

void	free_data(t_rules *rules)
{
	// int	i;
	
	// i = 0;
	// if (rules->n_philo == 1)
	// 	pthread_mutex_unlock(&rules->forks[0])
	// 	pthread_mutex_destroy(&rules->forks[0]);
	// else
	// {
	// 	while (i < rules->n_philo)
	// 		pthread_mutex_destroy(&rules->forks[i++]);
	// }
	free(rules->forks);
	free(rules);
}
