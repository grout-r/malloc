
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


  ptr = malloc(sizeof(char) * 15);

  i=0;
  while (i != 10)
    {
      ptr[i] = (char)i + 33;
      i++;
    }

  ptr[i] = 0;
  puts(ptr);

  *(char*)(ptr - 5) = 0;
  printf("%p\n", ptr);

  ptr = malloc(sizeof(char) * 10);

  i=0;
  while (i != 9)
    {
      ptr[i] = (char)i + 33;
      i++;
    }
  ptr[i] = 0;
  puts(ptr);

  printf("%p\n", ptr);

  return (0); 
}
