/*
** show_alloc_mem.c for show_alloc_mem in /home/voinne_c/malloc/mallocu
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Fri Jan 30 09:47:38 2015 Cédric Voinnet
** Last update Sun Feb  8 19:03:42 2015 Cédric Voinnet
*/

#include <unistd.h>
#include <stdio.h>
#include "mem.h"

void		show_alloc_mem()
{
  void		*tmp;
  size_t	size;

  printf("break: %p\n", sbrk(0));
  if (!g_start)
    return;
  tmp = g_start;
  tmp = (char*)tmp + DATA_SIZE + DATA_FREE;
  while (tmp != sbrk(0) && (char*)tmp - (DATA_SIZE + DATA_FREE) != sbrk(0))
    {
      size = get_size(tmp);
      if (!is_free(tmp))
	printf("NOT FREE:\t%p - %p : %lu octets\n", tmp, (char*)tmp + size, size);
      tmp = (char*)tmp + size + META_SIZE;
    }
} 
