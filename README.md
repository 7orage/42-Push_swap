ARG=$(shuf -i 0-5000 -n 100); ./push_swap $ARG | ./checker_linux $ARG


1. La génération des nombres (ARG=...)
ARG=$(shuf -i 0-5000 -n 100)

shuf : C'est un utilitaire qui génère des permutations aléatoires.

-i 0-5000 : Définit la plage de nombres (entre 0 et 5000).

-n 100 : Demande de choisir 100 nombres parmi cette plage.

ARG=$(...) : Stocke cette liste de 100 nombres dans une variable nommée ARG.


/* pour visu stacks */

ptr = stack_a;
	ft_printf("\n\n VALUE A --F\n");
	while (ptr)
	{
		ft_printf("value a %d\n", (int)ptr->value);
		ptr = ptr->next;
	}