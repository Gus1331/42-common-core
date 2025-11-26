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

void		*routine(void *philo);
static void	ft_eat(t_philo *philo);
static void	ft_sleep(t_philo *philo);
static int	ft_grab_forks(t_philo *philo);
static void	ft_wait_task(int ms, t_rules *rules);

void	*routine(void *philo)
{
	t_philo	*philo_cast;

	philo_cast = ((t_philo *)philo);
	usleep(1000 * (philo_cast->id % 5));
	while (check_is_active(philo_cast->rules))
	{
		pthread_mutex_lock(&(philo_cast->edit_philo));
		if (philo_cast->times_eaten == philo_cast->rules->max_eat_times)
			return (pthread_mutex_unlock(&(philo_cast->edit_philo)), NULL);
		pthread_mutex_unlock(&(philo_cast->edit_philo));
		ft_eat(philo);
		ft_sleep(philo);
		if (check_is_active(philo_cast->rules))
			printf("%-6ld %d is thinking\n", get_time()
				- philo_cast->rules->start_timestamp , philo_cast->id + 1);
	}
	return (NULL);
}

static void	ft_eat(t_philo *philo)
{
	if (ft_grab_forks(philo) == -1)
	{
		usleep(philo->rules->ms_to_starve * 1000);
		return ;
	}
	pthread_mutex_lock(&(philo->edit_philo));
	philo->last_meal_mark = get_time();
	philo->times_eaten++;
	pthread_mutex_unlock(&(philo->edit_philo));
	printf("%-6ld %d is eating\n",
		(get_time() - philo->rules->start_timestamp) , philo->id + 1);
	ft_wait_task(philo->rules->ms_to_eat, philo->rules);
	pthread_mutex_unlock(&(philo->rules->forks[philo->forks[0]]));
	pthread_mutex_unlock(&(philo->rules->forks[philo->forks[1]]));
}

static void	ft_sleep(t_philo *philo)
{
	if (!check_is_active(philo->rules))
		return ;
	printf("%-6ld %d is sleeping\n",
		get_time() - philo->rules->start_timestamp , philo->id + 1);
	ft_wait_task(philo->rules->ms_to_sleep, philo->rules);
}

static int	ft_grab_forks(t_philo *philo)
{
	if (philo->forks[1] == -1)
	{
		printf("%-6ld %d has taken a fork\n",
			get_time() - philo->rules->start_timestamp , philo->id + 1);
		return (-1);
	}
	if (!check_is_active(philo->rules))
		return (-1);
	pthread_mutex_lock(&(philo->rules->forks[philo->forks[0]]));
	if (!check_is_active(philo->rules))
	{
		pthread_mutex_unlock(&(philo->rules->forks[philo->forks[0]]));
		return (-1);
	}
	printf("%-6ld %d has taken a fork\n",
		get_time() - philo->rules->start_timestamp , philo->id + 1);
	pthread_mutex_lock(&(philo->rules->forks[philo->forks[1]]));
	if (!check_is_active(philo->rules))
	{
		pthread_mutex_unlock(&(philo->rules->forks[philo->forks[0]]));
		pthread_mutex_unlock(&(philo->rules->forks[philo->forks[1]]));
		return (-1);
	}
	printf("%-6ld %d has taken a fork\n",
		get_time() - philo->rules->start_timestamp , philo->id + 1);
	return (1);
}

static void	ft_wait_task(int ms, t_rules *rules)
{
	long	start;

	start = get_time();
	while (check_is_active(rules) && get_time() - start < ms)
		usleep(500);
}
