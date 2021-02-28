//
//  main.cpp
//  백준1012(유기농 배추)
//
//  Created by 유영우 on 2021/02/24.
//

#include <iostream>
#include <queue>

using namespace std;
int t;
int x,y;
int n,m,k;
int cnt;
int check[100][100];

struct coord{
    int y;
    int x;
};

queue<coord>v;


void butterFly(int y ,int x){
        if(x-1>=0 && check[y][x-1]==1){//좌
            check[y][x-1]++;
            butterFly(y, x-1);
        }
        if(x+1<m && check[y][x+1]==1){ //우
            check[y][x+1]++;
            butterFly(y, x+1);
        }
       if(y-1>=0 && check[y-1][x]==1){ //상
            check[y-1][x]++;
            butterFly(y-1, x);
        }
       if(y+1<n && check[y+1][x]==1){//하
            check[y+1][x]++;
            butterFly(y+1, x);
        }
    return;
        
}


int main(void) {
    cin >> t;
    
    for(int i=0;i<t;i++){
        cin >> m >> n >>k;

        cnt = 0;
        for(int j=0;j<k;j++){
            cin >> x >> y;
            check[y][x]++;
            coord cr={y,x};
            v.push(cr);
        }
        
        for(int j=0;j<k;j++){
            if(check[v.front().y][v.front().x]==1){
                check[v.front().y][v.front().x]++;
                butterFly(v.front().y,v.front().x);
                cnt++;
            }
            v.pop();
        }
        
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                check[j][k]=0;
            }
        }
        
        cout <<  cnt << endl;;
    }
    return 0;
}
