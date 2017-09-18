#include <sys/types.h>
#include <dirent.h>
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
int fcount=0;
char name[1000][1000];
char file[1000][1000];
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
    scan_dir("/media/tonystark/WINDOWS/Users/lavot/OneDrive/MSIT/04-CSPP-2/Plagiarism/txt/");
    char txt[1000],g[1000][1000];
    /*Loop to acquire all text files to strings*/
    for(int k=0;k<fcount;k++){
        fp=fopen(file[k],"r");
        while(!feof(fp)){
            fgets(txt,100,fp);
            strcpy(g[k],txt);
            strcat(g[k]," ");
            printf("%s\n",g[k] );
        }
        fclose(fp);
    }
}