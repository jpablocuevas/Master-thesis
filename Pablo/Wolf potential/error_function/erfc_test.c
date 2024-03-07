#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static double pi = 3.1415926535;


double integral ( double (*f)(double), double a, double b, int n){
	
	int i;
	double dx = (b-a)/n, s = 0.;
	
	double *x;
	
	x = (double *) calloc (n, sizeof(double));
	
	for (i = 0; i <= n; i++){
	
		x[i] = a + (double)i*dx;
	}
	
	
	for (i = 0; i <= n-4; i++){
	
		s = s + f(x[i]);
	}

	double I, s1, s2;

	s1=17.*f(x[0])+59.*f(x[1])+43.*f(x[2])+49.*f(x[3]);
    	s2=17.*f(x[n])+59.*f(x[n-1])+43.*f(x[n-2])+49.*f(x[n-3]);

	I = dx*(s1+s2+48.*s)/48.;
	
	free (x);

	return I;
}

double gauss_exp (double t){

	return exp (-pow(t,2));
}

double erfc (double z){
	
	double (*f) (double);
	
	f = &gauss_exp;
	
	return (2./sqrt(pi))*integral (*f, 0, z, 3500);
}




int main (void){

	printf ("erfc (1) = %lf \n", erfc(1.));

	

	return 0;
}









