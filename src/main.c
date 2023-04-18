#include "../includes/Philosophers.h"



int main(int ac, char **av)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo));

    init(av, philo);
    jsp();
    /*
    if (parsing(ac, av, philo) == 1)
        ft_putstr("le parsing est good\n");
    else
        ft_putstr("error\n");*/

    return(0);
}