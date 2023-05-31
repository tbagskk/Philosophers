#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <limits.h>

typedef struct s_info
{
    int ac;
    char **av;
    int index;
}   t_info;


typedef struct s_philo
{
    int time_die;
    int time_eat;
    int time_sleep;
    int last_eat;

    pthread_t thread;
    pthread_mutex_t fork;
    int id;
    int number_eat;
    int is_dead;
    int size;
    struct s_philo *next;

}              t_philo;

int parsing(int ac, char **av, t_philo *philo, t_info *info);
int ft_atoi(const char *str);
void	ft_putstr(char *str);
int	ft_point(const char *str);

void	*thread_routine(void *data);
int	habit2(t_philo *philo);
void    *habit(void *arg);

int	is_dead(t_philo *philo);
int	ft_usleep(long int time_in_ms, t_philo *philo);
long	ms(void);
void jsp();

#endif