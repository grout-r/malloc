
#include <stdlib.h>
#include <stdio.h>

void	*malloc(size_t size);

int     main()
{
  char  *ptr;
  int i = 0; 

  ptr = malloc(sizeof(char) * 10);

  while (i != 9)
    {
      ptr[i] = (char)i + 33;
      i++;
    }
  ptr[i] = 0;
  puts(ptr);

  ptr = realloc(ptr, sizeof(char) * 20);

  while (i != 19)
    {
      ptr[i] = (char)i + 33;
      i++;
    }
  ptr[i] = 0;
  puts(ptr);
  free(ptr);

  return (0);
}
