/*
MADE BY GROUT_R + VOINNE_C

PROJECT MALLOC EPITECH 2

JANUARY 2015

 */

#include <unistd.h>
#include <stdio.h>

void		*g_start;

void	*find_space(void *ptr, size_t size)
{
  while (ptr != sbrk(0) )
    {
      if(*(char*)ptr == 0 && *(int*)((char*)(ptr + 1)) >= size)
	return ptr;
      ptr = ptr + *(int*)(ptr + 1) + 9;
    }
  return NULL;
}

void		*malloc(size_t size)
{
  void		*ret;
  int		*stock_size;
  int		*stock_next;
  char		*stock_status;

  static int	first_time = 0;
  printf("size :: %lu\n", size);
  if ((int)size < 1)
    return (NULL);

  if (first_time == 0)
    {
      first_time = 1;
      g_start = sbrk(0);
      puts("first time !");
    }
  if ((ret = find_space(g_start, size)) != NULL)
    {
      *(char *)ret = 1;
      return ((char*)ret + 5);
    }

  ret = sbrk(size + 9);

  stock_status = (char*)(ret);
  stock_size = (int*)((char*)ret + 1);
  stock_next = (int*)((char*)ret + 5 + size);

  *stock_status = 1;
  *stock_size = size;
  *stock_next = size; 

  return ((char*)ret + 5);
}
