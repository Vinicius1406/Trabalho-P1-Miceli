#include <stdio.h>
#include <stdbool.h>

int main(){
    int n,a = 0;
    int array[100];
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        for(int j = 2;j < n;j++){
            if(i%j == 0){
                continue;
            }
            else{
                array[i] = i;
                a += 1;
            }

        }
    }
    for(int i = 1;i <= n;i++){
        printf("%d",array[i]);
    }
    return 0;
}
    
