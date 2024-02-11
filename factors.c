#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *
 **/

int main(int argc, __attribute__((unused))char *args[])
{
  FILE *fp;
  char *buffer = NULL;
  size_t n = 0;
  unsigned long long int number, q, p;

  if (argc != 2)
    {
      fprintf(stderr, "error argument!!!\n");
      exit(EXIT_FAILURE);
    }

  if (access("tests/test00", R_OK) == -1)
    {
      fprintf(stderr, "File can not read!!\n");
      exit(EXIT_FAILURE);
    }

  fp = fopen("tests/test00", "r");
  if (fp == NULL)
    {
      fprintf(stderr, "File can not open!!\n");
      exit(EXIT_FAILURE);
    }

  while (getline(&buffer, &n, fp))
    {
      number = atoi(buffer);

      for (q = 2; q < number; q++)
	{
	  for (p = 2; p < number; p++)
	    {
	      if (p * q == number)
		{
		  printf("%llu=%llu*%llu\n", number, p, q);
		  break;
		}
	    }
	  if (p != n)
	    break;
	}
    }
  free(buffer);
  return (0);
}
