
#include "philosophers.h"

t_philo			*init_philos(t_rules *rules);
static t_philo	new_philo(int id, t_rules *rules);


t_philo	*init_philos(t_rules *rules)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc((rules->n_philo) * sizeof(t_philo));
	if (!philos)
		return (NULL);
	while (i < rules->n_philo)
	{
		philos[i] = new_philo(i, rules);
		i++;
	}
	return (philos);
}

static t_philo	new_philo(int id, t_rules *rules)
{
	t_philo	philo;

	philo.id = id;
	philo.times_eaten = 0;
	philo.rules = rules;
	philo.forks[0] = id;
	if (rules->n_philo == 1)
		philo.forks[1] = -1;
	else if (id + 1 < rules->n_philo && id % 2 == 0)
		philo.forks[1] = id + 1;
	else if (id + 1 < rules->n_philo&& id % 2 == 1)
	{
		philo.forks[0] = id + 1;
		philo.forks[1] = id;
	}
	else if (id % 2 == 0)
		philo.forks[1] = 0;
	else
	{
		philo.forks[0] = 0;
		philo.forks[1] = id;
	}
	philo.last_meal_mark = get_time();
	pthread_mutex_init(&(philo.edit_philo), NULL);
	return (philo);
}
