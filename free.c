/*
** free.c for free in /home/voinne_c/rendu/PSU_2014_malloc
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Tue Jan 27 14:42:01 2015 Cédric Voinnet
** Last update Tue Feb  3 11:56:09 2015 Cédric Voinnet
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mem.h"

size_t	fusion_forward(void *ptr)
{
  if (ptr == sbrk(0) || ptr - (DATA_SIZE + DATA_FREE) == sbrk(0) || !is_free(ptr))
    return (0);
  (*(size_t*)(ptr - DATA_SIZE)) += fusion_forward(ptr + get_size(ptr) + META_SIZE);
  (*(size_t*)(ptr + (*(size_t*)(ptr - DATA_SIZE)))) = (*(size_t*)(ptr - DATA_SIZE));
  return (*(size_t*)(ptr - DATA_SIZE) + META_SIZE);
}

size_t	fusion_backward(void *ptr)
{
  if (!is_free(ptr))
    return (0);
  if (ptr != g_start && ptr - (DATA_SIZE + DATA_FREE) != g_start)
    fusion_backward(ptr - (META_SIZE + get_prev_size(ptr)));
  return (fusion_forward(ptr));
}

void	set_free(void *ptr)
{
  ptr -= (DATA_SIZE + DATA_FREE);
  *(char*)ptr = 0;
}

void		free(void *ptr)
{
  printf("FREEEEEEEEEEEEE\n");

  size_t	size;

  if (!ptr)
    return;
  set_free(ptr);
  fusion_backward(ptr);
  size = get_size(ptr);
  if (ptr + size + DATA_SIZE == sbrk(0))
    {
      *(size_t*)(ptr - DATA_SIZE) = 0;
      brk(ptr - (DATA_FREE + DATA_SIZE));
    }
}
