#include "../includes/Philosophers.h"

int main(int ac, char **av)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo));

    if (parsing(ac, av, philo) == 1)
        printf("le parsing est good\n");
    else
        printf("le parsing est faux\n");

    return(0);
}