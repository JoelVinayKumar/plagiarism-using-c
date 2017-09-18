#include <sys/types.h>
#include <dirent.h>
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
double bagofWords(char astr[1000],char bstr[1000]);
double stringMatch(char astr[1000],char bstr[1000]);
int fcount=0;
char name[1000][1000];
char file[1000][1000];
/*Scanning directories
We make sure our directory has only .txt files.
Then we try to read those files and store them into a file array.
These can be accessed later to get strings from files.*/
static void scan_dir(const char *dir){
    struct dirent * entry;
    DIR *d = opendir( dir );
    int c=0,ff=0;
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
int main()
{
    FILE *fp;
    scan_dir("txt\\");
    char txt[1000],g[1000][1000];
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
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("##########:::Displaying String Match Matrix:::##########\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    /*Loop to display string match matrix*/
    int w=0;
    printf("  \t\t");
    while(w<fcount){
        printf("File %d:\t\t",w+1);
        w++;
    }
    printf("\n\n");
    for(int e=0;e<fcount;e++){
        printf("File %d: ",e+1);
        for(int r=0;r<fcount;r++){
            printf("|%lf\t",stringMatch(g[e],g[r]));
        }
        printf("\n");
    }    
    return 0;
}
/*String Match
This function detects the lingest common substring among 2 files and calculates its length.
The ratio of length of longest common substring to the sum of lengths of 2 files gives us the result.*/
double stringMatch(char astr[1000],char bstr[1000]){
    if(strcmp(astr,bstr)==0){
        return 0;
    }
    else{
        int l=strlen(astr),m=strlen(bstr);
        char match[100];
        char answer[100];
        char c[10];
        /*LCS function*/
        for(int i=0;i<l;i++){
            strcpy(match,"");
            for(int j=0;j<m;j++){
                if(i+j<l && astr[i+j]==bstr[j]){
                    c[0]=bstr[j];
                    strcat(match,c);
                }
                else{
                    if(strlen(match)>=strlen(answer)){
                        strcpy(answer,match);
                    }
                strcpy(match,"");
                }
            }
        }
        int LCS=strlen(answer)-1;
        double output=(LCS*20)/(l+m);
        return output;
    }
}