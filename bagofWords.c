#include <sys/types.h>
#include <dirent.h>
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
double bagofWords(char astr[1000],char bstr[1000]);
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
            // printf("%s\n",g[k] );
        }
        fclose(fp);
    }
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("##########:::Displaying Bag of Words Matrix:::##########\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    /*Loop to display bag of words matrix*/
    int q=0;
    printf("  \t\t");
    while(q<fcount){
        printf("File %d:\t\t",q+1);
        q++;
    }
    printf("\n\n");
    for(int i=0;i<fcount;i++){
        printf("File %d: ",i+1);
        for(int j=0;j<fcount;j++){
            printf("|%lf\t",bagofWords(g[i],g[j]));
        }
        printf("\n");
    }   
    return 0;
}
/*Bag of Words
This functions extracts all the words from 2 files and stores them into lists.
It then compares the unique words in both files to the words which are available in each file. Thus, creating a frequency vector for each file.
Now, a formaula can be applied taking sum of squares of frequency vecotrs and dot product of frequency vectors.*/
double bagofWords(char astr[1000],char bstr[1000]){
    if(strcmp(astr,bstr)==0){
        return 0;
    }
    else{
    /*Declaration of variables*/
    char com[100];
    strcat(com,astr);
    strcat(com,bstr);
    char alist[100][100]={0};
    char blist[100][100]={0};
    char clist[100][100]={0};
    int i,j=0,k=0,l;
    int p,q=0,r=0,m;
    int x,y=0,z=0,n;
    l=strlen(astr);
    m=strlen(bstr);
    n=strlen(com);
    /*Splitting Function on line 1 here*/
    for(i=0;i<l;i++){
        if(astr[i]==' '){
            if(astr[i+1]!=' '){
                alist[k][j]='\0';
                j=0;
                k++;
            }
            continue;
        }
        else{
            alist[k][j++]=astr[i];
        }
    }
    alist[k][j]='\0';
    /*Splitting Function on line 2 here*/
    for(p=0;p<m;p++){
        if(bstr[p]==' '){
            if(bstr[p+1]!=' '){
                blist[r][q]='\0';
                q=0;
                r++;
            }
            continue;
        }
        else{
            blist[r][q++]=bstr[p];
        }
    }
    blist[r][q]='\0';
    /*Splitting Combined List*/
    for(x=0;x<n;x++){
        if(com[x]==' '){
            if(com[x+1]!=' '){
                clist[z][y]='\0';
                y=0;
                z++;
            }
            continue;
        }
        else{
            clist[z][y++]=com[x];
        }
    }
    clist[z][y]='\0';
    //Vector finder -A
    int fruw[100],fr1[100],fr2[100];
    char uw[100][100];
    /*Counting frequencty of all words*/
    for(int ae=0;ae<=z;ae++){
        for(int ar=ae+1;ar<=z;ar++){
            if(strcmp(clist[ae],clist[ar])==0){
            fruw[ae]++;
            }
        }
    }
    /*Filtering Unique Words*/
    int mini_count=0,euc1=0,euc2=0,sim[100]={0};
    float dot=0;
    for(int at=0;at<=z;at++){
        if(fruw[at]==0){
            strcpy(uw[mini_count++],clist[at]);
        }
    }
    /*Extracting frequency vector 1*/
    for(int ay=0;ay<mini_count;ay++){
        fr1[ay]=0;
        for(int au=0;au<=k;au++){
            if(strcmp(uw[ay],alist[au])==0){
                fr1[ay]++;
            }
        }
        euc1+=(fr1[ay]*fr1[ay]);
    }
    /*Extracting frequency vector 2*/
     for(int aa=0;aa<mini_count;aa++){
        fr2[aa]=0;
        for(int as=0;as<=k;as++){
            if(strcmp(uw[aa],blist[as])==0){
                fr2[aa]++;
            }
        }
        euc2+=(fr2[aa]*fr2[aa]);
    }
    /*Extracting dot product*/
    for(int ad=0;ad<mini_count;ad++){
        sim[ad]=fr1[ad]*fr2[ad];
        dot+=sim[ad];
    }
    double bag=dot*100/sqrt(euc1*euc2);
    return bag;
    }
}