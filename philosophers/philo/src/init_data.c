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

t_rules	*init_data(int argc, char **args);
t_philo	*init_philos(t_rules rules);
t_philo	new_philo(int id, t_rules rules);

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
	{
		free(data);
		return (NULL);
	}
	data->active = 1;
	return (data);
}

t_philo	*init_philos(t_rules rules)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc((rules.n_philo) * sizeof(t_philo));
	while (i < rules.n_philo)
	{
		philos[i] = new_philo(i + 1, rules);
		i++;
	}
	return (philos);
}

t_philo	new_philo(int id, t_rules rules)
{
	t_philo	philo;

	philo.id = id;
	philo.times_eaten = 0;
	philo.rules = rules;
	return (philo);
}
