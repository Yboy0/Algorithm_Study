//
//  main.cpp
//  카카오인턴쉽 문제2
//
//  Created by 유영우 on 2021/05/08.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>>q;
bool check[5][5][5];
int py;
int px;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int result = 0;
bool dCh;

//거리두기
// 대기실은 5개, 5X5 사이즈
// 맨해튼 거리가 2이하로 앉으면 안됨
// 다만 자리 사이에 파티션이 있다면 허용
// p: 응시자가 앉아있는 자리, 0: 빈체이블, X: 파티션
// 각 대기실 별로 거리두기 지키고 있으면 1, 지키지 않고 있다면 0을 배열에 담아 return

//거리가 2이하이면 거리두기 안지킨 것
void bfs(vector<string> room,int roomNum){ //
  
    q.push(make_pair(py, px));
    check[roomNum][py][px] = true;
    int d=0;
    bool newP=false;
    // p값 찾으면 거리 계산하고 파티션 고려하고 거리두기 안지키면 flase 아니면  계속 갱신
    while(!q.empty()){
        
        int qSz = q.size();
        d++; // 거리 증가
        cout << "d:" << d << endl;
        for(int k=0; k<qSz; k++){
            for(int i=0; i<4; i++){
                
//                cout <<q.front().first << " " << q.front().second << " " << endl;
                
                int qy = q.front().first+dy[i];
                int qx = q.front().second+dx[i];
                
                if(qy>=0 && qy<5 && qx>=0 && qx<5){
                    if((room[qy][qx] == 'O' || room[qy][qx] == 'X') && check[roomNum][qy][qx]==false){
                        check[roomNum][qy][qx] = true;
                        q.push(make_pair(qy, qx));
                        
                    }else if(room[qy][qx] == 'P' && check[roomNum][qy][qx]==false){
                        cout <<"원래p:"<< py << " " << px << " " << endl;
                        cout <<qy << " " << qx << " " << endl;
                                        
                        if(d<=2){ //거리두기 위반된다면
                            if(d==2){
                                //원래 p의 위 쪽에 있을 때 파티션 확인
                                if(qy<py && qx==px){
                                    if(room[qy+1][qx] != 'X'){
                                        dCh=true;
                                        return;
                                    }
                                }
                                //원래 p의 아래 쪽에 있을 때
                                else if(qy>py && qx==px){
                                    if(room[qy-1][qx] != 'X'){
                                        dCh=true;
                                        return;
                                    }
                                    
                                }
                                //원래 p의 오른 쪽에 있을 때
                                else if(qy==py && qx>px){
                                    if(room[qy][qx-1] != 'X'){
                                        dCh=true;
                                        return;
                                    }
                                    
                                }
                                //원래 p의 왼쪽에 있을 때
                                else if(qy==py && qx<px){
                                    if(room[qy][qx+1] != 'X'){
                                        dCh=true;
                                        return;
                                    }
                                }
                                //원래 p의 대각선에 있을 때
                                else{
                                    //11시 대각선일 때
                                    if(qy<py && qx<px){
                                        if(room[py+1][px] != 'X' || room[py][px-1] != 'X'){
                                            dCh=true;
                                            return;
                                        }
                                    }
                                    //1시 대각선일 때
                                    
                                    else if(qy<py && qx>px){
                                        if(room[py-1][px+1] != 'X' || room[py][px-1] != 'X'){
                                            dCh=true;
                                            return;
                                        }
                                        
                                    }
                                    //7시 대각선일 때
                                    
                                    else if(qy>py && qx<px){
                                        if(room[py][px-1] != 'X' || room[py+1][px] != 'X'){
                                            dCh=true;
                                            return;
                                        }
                                    }
                                    
                                    //5시 대각선일 때
                                    else if(qy>py && qx>px){
                                        if(room[py][px+1] != 'X' || room[py+1][px] != 'X'){
                                            dCh=true;
                                            return;
                                        }
                                    }
                                    
                                }
                                room[py][px]='O';
                                py=qy;
                                px=qx;
                                d=0;
                                newP=true;
                                break;
                            }else{
                                dCh=true;
                                return;
                            }
                        }else{ // 거리두기 통과라면
                            room[py][px]='O';
                            py=qy;
                            px=qx;
                            d=0;
                            newP=true;
                            break;
                        }
                    }
                    
                }
            }
        }
        q.pop();
        
        if(newP==true){
            while(!q.empty()){
                q.pop();
            }
            q.push(make_pair(py, px));
            
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    check[roomNum][i][j]=false;
                }
            }
            
            newP=false;
        }
  
    } //q가 비었으면 true return
    
    if(!dCh){
        result=1;
    }
}




vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    //5X5의 크기의  5개의 대기실
    for(int i=0; i<5; i++){
        result = 0;
        dCh=false;
        bool c = false;
        for(int j=0; j<5; j++){
            cout << "jjj" << endl;
            for(int k=0; k<5; k++){
                cout << "kkk" << endl;
                if(places[i][j][k] =='P'){
                    
                    while(!q.empty()){
                        q.pop();
                    }
                    
                    cout << "ppp" << endl;
                    cout << j << " "  << k << endl;
                    // bfs 시작
                    py=j;
                    px=k;
                    bfs(places[i],i);
                    answer.push_back(result);
                    c=true;
                    break;
                }
            }
            if(c==true){
                break;
            }
        }
        if(c==false){
            answer.push_back(result);
        }
    }
    return answer;
}


int main(void) {
    // insert code here...
    vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    
    vector<int> answer = solution(places);
    
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }
                                                                                                                                                                                   
    return 0;
}
