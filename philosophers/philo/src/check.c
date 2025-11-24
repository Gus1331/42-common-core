


#include "philosophers.h"

int check_philo_starved(t_philo *philos)
{
    int i;

    i = 0;
    while (i < philos->rules.n_philo)
    {
        if (philos[i].last_meal_mark - get_time() > philos->rules.ms_to_starve
            && philos[i].times_eaten != philos->rules.max_eat_times)
            return (1);
        i++;
    }
    return (0);
}

int check_all_philos_eaten(t_philo *philos)
{
        int i;

    i = 0;
    while (i < philos->rules.n_philo)
    {
        if ( philos[i].times_eaten != philos->rules.max_eat_times)
            return (0);
        i++;
    }
    return (1);
}