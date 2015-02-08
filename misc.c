/*
** misc.c for malloc in /home/voinne_c/malloc/mallocu
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Mon Feb  2 18:00:05 2015 Cédric Voinnet
** Last update Sun Feb  8 19:22:38 2015 Cédric Voinnet
*/

#include <stdio.h>
#include <unistd.h>
#include "mem.h"

size_t	get_size(void *ptr)
{
  ptr -= DATA_SIZE;
  return (*(size_t*)ptr);
  /* return (*(size_t*)((char*)ptr - DATA_SIZE)); */
}

size_t	get_prev_size(void *ptr)
{
  ptr -= META_SIZE;
  return (*(size_t*)ptr);
  /* return (*(size_t*)((char*)ptr - META_SIZE)); */
}

int	is_free(void *ptr)
{
  ptr -= DATA_SIZE + DATA_FREE;
  if (*(char*)ptr == 0)
  /* if (*(char*)((char*)ptr - DATA_SIZE + DATA_FREE) == 0) */
    return (1);
  return (0);
}
