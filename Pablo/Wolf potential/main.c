#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"

int main (void){

	ld alpha[4] = {0.3,0.5,0.7,1.};
	ld *r;
	ld dx, sigma = 1., a = 1., b = 6.;
	
	int i, j, n = 100;
	
	r = (ld*) calloc (sizeof(ld), n);
	
	dx = my_abs (b-a) / (ld)n; 
	
	
	for (i = 0; i < n; i++){
	
		r[i] = 1. + i*dx;

	}
	
	FILE *data;
	
	for (i = 0; i < sizeof(alpha)/sizeof(alpha[0]); i++){
	
		data = fopen (file_name(i), "w");
		
		for (j = 0; j < n; j++){
		
			fprintf(data, " %Lf \t %Lf \n", r[j]/sigma, Wolf (r[j]/sigma, alpha[i]));
		
		}
		
		fclose (data);
	
	}
	
	free (r);

	return 0;
}
