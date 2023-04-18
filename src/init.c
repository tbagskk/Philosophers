#include "../includes/Philosophers.h"

void init(char **av, t_philo *philo)
{
	philo->nb_philo = ft_atoi(av[0]);
	philo->time_die = ft_atoi(av[1]);
	philo->time_eat = ft_atoi(av[2]);
	philo->time_sleep = ft_atoi(av[3]);
	philo->nb_must_eat = ft_atoi(av[4]);
	
}

void init_mutex(t_philo *philo)
{
	pthread_mutex_init(&philo->write_mutex, NULL);
	pthread_mutex_init(&philo->dead, NULL);
	pthread_mutex_init(&philo->eat, NULL);
	pthread_mutex_init(&philo->finish, NULL);
}

void *hey()
{
	printf("hey");
	return(NULL);
}

int launch(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_create(&philo->thread_id, NULL, hey, &philo);
		i++;
	}
	return(1);
}