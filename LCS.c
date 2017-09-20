/*Made with Coffee 
by: Joel Vinay Kumar
MSIT, 20176109*/
#include "myFunctions.h"
/*String Match
This function detects the lingest common substring among 2 files and calculates its length.
The ratio of length of longest common substring to the sum of lengths of 2 files gives us the result.*/
double stringMatch(char astr[1000],char bstr[1000]){
    if(strcmp(astr,bstr)==0){
        return 0;
    }
    else{
        int l=strlen(astr),m=strlen(bstr);
        /*Match is used to store temporary word which has got the matching sequence*/
        char match[100];
        /*Answer is used to store the longer word extracted from match*/
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
        /*We remove a character in order to remove the space which is collected*/
        int LCS=strlen(answer)-1;
        double output=(LCS*20)/(l+m);
        return output;
    }
}
int main(int argc, char const *argv[]){
    /*Extracting text from .txt files*/
    fileextract();
    /*Loop to display string match matrix*/
    printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("##########:::Displaying String Match Matrix:::##########\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
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