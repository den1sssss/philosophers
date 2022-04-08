#include "philo.h"
void parser(int argc, char **argv, t_gen *gen)
{
	gen->num=ft_atoi(argv[1]);
	gen->t_die=ft_atoi(argv[2]);
	gen->t_eat=ft_atoi(argv[3]);
	gen->t_sleep=ft_atoi(argv[4]);
	if(argc == 6)
		// gen->
}

int main(int argc,char**argv)
{
	t_gen gen;

	if (argc == 5 || argc == 6)
	{
		parser(argc,argv,&gen);
	}
}