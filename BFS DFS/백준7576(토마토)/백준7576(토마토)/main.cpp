//
//  main.cpp
//  백준7576(토마토)
//
//  Created by 유영우 on 2021/03/04.
//

#include <iostream>
#include <queue>
struct Coord{
    int y;
    int x;
    int cnt;
};

using namespace std;
int n,m; // n:y, m:x
int check[1001][1001];
//bool ch[1001][1001];
queue<Coord>q;
int cnt;
int zeroCnt;
int cZeroCnt;
// 익은 토마토와 안 익은 토마토 // 1: 익은 토마토, 0: 익지 않은 토마토, -1: 토마토가 없다
// 토마토가 모두 익을 때까자의 최소 날짜
// 토마토가 모두 익지 못하면 -1

void tomato(){
    int y = q.front().y;
    int x = q.front().x;
    int c = q.front().cnt;
    
    
    if(x+1<m && check[y][x+1]==0){
        Coord coord = {y,x+1,c+1};
        q.push(coord);
        check[y][x+1]++;
        cZeroCnt++;
        
    }
    if(x-1>=0 && check[y][x-1]==0){
        Coord coord = {y,x-1,c+1};
        q.push(coord);
        check[y][x-1]++;
        cZeroCnt++;
        
    }
    if(y+1<n && check[y+1][x]==0){
        Coord coord = {y+1,x,c+1};
        q.push(coord);
        check[y+1][x]++;
        cZeroCnt++;
        
    }
    if(y-1>=0 && check[y-1][x]==0){
        Coord coord = {y-1,x,c+1};
        q.push(coord);
        check[y-1][x]++;
        cZeroCnt++;
        
    }
    if(q.size()==1){
        cnt=q.front().cnt;
    }
    
    q.pop();
        
}


int main(void) {
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> check[i][j];
            if(check[i][j]==1){
                Coord coord = {i,j,0};
                q.push(coord);
            }
            if(check[i][j]==0){
                zeroCnt++;
            }

        }
    }

    while(!q.empty()){
        tomato();
    }
    
//    bool ch=false;
//
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            if(check[i][j]==0){
//                ch=true;
//                break;
//            }
//        }
//        if(ch==true){
//            break;
//        }
//    }
//
//    if(ch==true){
//        cout << -1;
//    }else{
//        cout << cnt;
//    }
    if(zeroCnt==cZeroCnt){
        cout << cnt;
    }
    else{
        cout << -1;
    }
    return 0;
}
