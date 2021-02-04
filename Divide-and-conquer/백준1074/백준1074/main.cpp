//
//  main.cpp
//  백준1074
//
//  Created by 유영우 on 2021/02/03.
//

#include <iostream>
#include <cmath>
using namespace std;
int n,r,c,cnt;
void order(int y,int x,int size){
    if(size == 1){
        printf("%d",cnt) ;
        return;
        }
    else{
        int dv = size/2;
        if(r>=y && r<y+dv && c>=x && c<x+dv){
            order(y,x,dv);
        }
        else if(r>=y && r<y+dv && c>=x+dv && c<x+size){
            cnt+=dv*dv;
            order(y,x+dv,dv);
        }
        else if(r>=y+dv && r<y+size && c>=x && c<x+dv){
            cnt+=2*dv*dv;
            order(y+dv,x,dv);
        }
        else{
            cnt+=3*dv*dv;
            order(y+dv,x+dv,dv);
        }
    }
}

int main(void) {
    scanf("%d %d %d",&n,&r,&c);
    // r = y
    // c = x
    order(0,0,pow(2, n));
    
    return 0;
}
