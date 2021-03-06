/*
** malloc.c for malloc in /home/voinne_c/malloc/mallocu
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Tue Feb  3 09:59:09 2015 Cédric Voinnet
** Last update Sun Feb  8 18:59:22 2015 Cédric Voinnet
*/

#include <unistd.h>
#include <stdio.h>
#include "mem.h"

void		*g_start;

void		*split(void *ptr, size_t size)
{
  size_t	old_size;
  size_t	new_size;
  void		*new;

  old_size = *(size_t*)((char*)ptr + DATA_FREE);
  if (((old_size + META_SIZE) - (size + META_SIZE)) >= META_SIZE + 1)
    {
      *(size_t*)((char*)ptr + DATA_FREE) = size;
      *(size_t*)((char*)ptr + DATA_FREE + DATA_SIZE + size) = size;
      new = ((char*)ptr + META_SIZE + size);
      new_size = old_size - (size + DATA_SIZE + DATA_FREE + DATA_SIZE);
      *(char*)(new) = 0;
      *(size_t*)((char*)new + DATA_FREE) = new_size;
      *(size_t*)((char*)new + DATA_FREE + DATA_SIZE  + new_size) = new_size;
    }
  return (ptr);
}

void	*find_space(void *ptr, size_t size)
{
  while (ptr != sbrk(0))
    {
      if (*(char*)ptr == 0 && *(size_t*)((char*)ptr + DATA_FREE) >= size)
	return (split(ptr, size));
      ptr = (char*)ptr + *(size_t*)((char*)ptr + DATA_FREE) + META_SIZE;
    }
  return (NULL);
}

void		*malloc(size_t size)
{
  void		*ret;
  static int	first_time = 0;

  if ((long)size < 1)
    return (NULL);
  if (first_time == 0)
    {
      first_time = 1;
      g_start = sbrk(0);
    }
  if ((ret = find_space(g_start, size)) != NULL)
    {
      *(char *)ret = 1;
      return ((char*)ret + DATA_FREE + DATA_SIZE);
    }
  ret = sbrk(size + META_SIZE);
  if (ret == (void*) -1)
    return (NULL);
  *(char*)(ret) = 1;
  *(size_t*)((char*)ret + DATA_FREE) = size;
  *(size_t*)((char*)ret + DATA_FREE + DATA_SIZE + size) = size;
  return ((char*)ret + DATA_FREE + DATA_SIZE);
}
