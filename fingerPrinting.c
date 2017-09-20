/*Made with Coffee 
by: Joel Vinay Kumar
MSIT, 20176109*/
#include "myFunctions.h"
/*FingerPrinting is a technique where we create unique values for all possible word combinations using a k-gram.
In our case, we have k-gram as 4. 
Here, Rabin-Karp algorithm is used to extract hash keys and determine percentage of plagiarism.*/
double fingerPrinting(char a[1000],char b[1000]){
	/*Declaring variables*/
	char alist[100][1000]={0};
	char blist[100][1000]={0};
	int i,j=0,k=0,l;
	int p,q=0,r=0,m;
	l=strlen(a);
	m=strlen(b);
	if(strcmp(a,b)==0){
		return 0;
	}
	else{
	/*Splitting first sentence*/
	for(i=0;i<l;i++){
        if(a[i]==' '){
            if(a[i+1]!=' '){
                alist[k][j]='\0';
                j=0;
                k++;
            }
            continue;
        }
        else{
            alist[k][j++]=a[i];
        }
    }
    alist[k][j]='\0';
    /*Splitting second sentence*/
	for(p=0;p<m;p++){
        if(b[p]==' '){
            if(b[p+1]!=' '){
                blist[r][q]='\0';
                q=0;
                r++;
            }
            continue;
    	}
        else{
            blist[r][q++]=b[p];
	        }
    }
	blist[r][q]='\0';
	/*Full string without spaces*/
	char astr[1000],bstr[1000];
	int as,ad;
	for(as=0;as<=k;as++){
		strcat(astr,alist[as]);
	}
	for(ad=0;ad<=r;ad++){
		strcat(bstr,blist[ad]);
	}
	/*Extracting hash values
	k-gram is 4*/
	int kgram=4,tmp,la,lb,lc,ld,index;
	long long int hash_a[1000],hash_b[1000];
	/*Hash keys for first string*/
    for(la=0;la<strlen(astr)-3;la++){
    	index=4;
    	for(lb=la;lb<la+kgram;lb++){
    		hash_a[la]+=((int)astr[lb]*indpow(10,index--));
    	}
    	hash_a[la]=hash_a[la]%10007;
    }
    /*Hash keys for second string*/
    for(lc=0;lc<strlen(bstr)-3;lc++){
    	index=4;
    	for(ld=lc;ld<lc+kgram;ld++){
    		hash_b[lc]+=((int)bstr[ld]*indpow(10,index--));
    	}
    	hash_b[lc]=hash_b[lc]%10007;
    }
    /*Comparing hash arrays*/
    int count=0;
    for(int x=0;x<la;x++){
    	for(int y=0;y<lc;y++){
    		if(hash_a[x]==hash_b[y]){
    			count++;
    		}
    	}
    }
    double plag= (2*count)*100/(la+lc);
    return plag;
	}
}
int main(int argc, char const *argv[]){
	/*Extracting text from .txt files*/
    fileextract();
    /*Loop to display FingerPrinting matrix*/
    printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("##########:::Displaying FingerPrinting Matrix:::##########\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    int q=0;
    printf("\t\t");
    while(q<fcount){
        printf("File %d:\t\t",q+1);
        q++;
    }
    printf("\n\n");
    for(int i=0;i<fcount;i++){
        printf("File %d: ",i+1);
        for(int j=0;j<fcount;j++){
            printf("|%lf\t",fingerPrinting(g[i],g[j]));
        }
        printf("\n");
    }   
    return 0;
}