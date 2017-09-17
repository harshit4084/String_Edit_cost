#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//D-cost(DELETE)
//I=cost(INSERTION)
//S=cost(SUBSTITUITION)

int I,D,S,W;
int edit_dist(char s1[], char s2[] ,int m,int n)
{
//Creating a distace matrix to store operations
int C[m+1][n+1];
char op[m+1][n+1];
printf("\n****m and n are ****%d *** %d***** \n",m,n);
int i,j;
	for(i=0;i<=n;i++){
		C[i][0]=i*D;
		op[i][0]='D';
	}

	for(j=0;j<=n;j++){
		C[0][j]=j*I;
		op[0][j]='I';
		}
 int inf=1e9;
 for(i=1;i<=m;i++) {
        printf("\n\tTHIS IS %dth ITERATION\n\n",i);
 	for(j=1;j<=n;j++){
			C[i][j]=inf;
			if(s1[i]==s2[j]){
                    printf("\nSUBSTITUITION");
				C[i][j]=C[i-1][j-1]+S;
				op[i][j]='S';
			} else if ((s1[i]!=s2[j]) && (C[i-1][j-1]+S)<C[i][j]) {
				C[i][j]=C[i-1][j-1]+W;
				op[i][j]='W'; //y->s[j]
				printf("\nSUBSTITUITION WITH %c",s2[j]);
				printf("\nTHE COST IS NOW %d",C[i][j]);
			} else if ((C[i-1][j]+D)<C[i][j]) {
			    C[i][j]=C[i-1][j]+D;
				op[i][j]= 'D';
				printf("\nDELETE Cost is %d",C[i][j]);
			} else if ((C[i][j-1]+I)<C[i][j])
			{
			    printf("\nINSERTION");
				C[i][j]=C[i][j-1]+I;
				op[i][j]= 'I';
			}
		}
}
printf("\n\n***THE COST MATRIX IS*******");
for(i=0;i<=m;i++) {
        printf("\n");
 	for(j=0;j<=n;j++){
 		printf("\t%d",C[i][j]);

}
}
printf("\n\n***THE OPERATIONS MATRIX IS*******");
for(i=0;i<=m;i++) {
        printf("\n");
 	for(j=0;j<=n;j++){
 		printf("\t%c",op[i][j]);

}
}

return C[m][n];
}

void main()
{

  /*  // MAIN PROGRAM STARTS HERE
 printf("\n\nENTER str x\n");
 scanf("%s",x->s);
 printf("\n\nENTER str y\n");
 scanf("%s",y->s);
 printf("\n\nstr x IS :::::  %s\n",x->s);
 printf("\n\nstr y IS :::::  %s\n",y->s);
 */
	char s1[100],s2[100];
	int m,n;
    printf("\nENETR STRING 1 ::: ");
    scanf("%s",s1);
    printf("\n\nYOUR STRING 1 IS :: %s",s1);
    m=strlen(s1);
    printf("\n\nLENGTH OF STRING 1 IS :: %d",m);
    printf("\nENETR STRING 2 ::: ");
    scanf("%s",s2);
    printf("\n\nYOUR STRING 2 IS :: %s",s2);
    n=strlen(s2);
    printf("\n\nLENGTH OF STRING 2 IS :: %d",n);
	printf("\n\n ENTER COST OF INSERTION\n");
	scanf("%d",&I);
	printf("\n\n ENTER COST OF DELETE\n");
	scanf("%d",&D);
	printf("\n\n ENTER COST OF SUBSTITUITION WITH SAME CHAR\n");
	scanf("%d",&S);
	printf("\n\n ENTER COST OF SUBSTITUITION WITH DIFF CHAR\n");
	scanf("%d",&W);
printf("\n*****I=%d*****D=%d**********S=%d********\n",I,D,S);

int result = edit_dist(s1, s2,m,n);
   printf("\n\nSOLUTION IS ::::  %d\n",result);

}
