/*Made with Coffee 
by: Joel Vinay Kumar
MSIT, 20176109*/
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
void fingerPrinting(char a[1000],char b[1000]);
int indpow(int a,int b){
	int temp=1;
	for(b=0;b<=a;b++){
		temp*=a;
	}
	return temp;
}
int main(){
	/* code */
	char a[1000]="this that when";
	char b[1000]="doubt truth to be a liar";
	fingerPrinting(a,b);
	return 0;
}
void fingerPrinting(char* a,char* b){
	/*Declaring variables*/
	char alist[100][1000]={0};
	char blist[100][1000]={0};
	int i,j=0,k=0,l;
	int p,q=0,r=0,m;
	l=strlen(a);
	m=strlen(b);
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
	char fstr[1000000];
	for(int as=0;as<=k;as++){
		strcat(fstr,alist[as]);
	}
	for(int ad=0;ad<=r;ad++){
		strcat(fstr,blist[ad]);
	}
	/*Extracting hash values
	k-gram is 4*/
	int kgram=4,tmp;
	long long int hash[1000];
    for(int looper=0;looper<strlen(fstr)-3;looper++){
    	int index=4;
    	for(int inside_looper=looper;inside_looper<looper+4;inside_looper++){
    		tmp=pow(10,--index);
    		hash[looper]+=((int)fstr[inside_looper]*tmp);
    	}
    	hash[looper]=hash[looper]%10007;
    }
    int count=0;
    int limit=strlen(fstr)-3;
    for(int aq=0;aq<limit-1;aq++){   		
    	for(int h=aq;h<limit;h++){
    		if(hash[aq]==hash[h]){
    			count++;
    		}
    	}
    }
    printf("%d\n",count);
}