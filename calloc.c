/*
** calloc.c for calloc in /home/voinne_c/malloc/mallocu
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Tue Feb  3 09:11:33 2015 Cédric Voinnet
** Last update Tue Feb  3 10:27:21 2015 Cédric Voinnet
*/

#include <stdio.h>
#include <unistd.h>
#include "mem.h"

void		*calloc(size_t nmemb, size_t size)
{
  void		*tab;
  size_t	i;

  i = 0;
  if(!nmemb || !size)
    return (NULL);
  if (!(tab = malloc(nmemb * size)))
    return (NULL);
  while (i != nmemb * size)
    {
      *(char*)tab = 0;
      ++i;
    }
  return (tab);
}
