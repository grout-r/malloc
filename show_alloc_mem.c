/*
** show_alloc_mem.c for show_alloc_mem in /home/voinne_c/malloc/mallocu
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Fri Jan 30 09:47:38 2015 Cédric Voinnet
** Last update Fri Jan 30 14:50:43 2015 Cédric Voinnet
*/

#include <unistd.h>
#include <stdio.h>
#include "mem.h"

int	is_free(void *ptr)
{
  ptr -= 9;
  if (*(char*)ptr == 1)
    return (0);
  return (1);
}

void		show_alloc_mem()
{
  void		*tmp;
  unsigned int	size;

  tmp = start;
  printf("break: %p\n", sbrk(0));
  tmp += 9;
  while (tmp != sbrk(0) && tmp - 9 != sbrk(0))
    {
      size = get_size(tmp);
      if (!is_free(tmp))
	printf("%p - %p : %d octets\n", tmp, tmp + size, size);
      tmp += size + 9;
    }
} 
