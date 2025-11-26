


#include "philosophers.h"

int	check_philo_starved(t_philo *philos);
int	check_all_philos_eaten(t_philo *philos);
int	check_is_active(t_rules *rules);

int	check_philo_starved(t_philo *philos)
{
    int		i;
    int		times_eaten;
    long	last_meal_mark;

    i = 0;
    while (i < philos->rules->n_philo)
    {
        pthread_mutex_lock(&(philos[i].edit_philo));
        times_eaten = philos[i].times_eaten;
        last_meal_mark = philos[i].last_meal_mark;
        pthread_mutex_unlock(&(philos[i].edit_philo));
        if (get_time() - last_meal_mark > philos->rules->ms_to_starve
        && times_eaten != philos->rules->max_eat_times)
        {
            pthread_mutex_lock(&(philos->rules->edit_rule));
            philos->rules->active = 0;
            usleep(500);
            pthread_mutex_unlock(&(philos->rules->edit_rule));
            printf("%-6ld %d died\n",
                get_time() - philos[i].rules->start_timestamp , philos[i].id + 1);
            return (1);
        }
        i++;
    }
    return (0);
}

int	check_all_philos_eaten(t_philo *philos)
{
    int	i;
    int	times_eaten;

    i = 0;
    while (i < philos->rules->n_philo)
    {
        pthread_mutex_lock(&(philos[i].edit_philo));
        times_eaten = philos[i].times_eaten;
        pthread_mutex_unlock(&(philos[i].edit_philo));
        if (times_eaten != philos->rules->max_eat_times)
            return (0);
        i++;
    }
    pthread_mutex_lock(&(philos->rules->edit_rule));
    philos->rules->active = 0;
    pthread_mutex_unlock(&(philos->rules->edit_rule));
    return (1);
}

int	check_is_active(t_rules *rules)
{
    int	active;

    pthread_mutex_lock(&(rules->edit_rule));
    active = rules->active;
    pthread_mutex_unlock(&(rules->edit_rule));
    return (active);
}
