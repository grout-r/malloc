
#include <stdlib.h>
#include <stdio.h>

void	*malloc(size_t size);

int     main()                                                                  
{                                                                    
  char  *ptr;                                                                   
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
