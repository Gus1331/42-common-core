/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:32:17 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/22 17:02:38 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
#include <sys/time.h>

typedef struct s_rules {
	int				n_philo;
	int				ms_to_starve;
	int				ms_to_eat;
	int				ms_to_sleep;
	int				max_eat_times;
	int				active;
	long			start_timestamp;
	pthread_mutex_t	*forks;
	pthread_mutex_t	edit_rule;
}	t_rules;

typedef struct s_philo {
	int				id;
	pthread_t		thread;
	pthread_mutex_t	edit_philo;
	t_rules			*rules;
	int				forks[2];
	int				times_eaten;
	long			last_meal_mark;
}	t_philo;

/* Helpers */
int		ft_atoi(const char *nptr);
long	get_time(void);

/* Data management */
t_rules	*init_data(int argc, char **args);
t_philo	*init_philos(t_rules *rules);
void	free_data(t_rules *rules);

/* Check */
int		check_philo_starved(t_philo *philos);
int		check_all_philos_eaten(t_philo *philos);
int		check_is_active(t_rules *rules);

/* Routine */
void	*routine(void *philo);

#endif
