#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

# define NC	"\e[0m"
# define YELLOW	"\e[1;33m"

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
void	ft_putstr(char *str);

void	*thread_routine(void *data);
void jsp();

#endif