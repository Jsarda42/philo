#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# ifndef PHILO_MAX
#  define PHILO_MAX 200
# endif

typedef enum e_operation
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}					t_operation;

# define RST "\033[0m"
# define RED "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define M "\033[1;35m"
# define C "\033[1;36m"
# define W "\033[1;37m"

typedef enum e_bool
{
	false,
	true
}					t_bool;

typedef struct s_philo
{
	long			num_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_times_to_eat;
	int				id;
	int				meals_eaten;
	int				eating;
	pthread_mutex_t	*neighbor_fork;
	pthread_mutex_t	*philo_fork;
	size_t			last_meal;
	size_t			start_time;
	int				*dead;

	// pthread_t		thread;
	// pthread_mutex_t	*write_lock;
	// pthread_mutex_t	*dead_lock;
	// pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	// pthread_mutex_t	dead_lock;
	// pthread_mutex_t	meal_lock;
	// pthread_mutex_t	write_lock;
	// t_philo			*philos;
}					t_program;

// error
void				error_exit(const char *error);

// utils
int					ft_strlen(char *str);
size_t				get_time_of_day(void);

// init
void				parsing_init(t_philo *table, char **argv);
void				philo_init(t_philo *philos, pthread_mutex_t *forks,
						t_program *program);
void				init_forks(pthread_mutex_t *forks, int philo_num);

// safe
void				safe_thread(pthread_t *thread, void *(*foo)(void *),
						void *data, t_operation operation);
void				*safe_malloc(size_t bytes);

#endif
