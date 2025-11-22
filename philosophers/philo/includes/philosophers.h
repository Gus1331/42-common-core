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

typedef struct s_rules {
	int		n_philo;
	int		ms_to_starve;
	int		ms_to_eat;
	int		ms_to_sleep;
	int		max_eat_times;
	int		active;
}	t_rules;

typedef struct s_philo {
	int			id;
	pthread_t	thread;
	t_rules		rules;
	int			first_fork;
	int			second_fork;
	int			times_eaten;
}	t_philo;

/* Helpers */
int		ft_atoi(const char *nptr);

/* Data management */
t_rules	*init_data(int argc, char **args);

#endif
