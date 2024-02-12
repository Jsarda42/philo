#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
/*this is the structure for for the forks
we need the mtx and a fork id
what is mtx : ?
*/

# define RST "\033[0m"    /* Reset to default color */
# define RED "\033[1;31m" /* Bold Red */
# define G "\033[1;32m"   /* Bold Green */
# define Y "\033[1;33m"   /* Bold Yellow */
# define B "\033[1;34m"   /* Bold Blue */
# define M "\033[1;35m"   /* Bold Magenta */
# define C "\033[1;36m"   /* Bold Cyan */
# define W "\033[1;37m"   /* Bold White */

typedef enum e_bool
{
	false,
	true
}		t_bool;

typedef struct s_fork
{
	// fork
	// fork id
}		t_fork;

/*this is the structure for the philo
we need to have an id for each philo , we have to keep track on the meal counter
what is the meal counter ?
a boolean to tell when the philo is full or not
we need to keep track on the time last meal was , for each philo ?
need to get a the right and left fork
an id for the ptrhead what is it ?
need to get the table struc */
typedef struct s_philo
{
	// philo id
	// meal counter
	// full
	// last meal for the time passed from last meal
	// left fork
	// right fork
	// thread id
	// table struc
}		t_philo;

/*need to know how many philo are at the table , how long before dying ,
	eat and sleep
the optional number limit of meals the start of the simulation and the end (boolean)
keep the forks struc
and the philo struct*/
typedef struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_meal;
	// number limit of meals (optional)
	// start of simulation
	// end of similation (philo die) or (everyone full)
	// forks
	// philo
}		t_table;

void	error_exit(const char *error);
int		ft_strlen(char *str);

#endif
