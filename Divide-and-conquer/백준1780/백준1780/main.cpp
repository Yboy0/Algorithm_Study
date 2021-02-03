//
//  main.cpp
//  백준1780
//
//  Created by 유영우 on 2021/02/02.
//

#include <iostream>
using namespace std;

int mone,zero,pone;
int num;
int n;
int tmp;
int arr[2187][2187];

void paper(int x,int y, int sz){
    bool no = false;
    tmp = arr[y][x];
    for(int i=y; i<y+sz; i++){
        for(int j=x; j<x+sz; j++){
            if(arr[i][j] != tmp){
                no = true;
                break;
            }
        }
        if(no){
            break;
        }
    }
   
    if(!no){
        if(tmp == -1){
            mone++;
        }
        else if(tmp == 0){
            zero++;
        }
        else{
            pone++;
        }
        return;
    }
    else{ //no가 true일때
        int odv = sz/3;
        int tdv = 2*(sz/3);
        paper(x,y,odv);
        paper(x+odv,y,odv);
        paper(x+tdv,y,odv);
        paper(x,y+odv,odv);
        paper(x+odv,y+odv,odv);
        paper(x+tdv,y+odv,odv);        
        paper(x,y+tdv,odv);
        paper(x+odv,y+tdv,odv);
        paper(x+tdv,y+tdv,odv);
        return;
    }
    
        
}
int main(void) {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> num;
            arr[i][j]=num;
        }
    }
    
    paper(0,0,n);
    
    cout << mone << endl;
    cout << zero << endl;
    cout << pone << endl;
    return 0;
}
