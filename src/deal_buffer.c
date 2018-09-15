/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:59:18 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 16:59:20 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// t_buff			*create_buff(void)
// {
// 	t_buff	*buff;

// 	if (!(buff = (t_buff*)malloc(sizeof(t_buff))))
// 		return (NULL);
// 	if (!(buff->buffer = ft_strnew(500)))
// 		return (NULL);
// 	buff->buff_i = 0;
// 	return (buff);
// }

// void			ft_init_buffer(t_buff *buff)
// {
// 	if (buff->buff_i > 0)
// 		free(buff->buffer);
// 	buff->buffer = ft_strnew(500);
// 	buff->buff_i = 0;
// }


// void			ft_print_buffer(t_buff *buff)
// {
// 	// printf("Je passe 1\n");
// 	ft_putstr(buff->buffer);
// 	free(buff->buffer);
// 	if (!(buff->buffer = ft_strnew(500)))
// 		return ;
// 	buff->buff_i = 0;
// }

// void			ft_put_buffer(t_buff *buff, char c)
// {
// 	int i;
// 	// printf("Je passe 2\n");	

// 	i = buff->buff_i;
// 	if (i == 500)
// 		return (ft_print_buffer(buff));
// 	buff->buffer[i] = c;
// 	buff->buff_i = i + 1;
// }
