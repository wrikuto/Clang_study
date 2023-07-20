#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct	s_node
{
	int		num;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;