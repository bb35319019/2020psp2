#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
  double ave_online(double val, double ave_old, int n)
  {
    double ave_new;
    ave_new = (n-1)*ave_old + val;
    ave_new = ave_new/n;
    return ave_new;
  }
int main(void){
    double val,ave=0,std_err,average,var,var_online,ave2=0,ave__online,Z;
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
        ave=ave_online(val,ave,n);
        ave2=ave_online(pow(val,2),ave2,n);
        var=ave2-pow(ave,2);
    }
    average=ave;
    ave__online=average;
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
