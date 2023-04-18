#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>


typedef struct s_philo
{
    int nb_philo;
    int time_die;
    int time_eat;
    int time_sleep;
    int nb_must_eat;
    pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			eat;
	pthread_mutex_t			finish;
    pthread_t       thread_id;

    pthread_mutex_t mutex;
}              t_philo;

int parsing(int ac, char **av, t_philo *philo);
int ft_atoi(const char *str);
void	ft_putstr(char *str);

void	*thread_routine(void *data);
int jsp(); 
void init();

#endif