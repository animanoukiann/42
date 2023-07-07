#include "push_swap.h"

int main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*mix;
	char	**numbers;
	int		*arr;
	int		*arr1;
	int		*arr_index;
	int 	argv_len;
	int 	size_arr;

	if (argc >= 2)
	{	
		i = 1;
		argv_len = the_length_of_argv(argc,argv);
		mix = (char *)malloc(sizeof(char) * argv_len);
		if (!mix)
			return (0);
		ft_bzero(mix, argv_len - 1);
		j = 0;
		while(i < argc)
		{
			space_checker(argv[i]);
			mix = ft_strcpy(mix, argv[i], &j, argv_len);
			i++;
		}
		size_arr = 0;
		numbers = ft_split(mix, ' ', &size_arr);
		free(mix);
		arr = (int *)malloc(sizeof(int) * (size_arr));
		arr1 = (int *)malloc(sizeof(int) * (size_arr));
		arr_index = (int *)malloc(sizeof(int) * (size_arr));
		if (!arr)
			return (0);
		k = 0;
		while (k < size_arr)
		{
			arr[k] = ft_atoi(numbers[k]);
			arr1[k] = arr[k];
			k++;
		}
		checker(arr, size_arr);
		quick_sort(arr, size_arr);
		arr_index = for_index_sort(arr, arr1, arr_index, size_arr);
		free(arr);
		free(arr1);
		t_list	**a;
		t_list	**b;
		t_list	*new = NULL;
		a = (t_list **)malloc(sizeof(t_list) * size_arr);
		b = (t_list **)malloc(sizeof(t_list) * size_arr);
		*a = NULL;
		*b = NULL;
		for (int i = 0; i < size_arr; i++)
		{
			new = ft_lstnew(arr_index[i]);
			if (new != NULL)
				ft_lstadd_back(a, new);
		}
		free(arr_index);
		butterfly(a, b, size_arr);
		back_to_a(a, b, size_arr);
		free(a);
		free(b);
		// system("leaks push_swap");
	 }
	return (0);
}