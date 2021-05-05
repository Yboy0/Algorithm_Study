//
//  main.cpp
//  백준16236(아기상어)
//
//  Created by 유영우 on 2021/05/03.
//

#include <iostream>
#include <queue>

using namespace std;



//m마리 물고기와 아기상어 1마리
//상어의 크기는 2
//상어는 상하좌우 인접한 한 칸 씩 이동
//상어는 자신보다 큰 물고기 있는 칸은 못감
//상어는 자신보다 작은 물고기만 먹을 수 있음
// 크기가 같은 물고기는 먹을 수 없지만 그 물고기가 있는 칸은 갈 수 있다

//상어의 이동
//1. 이동 공간에 먹을 물고기가 없으면 엄마상어 call
//2. 먹을 수 있는 물고기 1마리면 먹음
//3. 먹을 수 있는 물고기 1마리보다 많으면, 거리가 가장 가까운 물고기 먹음
// 물고기 있는 칸으로 이동할 때, 지나는 최소 칸이 거리
// 가장 왼쪽 위에 있는 물고기 물고기 먹음
// 물고기를 먹으면 그 칸은 0
// 자신의 크기와 같은 수의 물고기 먹을 때 마다 크기 1 증가
// 물고기 다먹을 때까지 걸린 시간 구하기

struct Coord{
    int y;
    int x;
    int second;
};

int n;
int arr[21][21];
int check[21][21];
int sharkSz=2;
queue<Coord>q;
int dy[4] ={-1,0,0,1};
int dx[4]={0,-1,1,0};
int fishCnt;
int ch;
int ch2;
int ch3;
int sol;
int sy,sx;

queue<Coord>q1;

void shark(){
    if(ch==0){
        cout << 0;
        return;
    }
    
    
    while(!q.empty()){
        if(sharkSz == fishCnt){
            sharkSz++;
            fishCnt=0;
        }
        
        int qy = q.front().y;
        int qx = q.front().x;
        int qsec = q.front().second;
        q.pop();
        
        
        
        ch2=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(sharkSz>arr[i][j] && arr[i][j]!=0){
                    ch2++;
                }
            }
        }
        
        if(ch2==0){
            cout << qsec-1;
            return;
        }
        
        
        
        if(sharkSz > arr[qy][qx] && arr[qy][qx]!=0){
            
            while(!q.empty()){
                if(qsec==q.front().second && sharkSz >arr[q.front().y][q.front().x]&& arr[q.front().y][q.front().x]!=0){
                    struct Coord coord = {q.front().y,q.front().x,q.front().second};
                    q1.push(coord);
                }
                q.pop();
            }
            
            while(!q1.empty()){
                if(q1.front().y<=qy){
                    if(q1.front().y==qy){
                        if(q1.front().x<qx){
                            qy=q1.front().y;
                            qx=q1.front().x;
                        }
                    }else{
                        qy=q1.front().y;
                        qx=q1.front().x;
                    }
                    
                }
                q1.pop();
            }
            
            sol = qsec;
            arr[qy][qx]=9;
            arr[sy][sx]=0;
            
            fishCnt++;
            sy=qy;
            sx=qx;
            
            
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    check[i][j]=false;
                }
            }
        }
        
        for(int i=0; i<4; i++){
            int y = qy+dy[i];
            int x = qx+dx[i];
            
            if(check[y][x]==false && arr[y][x]!=9 && y>=1 && y<=n && x>=1 && x<=n && arr[y][x]<=sharkSz){
                check[y][x]=true;
                Coord coord = {y,x,qsec+1};
                q.push(coord);
            }
        }
        
        if(q.empty()){
            cout << sol;
            return;
        }
    }
    
}


int main(void) {
    
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                Coord coord = {i,j,0};
                q.push(coord);
                sy=i;
                sx=j;
            }else if(arr[i][j]==1){
                ch++;
            }
            
        }
    }
    
    
    shark();
    
    return 0;
}
