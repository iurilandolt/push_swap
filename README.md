# push_swap:

**./push_swap** sorts a list of numbers using a limited set and amout of operations.
On receiving a valid list, it prints a sequence of moves to sort the list in ascending order.
This printed output can be used to feed data-visualization software.

## Input Validation
The list must:
- Be composed of integers ranging from `int_min` to `int_max`.
- Contain no symbols or characters other than the number itself and "-" for negative values.
- Have no duplicate values.
- Be unsorted.

## Output
The program outputs a series of moves to the standard output, each followed by a newline (`\n`).

The printed set of moves should translate to the sorting of the list, as efficiently as possible with a limited amount of actions.

this push_swap's version complies with:

`set of 3` :

          max 2

`set of 5` : (average 8)

          max 12

`set of 100` (average 643)

          less than 700	-> 5
          less than 900	-> 4
          less than 1100	-> 3
          less than 1300	-> 2
          less than 1500	-> 1

`set of 500` (average 5901)

          less than 5500	-> 5
          less than 7000	-> 4
          less than 8500	-> 3
          less than 10000	-> 2
          less than 11500	-> 1

## Lists
- **List A**: The main list to be sorted.
- **List B**: An auxiliary list useful for sorting larger sets. This list must be empty at the end.

## Allowed Moves
- **SWAP** (`sa` or `sb`): Swap the top two elements of the target list. (used only in small sets)
- **ROTATE** (`ra` or `rb`): Rotate the list clockwise. The last element becomes the first.
- **REVERSE ROTATE** (`rra` or `rrb`): Rotate the list counter-clockwise. The first element becomes the last.
- **PUSH** (`pa` or `pb`): Transfer the top element from one list to the other.
- **SWAP BOTH** (`ss`): Simultaneously execute `sa` and `sb`. (not implemented)
- **ROTATE BOTH** (`rr`): Simultaneously execute `ra` and `rb`.
- **REVERSE ROTATE BOTH** (`rrr`): Simultaneously execute `rra` and `rrb`.

## Intput validation and conversion from char **argument to int
its not mandatory but if you want to handle input given in a single string; `"5 3 2 1 4"`,

you can use your `split()` function to turn it into a valid `**argv`;

          t_stack_node	*handle_single_argv(char **value)
          {
          	t_stack_node	*a;
          	char			**args;
          	int				i;
          	int				j;

          	a = NULL;
          	i = 0;
          	args = ft_split(*value, ' ');
          	j = arrlen(args);
          	while (i < j)
          		input_error(args + i++);
          	a = init_stack(args);
          	clean(args, j);
          	return (a);
          }

to keep things simple i decided to break down my validation process in two steps,
the first step only checks if `**argv` is composed singularly of characters valid to later build a list/array of `ints`;
          these would be only: `digits`, `+` and `-`.

before the second step of my validation, looking for dupes and checking if the list is sorted,

i first create my list, and populate it using atoi(), to convert each string of digits in **argv into a node with a value on my list;

(it's easier to do this validation to a list of ints than to an array of strings (: )

          int	ctoi(const char *nptr)
          {
          	long int	n;
          	int			sign;

          	sign = 1;
          	n = 0;
          	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
          		nptr++;
          	if (*nptr == '+' || *nptr == '-')
          		if (*nptr++ == '-')
          			sign = -1;
          	while (ft_isdigit(*nptr))
          	{
          		n = n * 10 + (*nptr++ - '0');
          		if (n * sign > INT_MAX || n * sign < INT_MIN)
          			ft_error("Error");
          	}
          	return (n * sign);
          }

stack initialization:

          t_stack_node	*init_stack(char **args)
          {
          	t_stack_node	*first;
          	t_stack_node	*new;
          	t_stack_node	*last;
          	int				index;

          	index = -1;
          	while (args[++index])
          	{
          		if (index == 0)
          		{
          			first = new_node(ctoi(args[index]), index);
          			last = first;
          		}
          		else
          		{
          			new = new_node(ctoi(args[index]), index);
          			last->next = new;
          			new->previous = last;
          			last = new;
          		}
          	}
          	check_stack(first);
          	return (first);
          }
## Struct

i opted for a doubly-linked-list struct as follows:

          typedef struct s_stack_node
          {
                    int					value;
                    int					index;
                    int					level;
                    int					cost;
                    struct s_stack_node	*next;
                    struct s_stack_node	*previous;
                    struct s_stack_node	*target;
          }

to clarify, other than the necessary `next` & `previous` pointers needed for a doubly-linked-list,

each node has a

`value` : argument stored in the node.

`index` : position of the node relative to the head of the list: `0`.

`level` : descriptor if node is in first half, center or second half of the list. `-1 0 1` .

`cost` : how many moves it would take the node to get to the head of the list.

`target` : pointer to the ideal target for this node in opposite list.

this seems overkill but it will make things a lot simpler when we get to sorting big sets of numbers.

## Sorting

at this moment the approach to sorting is divided in X possible cases;

### a set of 2 values

is the value of the first node > than the value of the second node?

                    yes? then swap.

                    no? it's sorted.

### a set of 3 values

in this case we need to find the position of the node with the highest value and get it to the tail of the list,

after this we only need to sort the first two nodes.

          void	sort_3(t_stack_node **lst)
          {
          	t_stack_node	*highest;

          	highest = get_highest_value_node(*lst);
          	if (*lst == highest)
          		rotate(lst, 'a');
          	else if ((*lst)->next == highest)
          		reverse_rotate(lst, 'a');
          	if ((*lst)->value > (*lst)->next->value)
          		swap(*lst, 'a');
          }

### a set of 4/5 values

          void	sort_4_5(t_stack_node **lst)
          {
          	t_stack_node	*b;
          	t_stack_node	*marker;

          	b = NULL;
          	while (stack_size(*lst) > 3)
          		push(lst, &b, 'b');
          	sort_3(lst);
          	while (b)
          	{
          		reset_targets(*lst, b);
          		if ((*lst) == b->target)
          			push(&b, lst, 'a');
          		else if ((*lst)->level <= 0)
          			rotate(lst, 'a');
          		else
          			reverse_rotate(lst, 'a');
          	}
          	marker = get_lowest_value_node(*lst);
          	while ((*lst) != get_lowest_value_node(*lst))
          	{
          		if (marker->level > 0)
          			reverse_rotate(lst, 'a');
          		else
          			rotate(lst, 'a');
          	}
          }
### a set > 5 values

          void	big_sort(t_stack_node **lst)
          {
          	t_stack_node	*b;
          	t_stack_node	*marker;

          	b = NULL;
          	while (stack_size(*lst) > 3)
          		push(lst, &b, 'b');
          	small_sort(lst);
          	while (b)
          	{
          		reset_targets((*lst), b);
          		move_b(lst, &b);
          		move_a(lst, &b);
          	}
          	marker = get_lowest_value_node(*lst);
          	while ((*lst) != get_lowest_value_node(*lst))
          	{
          		if (marker->level > 0)
          			reverse_rotate(lst, 'a');
          		else
          			rotate(lst, 'a');
          	}
          }




