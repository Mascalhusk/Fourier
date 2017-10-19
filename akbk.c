#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void coeficientes(double *x, double *y, int l, char *saida)
{	FILE* output;
	double *a, *b, *akbk, somacosseno, somaseno;
	int k, j;
   
	a = malloc(l*sizeof(double));
	b = malloc(l*sizeof(double));
	akbk = malloc(l*sizeof(double));
  
	output = fopen(saida, "w");
  
  	somacosseno = somaseno = 0. ;
  	for(k=0;k<l;k++)
  	{	
  		for(j=0;j<l-1;j++)
      		{  
      		somacosseno = somacosseno + y[j]*cos((k)*x[j]);
    		somaseno = somaseno + y[j]*sin((k)*x[j]);		 
   		} 
   	   
   	  	printf("Soma seno :%lf\n", somaseno);
    		printf("Soma cosseno :%lf\n",somacosseno);	
        	a[k] = (1/l)*(somacosseno);
     		b[k] = (1/l)*(somaseno);
        	akbk[k] = pow(a[k], 2) + pow(b[k],2);
        	printf("a[%d]=%.10lf\t b[%d]=%.10lf\t a[%d]²+b[%d]²=%lf \n\n", k, a[k], k, b[k], k, k, akbk[k]); 
        	fprintf(output, "%lf\t  \n", akbk[k]); 
	} 
}

int main(int argc, char **argv)
{ 
    FILE *input;
    int i, l;
    double *x, *y;
    
    x = malloc(10000*sizeof(double));
    y = malloc(10000*sizeof(double));
    
    input = fopen(argv[1], "r");
    if(!input)
    {	
    	printf("Erro na Leitura do Arquivo: \n");
    	exit(1);	
    }
    i=0;
    while(fscanf(input, "%lf %lf", &x[i], &y[i]) !=EOF) i++;
    l=i;
    
    x=realloc(x, l*sizeof(*x));
    y=realloc(y, l*sizeof(*y));
    
    coeficientes(x,y,l,argv[2]);   
}
