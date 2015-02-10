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
  void	*tmp;

  tmp = ((char*)ptr - 8);
  return (*(size_t*)tmp);
}

size_t	get_prev_size(void *ptr)
{
  void	*tmp;

  tmp = ((char*)ptr - 17);
  return (*(size_t*)tmp);
}

int	is_free(void *ptr)
{
  char	*tmp;

  tmp = (char*)ptr;
  tmp -= DATA_SIZE + DATA_FREE;
  if (*tmp == 0)
    return (1);
  return (0);
}
