#include "../includes/Philosophers.h"

void init(char **av, t_philo *philo)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->time_die = ft_atoi(av[2]);
	philo->time_eat = ft_atoi(av[3]);
	philo->time_sleep = ft_atoi(av[4]);
	philo->nb_must_eat = ft_atoi(av[5]);
	
}

void init_mutex(t_philo *philo)
{
	pthread_mutex_init(&philo->write_mutex, NULL);
	pthread_mutex_init(&philo->dead, NULL);
	pthread_mutex_init(&philo->eat, NULL);
	pthread_mutex_init(&philo->finish, NULL);
	pthread_mutex_init(&philo->fourchette, NULL);

}
int j = 0;

void *hey(void  *arg)
{
	t_philo *philo = arg;
	pthread_mutex_lock(&philo->fourchette);
	printf("a pris une fourchette");
	j++;
	pthread_mutex_unlock(&philo->eat);
//	printf("%d\n", j);
	
	return(NULL);
}

int launch(t_philo *philo)
{
	int	i;
	i = 0;
	init_mutex(philo);
	while (i < philo->nb_philo)
	{
		pthread_create(&philo->thread_id, NULL, hey, &philo);
		printf("%lu\n",(unsigned long)philo->thread_id);
		pthread_join(philo->thread_id, NULL);
		
		i++;
	}
	return(1);
}