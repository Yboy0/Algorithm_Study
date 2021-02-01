//
//  main.cpp
//  백준2630
//
//  Created by 유영우 on 2021/02/01.
//

#include <iostream>
using namespace std;

int n;
int num;
int white;
int black;
bool no;
int tmp;
int dt[128][128];

void cutting(int r,int rd, int c,int cd){
    no=false;
    tmp = dt[c][r];
    for(int i=c; i<cd; i++){
        for(int j=r; j<rd; j++){
            if(dt[i][j] != tmp){
                no = true;
                break;
            }
        }
        if(no){
            break;
        }
    }
    if(!no){
        if(tmp == 1){
            black ++;
        }
        else{
            white ++;
        }
        return;
    }
    
    else{
        cutting(r,(rd+r)/2,c,(cd+c)/2);
        cutting((rd+r)/2,rd,c,(cd+c)/2);
        cutting(r,(rd+r)/2,(cd+c)/2,cd);
        cutting((rd+r)/2,rd,(cd+c)/2,cd);
        return;
    }
    
}


int main(void) {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0;j<n; j++){
            cin >> num;
            dt[i][j]=num;
        }
    }
    
    cutting(0,n,0,n);
    cout << white << endl;
    cout << black << endl;
    
    return 0;
}
