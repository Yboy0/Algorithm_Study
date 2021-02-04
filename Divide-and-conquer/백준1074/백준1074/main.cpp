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
void order(int y,int x,int siz){
    if(siz == 2){
        if(r>=y && r<=y+siz && c>=x && c<=x+siz){
            if(c>x){
                cnt++;
            }
            if(r>y){
                cnt+=2;
            }
            printf("%d",cnt) ;
            return;
        }
        else{
            cnt+=siz*siz;
        }
    }
    else{
        int dv = siz/2;
        order(y,x,dv);
        order(y,x+dv,dv);
        order(y+dv,x,dv);
        order(y+dv,x+dv,dv);
    }
}

int main(void) {
    scanf("%d %d %d",&n,&r,&c);
    // r = y
    // c = x
    order(0,0,pow(2, n));
    
    return 0;
}
