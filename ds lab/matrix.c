#include<stdio.h>
int main(){
    int matrix[10][10],triplet[50][3],transpose[50][3];
    int i,j,m,n,k=1;
    printf("enter row and coloumns");
    scanf("%d%d",&m,&n);
    printf("enter matrix elements\n");
    for(j=0;j<m;j++){
        for(i=0;i<n;i++){
            scanf("%d",&matrix[j][i]);
        }
    }
    //converting to triplet form
    triplet[0][0]=m;
    triplet[0][1]=n;
    triplet[0][2]=0;
    for(j=0;j<m;j++){
        for(i=0;i<n;i++){
            if(matrix[j][i]!=0){
                triplet[k][0]=j;
                triplet[k][1]=i;
                triplet[k][2]=matrix[j][i];
                k++;
                triplet[0][2]++;
            }
        }
    }
    printf("\ntriplet resprestion:\n");
    for (i=0;i<k;i++){
        printf("%d %d %d\n",triplet[i][0],triplet[i][1],triplet[i][2]);
    
    }
    //transpose
    transpose[0][0]=triplet[0][1];
    transpose[0][1]=triplet[0][0];  
    transpose[0][2]=triplet[0][2];
    k=1;
    
    for (i=0;i<triplet[0][1];i++){
        for(j=1;j<=triplet[0][2];j++){
            if(triplet[j][1]==i){
                transpose[k][0]=triplet[j][1];
                transpose[k][1]=triplet[j][0];
                transpose[k][2]=triplet[j][2];
                k++;
            }
        }
    }
    printf("\ntranspose of triplet representation:\n");
    for (i=0;i<k;i++){
        printf("%d %d %d\n",transpose[i][0],transpose[i][1],transpose[i][2]);
    }
 return 0;
}