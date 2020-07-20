#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);

int main(void)
{
    double val,A,B;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double max_val=1,min_val=1;
    double mu_A=170.8,sigma_A=5.43,mu_B=169.7,sigma_B=5.5;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        A=(val - mu_A)/sigma_A;
        B=(val - mu_B)/sigma_B;
        max_val=max_val*p_stdnorm(A);
        min_val=min_val*p_stdnorm(B);
        
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",max_val);
    printf("L_B: %f\n",min_val);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

