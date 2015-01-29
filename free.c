/*
** free.c for free in /home/voinne_c/rendu/PSU_2014_malloc
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Tue Jan 27 14:42:01 2015 Cédric Voinnet
** Last update Thu Jan 29 12:17:55 2015 Cédric Voinnet
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int	get_size(void *ptr)
{
  ptr -= 4;
  printf("size: %d\n",*(unsigned int*)ptr);
  return (*(unsigned int*)ptr);
}

void	free(void *ptr)
{
  unsigned int	size;

  if (!ptr)
    return;
  size = get_size(ptr);
  if (ptr + size == sbrk(0))
    {
      printf("Dernier element alloué\n");
      sbrk((size * -1) - 4);
      return;
    }
  ptr -= 5;
  *(char*)ptr == 0 ? printf("ptr is free\n") : printf("ptr is occuped\n");
  *(char*)ptr = 0;
}

int	main()
{
  void	*toto;
  void	*titi;

  printf("End of heap: %10p\n", sbrk(0));
  toto = sbrk(6);
  *(char*)toto = 1;
  toto += 1;
  *(unsigned int*)toto = 1;
  printf("End of heap: %10p\n", sbrk(0));
  toto += 4;

  *(char*)toto = 't';

  titi = sbrk(132);
  *(char*)titi = 1;
  titi += 1;
  *(unsigned int*)titi = 128;
  printf("End of heap: %10p\n", sbrk(0));
  titi += 4;
  free(toto);
  free(titi);
  printf("End of heap: %10p\n", sbrk(0));
  return (0);
}
