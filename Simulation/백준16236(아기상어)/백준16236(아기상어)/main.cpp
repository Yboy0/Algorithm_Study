//
//  main.cpp
//  백준16236(아기상어)
//
//  Created by 유영우 on 2021/05/03.
//

#include <iostream>
#include <queue>
using namespace std;

// 상어의 처음크기는 2
// 1초에 상하좌우로 인접한 한 칸씩 이동
// 자신의 크기보다 큰 물고기가 있는 칸으로 이동 불가
// 자신보다 작은 물고기만 먹을 수 있다
// 크기가 같은 물고기가 있는 칸으로는 이동가능
// 거리가 가까운 물고기가 많다면 가장 왼쪽, 위에 있는 물고기를 먹는다
// 물고기 먹으면 그 칸은 0
// 자신의 크기만큼의 물고기 먹으면 크기가 커짐

int n; //칸
int area[21][21];
int c;
int fishCnt;
int canFishCnt;
int sec;
int sharkSz=2;
int eatFishCnt;
int dy[4]={-1,0,1,0}; //상좌위우
int dx[4]={0,-1,0,1};

int sy,sx;

queue<pair<int, int>>q;

struct ccmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        
//        if(a.second==b.second){
//            return a.first>b.first;
//        }
        return a.first>b.first;
    }
};

//크기가 2일 때 먹을 물고기가 아예 없으면 return
// 판에 먹을 물고기가 없게 되면 종료
//



void babyshark(){

    if(canFishCnt==0){ //여기 통과했다면 먹을 수 있는 건 무조건 있다.
        return;
    }
    
    while(fishCnt>0){
        area[sy][sx] = 9;
        q.push(make_pair(sy, sx));
        
        bool check[21][21];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                check[i][j]=false;
            }
        }
        
        check[sy][sx]=true;
        
        int subSec = sec;
        bool eatCheck=false;
        
        priority_queue<pair<int, int>,vector<pair<int, int>>,ccmp>fishSelectq;
        
        
        while(!q.empty()){ // 먹을 물고기 찾으러 가자
            
            if(eatCheck==true){ // 고기를 먹었으면 q비워주고 다시 시작
                break;
            }
            
            //초기화 되는 지 확인
            unsigned qSize= q.size();
            
            for(unsigned j=0;j<qSize; j++){ //거리 같은 것 중에 최선의 물고기 먹기 위해
                
                for(int i=0; i<4; i++){
                    
                    int qy=q.front().first+dy[i];
                    int qx=q.front().second+dx[i];
                    
                  
                    
                    if(qy>=0 && qx>=0 && qy<n && qx<n){
                        
                        if((area[qy][qx]==sharkSz || area[qy][qx]==0) && check[qy][qx]==false){//이동하는 경우
                            
                            q.push(make_pair(qy, qx));
                            check[qy][qx]=true;
                            
                        }else if(check[qy][qx]==false && area[qy][qx]>0 && area[qy][qx] < sharkSz ){ //물고기 먹는 경우
                            fishSelectq.push(make_pair(qy, qx));
                            check[qy][qx]=true;
                        }
                    }
                }// 먹을 수 있는 물고기 check
                q.pop();
            }
            
            subSec++; //1초 경과
            
            if(!fishSelectq.empty()){ //먹을 물고기 비교하고 최선의 물고기 먹는다
                
                fishCnt--; // 물고기 먹음
                eatFishCnt++;  //먹은 물고기
                eatCheck=true;
                
                area[sy][sx]=0;
                
                sy=fishSelectq.top().first;
                sx=fishSelectq.top().second;
                
                if(eatFishCnt==sharkSz){
                    sharkSz++;
                    eatFishCnt=0;
                }
                sec = subSec;//확실히 물고기를 먹었을 때 시간 간거 기록
                
            }
            
       
        } // q비었을 때
        
        if(eatCheck){
            while(!q.empty()){
                q.pop();
            }
        }

        if(!eatCheck){ //물고기를 먹지 못했는데 q갸 비어있을 때 계속 찾아다녔는데 판에 먹을 물고기가 없는 경우
            return;
        }
        
    }
}


int main(void) {
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c;
            if(c>0 && c!=9 ){
                fishCnt++;
                area[i][j]=c;
            }else if(c==9){
                sy=i;
                sx=j;
            }
            
            if(c==1){
                canFishCnt++;
            }
        }
    }
    babyshark();
    
    cout << sec;
    
    return 0;
}
