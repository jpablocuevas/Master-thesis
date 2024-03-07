#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcs.h"

// ------------------------ Numerical integration functions -------------------------------

ld integral ( ld (*f)(ld), ld a, ld b, int n){
	
	int i;
	ld dx, s = 0.;
	
	dx = (b-a) / (ld)n;
	
	ld *x;
	
	x = (ld*) calloc (n, sizeof(ld));
	
	for (i = 0; i <= n; i++){
	
		x[i] = a + (ld)i*dx;
	}
	
	
	for (i = 0; i <= n-4; i++){
	
		s = s + f(x[i]);
	}

	ld I, s1, s2;

	s1=17.*f(x[0])+59.*f(x[1])+43.*f(x[2])+49.*f(x[3]);
    	s2=17.*f(x[n])+59.*f(x[n-1])+43.*f(x[n-2])+49.*f(x[n-3]);

	I = dx*(s1+s2+48.*s)/48.;
	
	free (x);

	return I;
}

ld gauss_exp (ld t){

	return exp (-pow(t,2.));
}

ld my_erfc (ld z){
	
	fp gauss_p;
	
	gauss_p = &gauss_exp;
	
	return 1.-(2./sqrt(pi))*integral (*gauss_p, 0, z, 4000);
}

ld x_c (ld alpha){
	
	return 2./alpha;
}

ld my_abs (ld x){
	
	if (x>= 0){
	
		return x;
	}
	
	else {
		
		return -x;
	}
	
	return 0;
} 

// ------------------------ Wolf potential -------------------------------

ld Wolf (ld x, ld alpha) {
	
	if (x >= 1. && x <= x_c (alpha) ){
	
		return -my_erfc (alpha*x) / x+ my_erfc (alpha*x_c (alpha)) / x_c (alpha);
	}
	
	return 0.;
}



// ------------------------ File name functions -------------------------------

char int_to_char (int n){

	char c;

	switch (n){

	case 0:
	    c = '0';
	    break;

	case 1:
	    c = '1';
	    break;

	case 2:
	    c = '2';
	    break;

	case 3:
	    c = '3';
	    break;

	case 4:
	    c = '4';
	    break;

	case 5:
	    c = '5';
	    break;

	case 6:
	    c = '6';
	    break;

	case 7:
	    c = '7';
	    break;

	case 8:
	    c = '8';
	    break;

	case 9:
	    c = '9';
	    break;

	}
    
    return c;
}

int count_digits (int n){

	int i = 1;
	
	while (n / (int) pow(10,i) >= 1){
	
		i++;
	}
	
	return i;
}

char *int_to_str (int n){

	int i, j, count, x = 0;
	
	count = (int) count_digits (n); 

	char *num;
	
	num = (char*) malloc (sizeof(char)*(count+1));
	
	j = count-1;
	
	for (i = 1; i < count +1; i++){ 
	
		num[j] = int_to_char((n % (int) pow (10,i)-x)/ (int) pow (10, i-1)) ;
		
		x = n%(int) pow(10,i);
		
		j--;	
	}
	
	num[count] = '\0';
	
	return num;
}


char *file_name (int n){

	char text[] = ".txt";
	char *name, *num;
	
	int i, num_size = count_digits (n), text_size;
	
	text_size = (int) sizeof(text)/sizeof(text[0]) - 1; // Not counting the null character at the end of the array
	
	num = (char*) int_to_str(n);

	name = (char*) malloc (sizeof(char)* (num_size+text_size+1)); // The plus one is added to account for the extra null character, although it can be ommited since text_size already accounts for this, yet it is kept for consistency.
	
	for (i = 0; i < num_size; i++){
	
		name [i] = num[i];
	}
	
	int j = 0;
	
	for (i = num_size; i < num_size+text_size; i++){
	
		name [i] = text[j];
		
		j++;
	}
	
	name [num_size+text_size] = '\0';
	
	return name;

}





