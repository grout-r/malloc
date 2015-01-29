/*


MADE BY GROUT_R + VOINNE_C

PROJECT MALLOC EPITECH 2

JANUARY 2015
 */



#include <unistd.h>
#include <stdio.h>

void		*start;

void	*find_space(void *ptr, size_t size)
{
  while (ptr < sbrk(0))
    {
      printf(" USE : %d , SIZE : %d\n", *(char *)ptr, *((char*)ptr + 1));
      if (*(char *)ptr == 0 && *((char*)ptr + 1) >= (int)size)
	{
	  puts("reuse!\n");
	return ptr;
	}
      ptr = *(char **)ptr + 5;
    }
  return NULL;
}

void		*malloc(size_t size)
{
  void		*ret;
  int		*stock_size;
  char		*stock_status;
  char		**stock_next;
  static int	first_time = 0;
  printf("size :: %lu\n", size);
  if ((int)size < 1)
    return (NULL);

  if (first_time == 0)
    {
      first_time = 1;
      start = sbrk(0);
      puts("first time !");
    }

  if ((ret = find_space(start, size)) != NULL)
    {
      *(char *)ret = 1;
      return ret;
    }

  ret = sbrk(size + 13);

  stock_status = (char*)(ret);
  stock_size = (int*)((char*)ret + 1);
  stock_next = (char**)((char*)ret + 5);

  *stock_status = 1;
  *stock_size = size;
  *stock_next = sbrk(0);

  return ((char*)ret + 13);
}

int	main()
{
  char	*ptr;
  int i = 0;

  ptr = malloc(sizeof(char) * 10);

  printf("%d\n", *(int*)(ptr - 12));

  while (i != 10)
    {
      ptr[i] = (char)i + 33;
      puts(ptr);
      i++;
    }

  ptr = malloc(sizeof(char) * 15);

  printf("%p\n", (ptr));

  i=0;
  while (i != 10)
    {
      ptr[i] = (char)i + 33;
      puts(ptr);
      i++;
    }
  
  *((char*)ptr - 13) = 0;

  ptr = malloc(sizeof(char) * 10);


  i=0;
  while (i != 10)
    {
      ptr[i] = (char)i + 33;
      puts(ptr);
      i++;
    }
  return (0);
}
