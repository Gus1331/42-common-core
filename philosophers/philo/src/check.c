


#include "philosophers.h"

int check_philo_starved(t_philo *philos);
int check_all_philos_eaten(t_philo *philos);

int check_philo_starved(t_philo *philos)
{
    int i;

    i = 0;
    while (i < philos->rules->n_philo)
    {
        if (get_time() - philos[i].last_meal_mark > philos->rules->ms_to_starve
            && philos[i].times_eaten != philos->rules->max_eat_times)
        {
            pthread_mutex_lock(&(philos->rules->edit_rule));
	        philos->rules->active = 0;
            printf("%ld %d died\n",
                get_time() - philos[i].rules->start_timestamp , philos[i].id + 1);
            pthread_mutex_unlock(&(philos->rules->edit_rule));
            return (1);
        }
        i++;
    }
    return (0);
}

int check_all_philos_eaten(t_philo *philos)
{
        int i;

    i = 0;
    while (i < philos->rules->n_philo)
    {
        if ( philos[i].times_eaten != philos->rules->max_eat_times)
            return (0);
        i++;
    }
    return (1);
}