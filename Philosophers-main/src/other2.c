#include "../includes/Philosophers.h"

long	ms(void)
{
	static unsigned long	start = 0;
	struct timeval			a;

	gettimeofday(&a, NULL);
	if (!start)
		start = a.tv_sec * 1000 + a.tv_usec / 1000;
	return ((a.tv_sec * 1000 + a.tv_usec / 1000) - start);
}

int	ft_usleep(long int time_in_ms, t_philo *philo)
{
	long int	start_time;

	start_time = ms();
	while ((ms() - start_time) < time_in_ms)
	{
		if (is_dead(philo))
			return (0);
		usleep(10);
	}
	return (1);
}

int	is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->size == 1)
	{
		philo->size = 0;
		ft_usleep(philo->time_die, philo);
		printf("%lu %d has died\n", ms(), philo->id);
		return (1);
	}
	while (i++ < philo->size)
	{
		if (philo->is_dead == 1)
			return (1);
		philo = philo->next;
	}
	if (philo->time_die < ms() - philo->last_eat)
	{
		philo->is_dead = 1;
		printf("%lu %d has died\n", ms(), philo->id);
		return (1);
	}
	return (0);
}