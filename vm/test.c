/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:50:08 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/15 17:54:06 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		big_endian(unsigned int num, int n)
{ 
    unsigned int reverse_num = 0;
	unsigned int temp; 
	int i;

	i = 0;
	while (i < n) 
    { 
        temp = (num & (1 << i)); 
        if (temp) 
            reverse_num |= (1 << ((n - 1) - i));
		i++;
	}
    return reverse_num;
}

int main()
{
	unsigned int num = 42;
	printf("after_conversion = %d\n", big_endian(42, 4));
}