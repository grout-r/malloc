/*
** free.c for free in /home/voinne_c/rendu/PSU_2014_malloc
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Tue Jan 27 14:42:01 2015 Cédric Voinnet
** Last update Fri Jan 30 16:37:26 2015 Cédric Voinnet
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mem.h"

unsigned int	get_size(void *ptr)
{
  ptr -= 8;
  return (*(unsigned int*)ptr);
}

unsigned int	fusion_backward(void *ptr)
{
  
}

unsigned int	fusion_forward(void *ptr)
{
  if (ptr == sbrk(0))
    return (0);
  *(int*)ptr - 4 = fusion_forward(ptr);
  return (*(int*)ptr - 4);
}

void	set_free(void *ptr)
{
  ptr -= 9;
  *(char*)ptr = 0;
}

void	free(void *ptr)
{
  unsigned int	size;

  if (!ptr)
    return;
  fusion_forward(ptr);
  fusion_backward(ptr);
  size = get_size(ptr);
  if (ptr + size == sbrk(0))
    {
      set_free(ptr);
      *(int*)(ptr - 8) = 0;
      brk(ptr);
      return;
    }
  set_free(ptr);
}

int	main()
{
  void  *tata;
  void  *titi;
  void  *toto;
  void  *tutu;

  start = sbrk(0);

  show_alloc_mem();

  toto = sbrk(972);
  *(char*)toto = 1;
  toto += 1;
  *(unsigned int*)toto = 963;
  toto += 4;
  *(unsigned int*)toto = 0;
  toto += 4;

  show_alloc_mem();

  titi = sbrk(10);
  *(char*)titi = 1;
  titi += 1;
  *(unsigned int*)titi = 1;
  titi += 4;
  *(unsigned int*)titi = 963;
  titi += 4;

  show_alloc_mem();

  tata = sbrk(454121);
  *(char*)tata = 1;
  tata += 1;
  *(unsigned int*)tata = 454112;
  tata += 4;
  *(unsigned int*)tata = 1;
  tata += 4;

  show_alloc_mem();

  free(tata);

  show_alloc_mem();

  return (0);
}
