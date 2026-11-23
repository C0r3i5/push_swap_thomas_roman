
typedef struct s_stack
{
    int             value; // Die eigentliche Zahl
    struct s_stack  *next; // Zeiger auf die Zahl darunter im Stapel
}   t_stack;

// Hauptfunktionen der vier Strategien
void bubble_sort_stack(t_stack **a, t_stack **b, int size)
{

// void	ft_sort_int_tab(int *tab, int size)

	int	count_array_loop1;
	int	count_array_loop2;
	int	temp;

	count_array_loop1 = 0;
	while (count_array_loop1 < size - 1)
	{
		count_array_loop2 = 0;
		while (count_array_loop2 < size - 1)
		{
			if (tab[count_array_loop2] > tab[count_array_loop2 + 1])
			{
				temp = tab[count_array_loop2];
				tab[count_array_loop2] = tab[count_array_loop2 + 1];
				tab[count_array_loop2 + 1] = temp;
			}
			count_array_loop2++;
		}
		count_array_loop1++;
	}
}
}