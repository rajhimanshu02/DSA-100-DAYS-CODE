#include <stdio.h>
int main(){
    int n;
    int m;
printf("Enter how many numbers for array1:- ");
scanf("%d",&n);
int num1[n];

printf("Enter how many numbers for array2- ");
scanf("%d",&m);
int num2[m];

for(int i=0 ; i<=n ; i++){
    printf("Enter no %d: ",i);
scanf("%d ",&num1[i]);
}

for(int i=0 ; i<=m ; i++){
    printf("Enter no %d: ",i);
scanf("%d ",&num2[i]);
}
for(int j=0 ; j<=n ; j++){
    printf("%d\t",num1[j]);
    for(int k=0 ; k<=m ; k++){
        printf("%d\t",num2[k]);
    }
}

printf("%d",num2);
    return 0;
}