## Mathématiques - Année 1 - Projets scolaires

- ** 101pong : Vecteurs (C)**

```
USAGE:
	./101pong x0 y0 z0 x1 y1 z1 n

DESCRIPTION:
	x0	 ball abscissa at time t - 1
	x0	 ball ordinate at time t - 1
	x0	 ball altitude at time t - 1
	x1	 ball abscissa at time t
	y1	 ball ordinate at time t
	z1	 ball altitude at time t
	n      time shift (grater than or equal to zero, integer)

```
- **102cipher : chiffrement matriciel (C)**

```
 USAGE:
	./102cipher message key flag

DESCRIPTION:
	message	a message made of ASCII characters
	key	the encryption key, made of ASCII characters
	flag	0 for the message to be encrypted, 1 to be encrypted

```
- **103architect : transformations dans l'espace (Python2)**

```
USAGE:
	./103architect x y transfo1 arg11 [arg12] [transfor2 arg12 [arg22]]
DESCRIPTION
	x	abscissa of the original point
	y	ordinate of the original point
transo arg1 [arg2]
	-t i j	translation along the coordinate vector (i,j)
	-h m n	homothety with center 0 and scale factors m along x-axis and n along y-axis
	-r a	rotation centered in O at angle a degrees
	-s a	symmetry about the axis passing by 0 and inclined with an a-degree angle
```

- **104intersection : 3dimensions et equation quadratique (Python2)**

```
USAGE:
	./104intersection opt xp yp zp xv yv zv p
DESCRIPTION
	opt	number of the option : 1 for a sphere, 2 for a cylinder, 3 for a cone
	(xp, yp, zp)	coordinates of the point by which the light ray goes through
	(xv, yv, zv)	coordinates of the direction vector of the light ray
	p	parameter : radius of the sphere, radius of the cylinder or angle formed by the cone and the Z-axis
```

- **105torus : Résolution d'équation du 4eme degré (Python2)**

```
USAGE:
	./105torus opt a0 a1 a2 a3 a4 n
DESCRITPION
	opt	number of the option :
			1 for the bisection method
			2 for the Newton's method
			3 for the secant method
	a0,a1,a2,a3,a4	coefficients of the equation
	n	precision
```

- **107transfert : Fonction de tranfert (Ruby)**

```
USAGE
./107transfer [num den]
DESCRIPTION
num	polynomial numerator defined by its coeficients
den	polynomial denominator defined by its coeficients
```

- **108trigo : Application de fonction fondamentales (sin, cos, ln(x), ...) à des matrice (Ruby)**

```
USAGE
	./108trigo fun a0 a1 a2...
DESCRIPTION
	fun	function to be applied, among at least "EXP", "COS", "SIN", "COSH", "SINH", "LN+", "LN-", "1/X+" and "1/X-"
	ai	coeficients of the matrix
```

- **109titration : titrage par méthode des dérivées et par tangentes parallèles (Ruby)**

```
USAGE
	./109titration file
DESCRIPTION
	file	acsv containing "vol;ph" lines
```

- **110Borwein : Calcul d'intégrale (Ruby)**

```
USAGE
	./110borwein n
DESCRIPTION
	n	constant defining the integral to be computed
```
