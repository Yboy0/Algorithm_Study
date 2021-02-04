//
//  main.cpp
//  백준2447
//
//  Created by 유영우 on 2021/02/04.
//

#include <iostream>
using namespace std;
int n;
char arr[6600][6600];
void star(int y, int x,int size){
    if(size == 3){
        for(int i=y;i<y+size;i++){
            for(int j=x;j<x+size;j++){
                if(!(i==y+size/2 && j==x+size/2)){
                    arr[i][j] = '*';
                }
            }
        }
        return;
    }
    else{
        int sz = size/3;
        
        star(y,x,sz);
        star(y,x+sz,sz);
        star(y,x+2*sz,sz);
        
        star(y+sz,x,sz);
        star(y+sz,x+2*sz,sz);
        
        star(y+2*sz,x,sz);
        star(y+2*sz,x+sz,sz);
        star(y+2*sz,x+2*sz,sz);
        
    }
}
int main(void) {
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = ' ';
        }
    }
    star(0,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
