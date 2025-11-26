/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:08:19 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/22 17:09:52 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);



void	*routine(void *philo)
{
	while (((t_philo *)philo)->rules->active)
	{
		if (((t_philo *)philo)->times_eaten == ((t_philo *)philo)->rules->max_eat_times)
			return (NULL);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	if (!philo->rules->active)
		return ;
	pthread_mutex_lock(&(philo->rules->forks[philo->forks[0]]));
	if (!philo->rules->active)
		return ;
	printf("%ld %d has taken a fork\n",
		get_time() - philo->rules->start_timestamp , philo->id + 1);
	pthread_mutex_lock(&(philo->rules->forks[philo->forks[1]]));
	if (philo->forks[1] != -1)
	{
		if (!philo->rules->active)
			return ;
		printf("%ld %d has taken a fork\n",
			get_time() - philo->rules->start_timestamp , philo->id + 1);
	}
	philo->last_meal_mark = get_time();
	printf("%ld %d is eating\n",
		(get_time() - philo->rules->start_timestamp) , philo->id + 1);
	philo->times_eaten++; // blockear com mutex
	usleep(1000 * philo->rules->ms_to_eat);
	pthread_mutex_unlock(&(philo->rules->forks[philo->forks[0]]));
	pthread_mutex_unlock(&(philo->rules->forks[philo->forks[1]]));
}

void	ft_sleep(t_philo *philo)
{
	if (!philo->rules->active)
		return ;
	printf("%ld %d is sleeping\n",
		get_time() - philo->rules->start_timestamp , philo->id + 1);
	usleep(1000 * philo->rules->ms_to_sleep);
}

void	ft_think(t_philo *philo)
{
	if (!philo->rules->active)
		return ;
	printf("%ld %d is thinking\n",
		get_time() - philo->rules->start_timestamp , philo->id + 1);
}
