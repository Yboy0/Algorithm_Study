//
//  main.cpp
//  백준14503(로봇 청소기)
//
//  Created by 유영우 on 2021/05/11.
//

#include <iostream>
#include <queue>
using namespace std;


// 청소기가 청소하는 영역의 개수를 구하는 프로그램 작성
// 영역은  벽또는 빈 칸
// 동서남북으로 이동
// 지도의 각 칸은 (r,c) y,x
// 청소기의 동작
    // 1.현재위치 청소
    // 2. 왼쪽방향부터 차례대로 탐색
        // a. 왼쪽에 청소하지 않은 공간있다면 그 방향으로 회전하고 한 칸 전진하고 1번
        // b.  왼쪽에 청소할 공간없다면, 그 방향으로 회전하고 2번
        // c.  네 방향 모두 청소되어있거나 벽인 경우, 바라보는 방향 유지한 채 한 칸 후진 후 2번으로
        // d.  네 방향 모두 청소되어있거나 벽인 경우, 뒤쪽 방향이 벽이라 후진 불가능한 경우 작동 멈춤
// 이미 청소되어있는 칸 청소하지 않고 벽은 통과할 수 없다.

//0: 빈 칸
//1: 벽

//청소기가 청소하는 칸의 개수 구하기.


int n,m;
int r,c; //청소기의 위치 좌표
int d; // 청소기가 바라보는 방향 0:북, 1:동, 2:남, 3:서
int area[52][52];
int dy[4]={0,1,0,-1}; //좌하우상
int dx[4]={1,0,1,0};

queue<pair<int,int>>q;
int check[52][52];
int cleanCnt;

void robot(){
    
    // 이미 청소되어 있는 칸
    while(!q.empty()){
        
        int qy = q.front().first;
        int qx = q.front().second;
        q.pop();
 
        bool checkDir=false;
        int searchCnt=0;
        //방향에 따라 왼쪽 확인
        while(!checkDir){
            if(searchCnt==4){ //동서남북 다 탐색했는데 청소 할 곳 없을 때(청소 되어있거나 벽인 경우)
                // 뒤로 후진
                if(d==0){ //북 -> 남
                    qy=qy+1;
                    
                }else if(d==1){ //동 -> 서
                    qx=qx-1;

                }else if(d==2){//남 -> 북
                    qy=qy-1;
                    
                }else{//서 -> 동
                    qx=qx+1;
                }
                
                if(qy>0 && qx>0 && qy<n-1 && qx<m-1){ //뒤가 벽인지 확인
                    if(area[qy][qx] == 1){ //벽이면 종료
                        return;
                    }else{
                        q.push(make_pair(qy, qx));
                        break;
                    }
                }else{
                    return;
                }
            }
            
            int qqy =qy;
            int qqx =qx;
            
            
            if(d==0){ //북 -> 서
                qqx=qqx-1;
                
                d=3;
            }else if(d==1){ //동 -> 북
                qqy=qqy-1;
                
                d=0;
            }else if(d==2){//남 -> 동
                qqx=qqx+1;
                
                d=1;
            }else{//서 -> 남
                qqy=qqy+1;
                
                d=2;
            }
            searchCnt++;
            //q에 넣을 수 있을 지 확인
            if(qqy>0 && qqx>0 && qqy<n-1 && qqx<m-1){
                if(check[qqy][qqx]==false && area[qqy][qqx] == 0){//영역이 청소 가능하다면 q에 넣는다
                    check[qqy][qqx] =true; // 청소
                    cleanCnt++;
                    q.push(make_pair(qqy, qqx)); // 한 칸 전진
                    checkDir=true;
                }
            }
            
        }
        
        
    } //q가 비었다면
}




int main(void) {
    cin >> n >> m;
    cin >> r >> c >> d;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> area[i][j];
        }
    }
    
    area[r][c] = 0;
    check[r][c] =true;
    q.push(make_pair(r, c));
    cleanCnt++;
    
    robot();
    
    cout << cleanCnt << endl;

    return 0;
}
