#include "stdio.h"
#include "conio.h"
#include "string.h"
int main(int argc, char const *argv[])
{
	/* code */
	int n;
	scanf("%d",&n);
	int matrix[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",matrix[i][j]);
		}
	}
	return 0;
}