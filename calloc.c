/*
** calloc.c for calloc in /home/voinne_c/malloc/mallocu
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Tue Feb  3 09:11:33 2015 Cédric Voinnet
** Last update Sun Feb  8 18:58:50 2015 Cédric Voinnet
*/

#include <unistd.h>
#include <strings.h>
#include "mem.h"

void		*calloc(size_t nmemb, size_t size)
{
  void		*tab;

  if(!nmemb || !size)
    return (NULL);
  if (!(tab = malloc(nmemb * size)))
    return (NULL);
  bzero(tab, nmemb * size);
  return (tab);
}
