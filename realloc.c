/*
** realloc.c for realloc in /home/voinne_c/malloc/mallocu
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Fri Jan 30 09:49:48 2015 Cédric Voinnet
** Last update Sun Feb  8 19:21:59 2015 Cédric Voinnet
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mem.h"

void	*realloc(void *ptr, size_t size)
{
  void	*new;

  if (!ptr)
    return (malloc(size));
  if (!size)
    {
      free(ptr);
      return (NULL);
    }
  if (get_size(ptr) >= size)
    return (ptr);
  new = malloc(size);
  size = (get_size(ptr) < get_size(new)) ? get_size(ptr) : get_size(new);
  new = memcpy(new, ptr, size);
  free(ptr);
  return (new);
}
