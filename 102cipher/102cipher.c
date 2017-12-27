#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int deter(int **key, int size)
{
  int det;

  int i, j, j1, j2;
  int **m;

  if (size < 1)
    {
      exit(84);
    }
  else if (size == 1)
    det = key[0][0];
  else if (size == 2)
    det = (key[0][0] * key[1][1]) - (key[0][1] * key[1][0]);
  else
    {
      det = 0;
      for (j1 = 0; j1 < size; j1++)
      	{
      	  m = malloc(sizeof (int **) * (size));
      	  for (i = 0; i < size - 1; i++)
      	    m[i] = malloc(sizeof(int *) * (size));
      	  for (i = 1; i < size; i++)
      	    {
      	      j2 = 0;
      	      for (j = 0; j < size; j++)
      		{
      		  if (j == j1)
      		    continue ;
      		  m[i - 1][j2] = key[i][j];
      		  j2++;
      		}
      	    }
      	  det += pow(-1.0, (j1 + 2.0)) * key[0][j1] * deter(m , size - 1);
      	  for (i = 0; i < size - 1; i++)
      	    free(m[i]);
      	  free(m);
	}
    }
  return (det);
}

float	**inverse(int **key, int size)
{
  float **tmp;
  int	i, j, i1, j2;
  float det;

  if (deter(key, size) == 0)
    {
      exit(84);
    }
  else if (size == 2)
    {
      tmp = malloc(sizeof (float *) * (size));
      for (i = 0; i < size; i++)
	tmp[i] = malloc(sizeof(float ) * (size));
      tmp[0][0] = key[1][1];
      tmp[0][1] = -key[0][1];
      tmp[1][0] = -key[1][0];
      tmp[1][1] = key[0][0];
      det = 1.00 / (float)deter(key, 2);
      for (i = 0; i < 2; i++)
	{
	  for (j = 0; j < 2; j++)
	    {
	    tmp[i][j] = tmp[i][j] * det;
	    }
	}
    }
  else if (size == 3)
    {
      tmp = malloc(sizeof (float *) * (size));
      for (i = 0; i < size; i++)
	tmp[i] = malloc(sizeof(float) * (size));
      tmp[0][0] = (key[1][1] * key[2][2]) - (key[1][2] * key[2][1]);
      tmp[0][1] = -((key[1][1] * key[2][2]) - (key[2][1] * key[1][2]));
      tmp[0][2] = (key[0][1] * key[1][2]) - (key[1][1] * key[0][2]);
      tmp[1][0] =  -((key[1][0] * key[2][2]) - (key[2][0] * key[1][2]));
      tmp[1][1] = (key[0][0] * key[2][2]) - (key[0][2] * key[2][0]);
      tmp[1][2] = -((key[0][0] * key[1][2]) - (key[1][0] * key[0][2]));
      tmp[2][0] = (key[1][0] * key[2][1]) - (key[1][1] * key[2][0]);
      tmp[2][1] = -((key[0][0] * key[2][1]) - (key[0][1] * key[2][0]));
      tmp[2][2] = (key[0][0] * key[1][1]) - (key[0][1] * key[1][0]);
      det = 1.00 / (float)deter(key, 3);
      printf("Key matrix :\n");
      for (i = 0; i < size; i++)
	{
	  for (j = 0; j < size; j++)
	    {
	      tmp[i][j] = tmp[i][j] * det;
	      (j != size - 1) ? printf("%lf\t", tmp[i][j]) : printf("%lf", tmp[i][j]);
	    }
	  printf("\n");
	}
      printf("\n");
    }
  else
    {
      exit(84);
    }
  return (tmp);
}

void	decrypt(float **key, int **matrix, int size, int size2)
{
  float	**result;
  int	i, j, l;

  result = malloc(sizeof (float *) * size2);
  for (i = 0; i < size2; i++)
    result[i] = malloc(sizeof (float) * size);
  for (i = 0; i < size2; i++)
    for (l = 0; l < size; l++)
      for (j = 0; j < size; j++)
	result[i][l] = 0;
  for (i = 0; i < size2; i++)
    for (l = 0; l < size; l++)
      for (j = 0; j < size; j++)
	result[i][l] += key[j][l] * (float)matrix[i][j];
  printf("Decrypted message :\n");
  for (i = 0; i < size2; i++)
    for (j = 0; j < size; j++)
      if  ((char)round(result[i][j]) != 0)
	printf("%c", (char)round(result[i][j]));
  printf("\n");
  for (i = 0; i < size2; i++)
    free(result[i]);
  free(result);
}

void	encrypt(int **key, int **matrix, int size, int size2)
{
  int	**result;
  int	i, j, l;

  result = malloc(sizeof (int **) * size2);
  for (i = 0; i < size2; i++)
    result[i] = malloc(sizeof (int *) * size);
  for (i = 0; i < size2; i++)
    for (l = 0; l < size; l++)
      for (j = 0; j < size; j++)
	result[i][l] = 0;

  for (i = 0; i < size2; i++)
    for (l = 0; l < size; l++)
      {
	for (j = 0; j < size; j++)
	  result[i][l] += key[j][l] * matrix[i][j];
	(i == size2 - 1 && l == size - 1) ? printf("%d", result[i][l]) : printf("%d ", result[i][l]);
      }
  printf("\n");
  for (i = 0; i < size2; i++)
    free(result[i]);
  free(result);
}

int	taille2(char *str)
{
  int	i = 0, j = 1;

  while (str[i])
    {
      if (str[i] == ' ')
	j++;
      while (str[i] == ' ')
	i++;
      i++;
    }
  return (j);
}

int	taille(int size)
{
  int	i = 0;
  while (pow(i, 2) < size)
    i++;
  return (i);
}

int	main(int ac, unsigned char **av)
{
  int	**matrix, **key;
  float	**tmp2;
  int	i, j, k;
  int	size, size2;
  int	*tmp;

  if (ac != 4)
    {
      fprintf(stderr, "USAGE:\n");
      fprintf(stderr, "\t%s message key flag\n", av[0]);
      fprintf(stderr, "\nDESCRIPTION:\n");
      fprintf(stderr, "\tmessage\ta message made of ASCII characters\n");
      fprintf(stderr, "\tkey\tthe encryption key, made of ASCII characters\n");
      fprintf(stderr, "\tflag\t0 for the message to be encrypted, 1 to be encrypted\n");
      return (84);
    }
  else
    {
      if (av[3][0] == '0')
	{
	  k = 0;
	  size = taille(strlen(av[2]));
	  key = malloc(sizeof(int **) * size);
	  for (i = 0; i < size; i++)
	    key[i] = malloc(sizeof (int *) * size);

	  size2 = (strlen(av[1]) % size == 0) ? (strlen(av[1]) / size) : ((strlen(av[1]) / size) + 1);
	  matrix = malloc(sizeof (int **) * size2);
	  for (i = 0; i < size2; i++)
	    matrix[i] = malloc(sizeof (int *) * size);
	  for (i = 0; i < size; i++)
	    {
	      for (j = 0; j < size; j++)
		{
		  if (av[2][k] != '\0')
		    {
		      key[i][j] = av[2][k];
		      k++;
		    }
		  else
		    key[i][j] = 0;
		}
	    }
	  printf("Key matrix :\n");
	  for (i = 0; i < size; i++)
	    {
	      for (j = 0; j < size; j++)
		(j != size - 1) ? printf("%d\t", key[i][j]) : printf("%d", key[i][j]);
	      printf("\n");
	    }
	  printf("\n");
	  printf("Encrypted message :\n");
	  k = 0;
	  for (i = 0; i < size2; i++)
	    {
	      for (j = 0; j < size; j++)
		{
		  if (av[1][k] != '\0')
		    {
		      matrix[i][j] = av[1][k];
		      k++;
		    }
		  else
		    matrix[i][j] = 0;
		}
	    }
	  encrypt(key, matrix, size, size2);
	  for (i = 0; i < size; i++)
	    free(key[i]);
	  free(key);
	  for (i = 0; i < size2; i++)
	    free(matrix[i]);
	  free(matrix);
	  return (0);
	}
      else if (av[3][0] == '1')
	{
	  size = taille(strlen(av[2]));
	  key = malloc(sizeof(int **) * size);
	  for (i = 0; i < size; i++)
	    key[i] = malloc(sizeof (int *) * size);

	  size2 = (strlen(av[1]) % size != 0) ? (taille2(av[1]) / size) : ((taille2(av[1]) / size));
	  matrix = malloc(sizeof (int **) * size2);
	  for (i = 0, k = 0; i < size; i++)
	    {
	      for (j = 0; j < size; j++)
		{
		  if (av[2][k] != '\0')
		    {
		      key[i][j] = av[2][k];
		      k++;
		    }
		  else
		    key[i][j] = 0;
		}
	    }
	  for (i = 0; i < size2; i++)
	    matrix[i] = malloc(sizeof (int *) * size);
	  i = 0, j = 1, k = 0;
	  tmp = malloc (sizeof (int *) * taille2(av[1]));
	  while (av[1][i])
	    {
	      if (av[1][i] == ' ' || j)
		{
		  j = 0;
		  while (av[1][i] == ' ')
		    i++;
		  tmp[k] = atoi(&av[1][i]);
		  k++;
		}
	      if (!isdigit(av[1][i]))
		{
		  exit(84);
		}
		  i++;
	    }
	  for (i = 0, k = 0; i < size2; i++)
	    for (j = 0; j < size; j++)
	      matrix[i][j] = tmp[k++];
	  decrypt(inverse(key, size), matrix, size, size2);
	  for (i = 0; i < size; i++)
	    free(key[i]);
	  free(key);
	  for (i = 0; i < size2; i++)
	    free(matrix[i]);
	  free(matrix);
	  free(tmp);
	  return (0);
	}
      else
	{
	  return (84);
	}
    }
}
