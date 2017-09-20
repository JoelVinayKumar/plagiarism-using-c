#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include "math.h"
#include <sys/types.h>
#include <dirent.h>
FILE *fp;
int fcount=0;
char name[1000][1000];
char file[1000][1000];
char txt[1000],g[1000][1000];
/*Scanning directories
We make sure our directory has only .txt files.
Then we try to read those files and store them into a file array.
These can be accessed later to get strings from files.*/
static void scan_dir(const char *dir){
    struct dirent * entry;
    int c=0,ff=0;
    DIR *d = opendir( dir );
    if (d == 0) 
    {
       perror("opendir");
       return;
    }
    while ((entry = readdir(d)) != 0) 
    {
        if(c>1)
        {
            fcount+=1;
            strcpy(file[ff],dir);
            strcat(file[ff],entry->d_name);
            strcpy(name[ff],entry->d_name);
            ff+=1;
        }
        c+=1;
    }
    closedir(d);
}
/*A function to use a power b*/
int indpow(int a,int b){
	int res=1;
	for(int temp=1;temp<=b;temp++){
		res*=a;
	}
	return res;
}
/*A function to extract text from .txt files*/
static void fileextract(){
    scan_dir("txt\\");
    /*Loop to acquire all text files to strings*/
    for(int k=0;k<fcount;k++){
        fp=fopen(file[k],"r");
        while(!feof(fp)){
            fgets(txt,100,fp);
            strcpy(g[k],txt);
            strcat(g[k]," ");
        }
        fclose(fp);
    }
}