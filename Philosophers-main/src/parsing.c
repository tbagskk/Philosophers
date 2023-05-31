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
    return (1);
}

int parsing(int ac, char **av, t_philo *philo, t_info *info)
{
    int i;
    int value;

    i = 1;
    if (ac < 5 || ac > 6)
        return (0);
    if (!(parsing_chiffre(av)))
          return (0);
    while (i < 5)
    {
        value = ft_atoi(av[i]);
        if (value <= 0 || value > INT_MAX || !ft_point(av[i]))
            return (0);
        i++;
    }
    if (ac == 6 && ((ft_atoi(av[5]) <= 0) || !ft_point(av[5])))
        return (0);
    info->ac = ac;
    info->av = av;
    info->index = 1;
    return (1);
}