/*
** mem.h for mem in /home/voinne_c/malloc/mallocu
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Fri Jan 30 13:37:35 2015 Cédric Voinnet
** Last update Mon Feb  2 18:57:13 2015 Cédric Voinnet
*/

#ifndef MEM_H_
# define MEM_H_

# define DATA_FREE sizeof(char)
# define DATA_SIZE sizeof(size_t)
# define META_SIZE DATA_SIZE + DATA_SIZE + DATA_FREE

extern void	*g_start;

void	show_alloc_mem();
void	*malloc(size_t);
void	free(void *);
size_t		get_size(void *ptr);
void		show_alloc_mem();
int		is_free(void *);
size_t		get_size(void *ptr);
size_t		get_prev_size(void *ptr);

#endif	/* !MEM_H_ */
