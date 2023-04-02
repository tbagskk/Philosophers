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
}              t_philo;

int parsing(int ac, char **av, t_philo *philo);
int ft_atoi(const char *str);

#endif