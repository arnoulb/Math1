/*
** 101pong.c for 101pong in /home/willai_n/rendu/101pong
**
** Made by noah willaime
** Login   <willai_n@epitech.net>
**
** Started on  Tue Nov 24 10:39:32 2015 noah willaime
** Last update Thu Dec  3 16:21:30 2015 Arnould Jean-Michel
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	angle(float *vecteur)
{
  float	cos;
  float scal;
  float	val;

  scal = sqrt(pow(vecteur[0], 2) + pow(vecteur[1], 2));
  if (!sqrt(pow(vecteur[0], 2) + pow(vecteur[1], 2) + pow(vecteur[2], 2)))
    return (84);
  cos = scal / sqrt(pow(vecteur[0], 2) + pow(vecteur[1], 2) + pow(vecteur[2], 2));
  cos = acos(cos);
  val = cos * (180/M_PI);
  printf("%.2f\n", val);
  return (0);
}

int	pong(float *cord, int n)
{
  float	vecteur[3];
  float npoint[3];
  int	i;

  i = 0;
  while (i < 3)
    {
      vecteur[i] = cord[i + 3] - cord[i];
      i++;
    }
  printf("The speed vector coordinates are :\n");
  printf("(%.2f;%.2f;%.2f)\n", vecteur[0], vecteur[1], vecteur[2]);
  i = 0;
  while (i < 3)
    {
      npoint[i] = ((vecteur[i] * n) + cord[i + 3]);
      i++;
    }
  printf("At time t+%d, ball coordinates will be :\n", n);
  printf("(%.2f;%.2f;%.2f)\n", npoint[0], npoint[1], npoint[2]);
  if (vecteur[2] > 0 && cord[5] < 0 && npoint[2] >= 0
      || vecteur[2] < 0 && cord[5] > 0 && npoint[2] <= 0)
    {
      printf("The incidence angle is :\n");
      return (angle(vecteur));
    }
  else
    printf("The ball won't reach the bat.\n");
  return (0);
}

int	main(int ac, char **av)
{
  float	a[7];
  int	i;
  int	j;

  i = 0;
  if (ac != 8){
    fprintf(stderr, "USAGE:\n");
    fprintf(stderr, "\t%s x0 y0 z0 x1 y1 z1 n\n", av[0]);
    fprintf(stderr, "\nDESCRIPTION:\n");
    fprintf(stderr, "\tx0\t ball abscissa at time t - 1\n");
    fprintf(stderr, "\tx0\t ball ordinate at time t - 1\n");
    fprintf(stderr, "\tx0\t ball altitude at time t - 1\n");
    fprintf(stderr, "\tx1\t ball abscissa at time t\n");
    fprintf(stderr, "\ty1\t ball ordinate at time t\n");
    fprintf(stderr, "\tz1\t ball altitude at time t\n");
    fprintf(stderr, "\tn\ttime shift (grater than or equal to zero, integer)\n");
    return (84);
  }
  while (i < 7)
    {
      for (j = 0; av[i + 1][j]; j++)
      	{
      	  if (isalpha(av[i + 1][j]))
      	    return (84);
      	}
      a[i] = atof(av[i + 1]);
      i++;
    }
  if (atof(av[i]) < 0 || atof(av[i]) != atoi(av[i]))
    return (84);
  else
    {
      for (j = 0; av[i][j]; j++)
      	{
      	  if (isalpha(av[i][j]))
      	    return (84);
      	}
    return (pong(a, atoi(av[i])));
    }
}
