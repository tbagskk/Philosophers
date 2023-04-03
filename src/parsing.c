#include "../includes/Philosophers.h"


int estChiffres(char *tab) 
{
    int i;

    i = 0;
    while(tab[i] != '\0') 
    {
        if(tab[i] < '0' || tab[i] > '9') 
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int parsing_chiffre(char **av)
{
    if (!(estChiffres(av[1])))
            return (0);
    if (!(estChiffres(av[2])))
            return (0);
    if (!(estChiffres(av[3])))
            return (0);
    if (!(estChiffres(av[4])))
            return (0);
    if (!(estChiffres(av[5])))
            return (0);
    return (1);
}

int parsing(int ac, char **av, t_philo *philo)
{
    int i;

    i = 0;
    if (ac == 6)
    {
        if (!(parsing_chiffre(av)))
            return (0);
        philo->nb_philo = ft_atoi(av[1]);
        philo->time_die = ft_atoi(av[2]);
        philo->time_eat = ft_atoi(av[3]);
        philo->time_sleep = ft_atoi(av[4]);
        philo->nb_must_eat = ft_atoi(av[5]);
        return (1);
    }
    return (0);
}