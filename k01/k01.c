#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void){
    double val,ave=0,std_err,average,var,ave_online,var_online,ave2=0;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int n;
    n=0;
    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);
    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    while(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%lf",&val);
        n++;
        ave=((n-1)*ave+val)/n;
        ave2=((n-1)*ave2+val*val)/n;
        var=ave2-ave*ave;
    }
    average=ave;
    ave_online=average;
    var_online=n*var/(n-1);
    std_err=pow(var_online/n,0.5);
    if(fclose(fp)==EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    printf("Average=%.2lf\n",average);
    printf("Var=%.2lf\n",var);
    printf("Suitei_average=%.2lf,std_err=%.2lf\n",average,std_err);
    printf("Suitei_var=%.2lf\n",var_online);
    return 0;
}
