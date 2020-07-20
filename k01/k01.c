#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double n;
extern double ave_online(double val,double ave);
extern double var_online(double val,double ave,double ave2);
int main(void)
{
    double val,ave=0,var=0,ave2=0,s_var;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

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
        n=n+1;
        ave=ave_online(val,ave);
        var=var_online(var,ave,ave2);
        ave2=ave_online(pow(val,2),ave2);
    }
    
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
     printf("%f\n,n");
     s_var=(n/(n-1))*var;
     printf("Average:%f\n",ave);
     printf("Var:%f\n",var);
     printf("Suitei_Average:%f\n",ave);
     printf("Suitei_Var:%f\n",s_var);

    return 0;


}

