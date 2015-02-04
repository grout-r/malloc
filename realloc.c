/*
** realloc.c for realloc in /home/voinne_c/malloc/mallocu
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Fri Jan 30 09:49:48 2015 Cédric Voinnet
** Last update Wed Feb  4 09:32:02 2015 Cédric Voinnet
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mem.h"

void	*realloc(void *ptr, size_t size)
{
  //  printf("REALLLLOOOOOCC\n");
  void	*new;

  show_alloc_mem();
  //  printf("s: %p --- c: %p --- e: %p SIZE :::: \t%lu\n", g_start, ptr, sbrk(0), size);
  if (!ptr)
    return (malloc(size));
  if (!size)
    {
      free(ptr);
      return (NULL);
    }
  if (get_size(ptr) == size)
    return (ptr);
  new = malloc(size);
  size = (get_size(ptr) < get_size(new)) ? get_size(ptr) : get_size(new);
  new = memcpy(new, ptr, size);
  free(ptr);
  return (new);
}
