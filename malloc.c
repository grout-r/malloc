/*
** malloc.c for malloc in /home/voinne_c/malloc/mallocu
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Tue Feb  3 09:59:09 2015 Cédric Voinnet
** Last update Wed Feb  4 09:24:21 2015 Cédric Voinnet
*/

#include <unistd.h>
#include <stdio.h>
#include "mem.h"

void		*g_start;

void	*find_space(void *ptr, size_t size)
{
  while (ptr != sbrk(0))
    {
      //      printf("%p --- %p ... %p\n", ptr, ptr + *(size_t*)(ptr + DATA_FREE) + META_SIZE, sbrk(0));
      if (*(char*)ptr == 0 && *(size_t*)(ptr + DATA_FREE) >= size)
	return (ptr);
      ptr = ptr + *(size_t*)(ptr + DATA_FREE) + META_SIZE;
    }
  return (NULL);
}

void		*malloc(size_t size)
{
  //  printf("MALLLLLOOOOOCCOCOOCOCOCOCO\n");
  void		*ret;
  static int	first_time = 0;

  //  show_alloc_mem();
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
      return (ret + DATA_FREE + DATA_SIZE);
    }
  //  printf("TOUT EST VRAIMENT GENIAL \n");
  ret = sbrk(size + META_SIZE);
  if (ret == (void*) -1)
    {
      printf("OWOWOWOWOWOWOWOWO\n");
    return (NULL);
    }
  *(char*)(ret) = 1;
  *(size_t*)(ret + DATA_FREE) = size;
  *(size_t*)(ret + DATA_FREE + DATA_SIZE + size) = size;
  //  show_alloc_mem();
  return (ret + DATA_FREE + DATA_SIZE);
}
