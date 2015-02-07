/*
** misc.c for malloc in /home/voinne_c/malloc/mallocu
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Mon Feb  2 18:00:05 2015 Cédric Voinnet
** Last update Fri Feb  6 08:38:06 2015 Cédric Voinnet
*/

#include <unistd.h>
#include "mem.h"

size_t	get_size(void *ptr)
{
  ptr -= DATA_SIZE;
  return (*(size_t*)ptr);
}

size_t	get_prev_size(void *ptr)
{
  ptr -= META_SIZE;
  return (*(size_t*)ptr);
}

size_t		next_mul(size_t size)
{
  size_t	mul;

  mul = 0;
  while (mul < size)
    mul += 4;
  return (mul);
}

int	is_free(void *ptr)
{
  ptr -= DATA_SIZE + DATA_FREE;
  if (*(char*)ptr == 0)
    return (1);
  return (0);
}
