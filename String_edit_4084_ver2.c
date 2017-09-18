#include<stdio.h>
#include<string.h>

//D-cost(DELETE)
//I=cost(INSERTION)
//S=cost(SUBSTITUITION)

int I,D,S,W;
int edit_dist(char s1[], char s2[] ,int m,int n)
{
int C[m+1][n+1];
char op[m+1][n+1];
printf("\n***** m=%d ***** n=%d *****\n",m,n);
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
			} else if ((C[i-1][j]+D)<C[i][j]) {
				printf("\nDELETE");
			    C[i][j]=C[i-1][j]+D;
				op[i][j]= 'D';
			} else if ((C[i][j-1]+I)<C[i][j])
			{
			    printf("\nINSERTION");
				C[i][j]=C[i][j-1]+I;
				op[i][j]= 'I';
			}
		}
}

printf("\n\n\t***THE COST MATRIX IS %dx%d*******",m,n);
for(i=0;i<=m;i++) {
        printf("\n");
 	for(j=0;j<=n;j++){
 		printf("\t%d",C[i][j]);

 	}
}
printf("\n\n\t***THE OPERATIONS MATRIX IS*******");
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
	printf("\n\n ENTER COST OF INSERTION : ");
	scanf("%d",&I);
	printf("\n\n ENTER COST OF DELETE : ");
	scanf("%d",&D);
	printf("\n\n ENTER COST OF SUBSTITUITION WITH SAME CHAR : ");
	scanf("%d",&S);
	printf("\n\n ENTER COST OF SUBSTITUITION WITH DIFF CHAR : ");
	scanf("%d",&W);
printf("\n*****I=%d*****D=%d*****S=%d*****W=%d*****\n",I,D,S,W);

int result = edit_dist(s1, s2,m,n);
   printf("\n\nTOTAL COST OF OPERATIONS IS ::::  %d\n",result);

}
