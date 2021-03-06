/*
** free.c for free in /home/voinne_c/rendu/PSU_2014_malloc
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Tue Jan 27 14:42:01 2015 Cédric Voinnet
** Last update Sun Feb  8 19:01:48 2015 Cédric Voinnet
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mem.h"

size_t	fusion_forward(void *ptr)
{
  if (ptr == sbrk(0) || (char*)ptr - (DATA_SIZE + DATA_FREE) == sbrk(0) ||
      !is_free(ptr))
    return (0);
  (*(size_t*)((char*)ptr - DATA_SIZE)) += 
    fusion_forward((char*)ptr + get_size(ptr) + META_SIZE);
  (*(size_t*)((char*)ptr + (*(size_t*)((char*)ptr - DATA_SIZE)))) =
    (*(size_t*)((char*)ptr - DATA_SIZE));
  return (*(size_t*)((char*)ptr - DATA_SIZE) + META_SIZE);
}

void	*fusion_backward(void *ptr)
{
  if (!is_free(ptr))
    return ((char*)ptr + META_SIZE + get_size(ptr));
  if (ptr != g_start && (char*)ptr - (DATA_SIZE + DATA_FREE) != g_start)
    ptr = fusion_backward((char*)ptr - (META_SIZE + get_prev_size(ptr)));
  fusion_forward(ptr);
  return (ptr);
}

void	set_free(void *ptr)
{
  ptr = (char*)ptr - (DATA_SIZE + DATA_FREE);
  *(char*)ptr = 0;
}

void		free(void *ptr)
{
  size_t	size;

  if (!ptr)
    return;
  set_free(ptr);
  ptr = fusion_backward(ptr);
  size = get_size(ptr);
  if ((char*)ptr + size + DATA_SIZE == sbrk(0))
    {
      *(size_t*)((char*)ptr - DATA_SIZE) = 0;
      brk((char*)ptr - (DATA_FREE + DATA_SIZE));
    }
}
