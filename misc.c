/*
** misc.c for malloc in /home/voinne_c/malloc/mallocu
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Mon Feb  2 18:00:05 2015 Cédric Voinnet
** Last update Mon Feb  2 18:02:42 2015 Cédric Voinnet
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
