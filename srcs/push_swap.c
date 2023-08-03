/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:43:45 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/03 19:37:37 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{


    if (argc < 2)
		ft_error("no input");
    else
    {
		argv++;
        input_error(argv);


    }
    return 0;
}


/*
		while (argv)
        {
            printf("%s\n", *argv);
			if(!*(argv + 1))
				break;
            argv++;
        }
*/
