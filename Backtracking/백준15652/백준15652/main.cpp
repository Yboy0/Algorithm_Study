//
//  main.cpp
//  백준15652
//
//  Created by 유영우 on 2021/02/01.
//

#include <iostream>
using namespace std;

int n,m;
int cnt;
int arr[9];
void sequence(int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    else{
        for(int i=1; i<n+1; i++){
            if(cnt==0){
                arr[cnt]=i;
                sequence(cnt+1);
            }
            if(cnt>0 && arr[cnt-1] <= i){
                arr[cnt]=i;
                sequence(cnt+1);
            }
        }
    }
}

int main(void) {
    scanf("%d %d",&n,&m);
    sequence(cnt);
   
    return 0;
}
