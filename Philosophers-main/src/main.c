#include "../includes/Philosophers.h"


t_philo *init(t_philo *philo, t_philo *first, t_info *info)
{
    t_philo *new;

    new = malloc(sizeof(t_philo));

    new->id = info->index++;
    new->is_dead = 0;
    new->size = ft_atoi(info->av[1]);
    new->time_die = ft_atoi(info->av[2]);
    new->time_eat = ft_atoi(info->av[3]);
    new->time_sleep = ft_atoi(info->av[4]);
    new->last_eat = 0;
    pthread_mutex_init(&new->fork, NULL);
    
    if (info->ac == 6)
        new->number_eat = ft_atoi(info->av[5]);
    else
        new->number_eat = -1;
    if (philo)
        philo->next = new;
    else
        first = new;
    if (info->index - 1 == new->size)
    {
        new->next = first;
        return (first);
    }
    return (init(new, first, info));

}

void    *habit(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        ft_usleep(philo->time_eat, philo);
    while (1)
    {
        pthread_mutex_lock(&philo->fork);
        printf("%lu %d has taken a fork\n", ms(), philo->id);
        if (is_dead(philo))
            return (NULL);
        pthread_mutex_lock(&philo->next->fork);
        printf("%lu %d has taken a fork\n", ms(), philo->id);
        philo->last_eat = ms();
		printf("%lu %d is eating\n", ms(), philo->id);
		ft_usleep(philo->time_eat, philo);
		philo->number_eat--;
		if (!habit2(philo))
			return (NULL);
		if (is_dead(philo))
			return (NULL);
    }
    return (NULL);
}

int	habit2(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	if (philo->number_eat == 0)
		return (0);
	if (is_dead(philo))
		return (0);
	printf("%lu %d is sleeping\n", ms(), philo->id);
	if (!ft_usleep(philo->time_sleep, philo))
		return (0);
	if (is_dead(philo))
		return (0);
	printf("%lu %d is thinking\n", ms(), philo->id);
    return (1);
}

int main(int ac, char **av)
{
    t_philo *philo;
    t_info info;
    int i;

    philo = malloc(sizeof(t_philo));
    if (!parsing(ac, av, philo, &info))
    {
        printf("error\n");
         return (0);
    }
    philo = init(NULL, NULL, &info);
    i = 0;
    while (i < philo->size)
    {
        pthread_create(&philo->thread, NULL, &habit, philo);
        philo = philo->next;
    }
    i = 0;
    while (i < philo->size)
    {
        pthread_join(philo->thread, NULL);
		philo = philo->next;
    }
    while (--i)
	{
		pthread_detach(philo->thread);
		philo =philo->next;
	}
}