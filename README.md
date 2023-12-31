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

This push_swap's version complies with:

`set of 3` :

          max 2

`set of 5` : 

          max 12

`set of 100` 

          less than 700	-> 5
          less than 900	-> 4
          less than 1100	-> 3
          less than 1300	-> 2
          less than 1500	-> 1

`set of 500` 

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

To keep things simple i decided to break down my validation process in two steps,
the first step only checks if `**argv` is composed singularly of characters valid to later build a list/array of `ints`;


These would be only: `digits`, `+` and `-`.

Before the second step of my validation, looking for dupes and checking if the list is sorted,


 We first create a list, and populate it using `atoi()`, to convert each string of digits in **argv into a node with a value on my list;

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

Stack initialization:

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

To clarify, other than the necessary `next` & `previous` pointers needed for a doubly-linked-list,

each node has a

`value` : argument stored in the node.

`index` : position of the node relative to the head of the list: `0`.

`level` : descriptor if node is in first half, center or second half of the list. `-1 0 1` .

`cost` : how many moves it would take the node to get to the head of the list.

`target` : pointer to the ideal target for this node in opposite list.

This seems overkill but it will make things a lot simpler when we get to sorting big sets of numbers.

## Sorting

At this moment the approach to sorting is divided in X possible cases;

### a set of 2 values

is the value of the first node > than the value of the second node?

                    yes? then swap.

                    no? it's sorted.

### a set of 3 values

In this case we need to find the position of the node with the highest value and get it to the tail of the list,

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

### a set of 4 or 5 values

From here on out, for sets larger than 3 values, we`ll push enough nodes to list B until there are only 3 nodes left in list A.

After this we can sort the 3 nodes in list A. Now we only need to find the best position in list A to push back the nodes in list B.

We set a "best target" in list A for each node in list B. 

The best target will be saved in our struct with the `t_stack_node *target`, this target should be a node with a `>` value but as close as possible to the value stored in B.

e.g; If the value stored in B is 3 and if there is a node in A with the value 4, this node will be the ideal target.

If there isn`t a node with a larger value stored in list A, the target will be the smallest node.

After searching for an ideal target and rotating list A until that target is at the head of the list we push B, repeat this process until B is empty.

Now we only need to find the node with the lowest value on our list and bring it to the top, if this node is on the first half of the list we will rotate, if it is on the second half we will reverse rotate.
this is why we have the `int level` variable in our struct, it tells us if the node is in the first or second half of the list `-1` means first half `1` means second half, `0` is the center of the list, but we consider this position to be 
the same as `-1`, because its cheaper to rotate than it is to reverse rotate.

Your list is sorted.

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

With sets larger than 5 values we`ll use the exact same logic as with 4/5 but we need to optimize how we set our targets.

To achieve this we`ll have to rotate list B as well instead of only rotatin list A.

We will also use simultaneous rotation whenever possible to lower the amount of actions we use to sort the list.

For this algorithm we will have to find an `optimal` node in B. The optimal node will be the one with the lowest combined movement cost.

This means that, for each node in B, we will calculate how many actions in would take to bring it and it's `*target` to the top of the list.

So we add the cost of each node in B to the cost of `b->target`, we find the cheapest `combined cost` and we set this node in B as our optimal node.

We'll bring the optimal node and it's target to the top of the stacks, using `RR` or `RRR` whenever possible to move them together.

Just like before, repeat this process until B is empty, find the lowest value node in list A and bring it to the top.

Job done. :)
          
          void	optimal_rotation(t_stack_node **lst_a, t_stack_node **lst_b)
          {
          	t_stack_node	*optimal;
          
          	reset_targets(*lst_a, *lst_b);
          	optimal = get_optimal_b(*lst_a, *lst_b);
          	while (*lst_a != optimal->target || *lst_b != optimal)
          	{
          		if (optimal->level <= 0 && optimal->target->level <= 0)
          			rotate_all(lst_a, lst_b);
          		else if (optimal->level > 0 && optimal->target->level > 0)
          			reverse_rotate_all(lst_a, lst_b);
          		else
          			move_nodes(lst_a, lst_b, optimal);
          	}
          	push(lst_b, lst_a, 'a');
          }
          
          void	big_sort(t_stack_node **lst)
          {
          	t_stack_node	*b;
          	t_stack_node	*marker;
          
          	b = NULL;
          	while (stack_size(*lst) > 3)
          		push(lst, &b, 'b');
          	small_sort(lst);
          	while (b)
          		optimal_rotation(lst, &b);
          	marker = get_lowest_value_node(*lst);
          	while ((*lst) != get_lowest_value_node(*lst))
          	{
          		if (marker->level > 0)
          			reverse_rotate(lst, 'a');
          		else
          			rotate(lst, 'a');
          	}
          }




