#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int num=15;
struct DATA
{
    int ID;
    int gender;
    double heights;
};
int main(void){
    char fname[FILENAME_MAX];
    char buf[256];
    FILE * fp;
    int n=0;
    struct DATA sample[num];
    int gender,ID;
    double height;
    int w_ID;
    printf("input the filename of sample heights ?:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    printf("the filename of sample heigths: %s\n",fname);
    fp=fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    while(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%d,%lf",&gender,&height);
        sample[n-1].gender=gender;
        sample[n-1].heights=height;
        n=n+1;
    }
    if(fclose(fp)==EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    printf("input the filename of sample ID ?:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    printf("the filename of sample ID: %s\n",fname);
    fp=fopen(fname,"r");
    if (fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    n=0;
    while(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%d",&ID);
        sample[n].ID=ID;
        n=n+1;
    }
    if(fclose(fp)==EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    printf("Which ID's date do you want?:");
    scanf("%d",&w_ID);
        int i=0,j=0;
        while(i<=num){
            if(sample[i].ID==w_ID){
                if(sample[i].gender==1){
                    printf("---\nID:%d\ngender:Female\nheigths:%.2lf\n",sample[i].ID,sample[i].heights);
                }
                else{
                    printf("---\nID:%d\ngender:Female\nheights:%.2lf\n",sample[i].ID,sample[i].heights);
                }
                               }
                               else{
                                   j=j+1;
                               }
                                   i=i+1;
                               
            }
if(j==i){
    printf("---\nNo Date");
}
return 0;
}