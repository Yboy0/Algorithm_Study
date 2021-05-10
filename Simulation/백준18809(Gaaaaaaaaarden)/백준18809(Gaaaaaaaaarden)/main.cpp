//
//  main.cpp
//  백준18809(Gaaaaaaaaarden)
//
//  Created by 유영우 on 2021/05/10.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// 정원 가꾸기
// 정원은 땅과 호수로 구성
// 녹색, 적색 배양액을 땅에 적절히 뿌려 꽃을 심는다
// 배양약은 매 초마다 이전에 도달한 적없는 인접한 땅으로 퍼진다

// 하얀 칸: 배양약을 뿌릴 수 없는 땅
// 황토 칸: 배양액을 뿌릴 수 있는 땅
// 하늘 칸: 호수

// 녹색 + 적색 배양액이 동일한 시간에 도달한 땅 = 꽃이 핀다.
// 칸에 꽃이 피었다면 더이상 배양약에 인정한 땅으로 퍼지지 않는다.

//주어진 배양액을 남김없이 사용해야 함
// 모든 배양액은 서로 다른 곳에 뿌려진다

// 정원과 두 배양액의 개수가 주어졌을 때 피울 수 있는 꽃의 최대개수 구하기

//0: 호수
//1: 하얀 칸
//2: 황토 칸

struct greenRedCh{
    
    int y;
    int x;
    int color;
};


int n,m; // 정원의 행, 열
int g; // 녹색 배양액 개수
int r; // 빨간색 배양액 개수

int garden[52][52];

//배양액 배치 이용
vector<pair<int, int>>possibleGarden;
int gCheck[12];
int rCheck[12];
vector<pair<int, int>>possibleRgarden;
vector<pair<int, int>>possibleGgarden;
// 녹색, 적색 배양액 구별

int dy[4]={-1,1,0,0}; //상하좌우
int dx[4]={0,0,-1,1};


//꽃 최종 개수
int resultFlower;


struct rgChk{
    int y;
    int x;
    int color;
};



//적색 배치
void ArrayRmedium(int rCnt, int index){
    if(rCnt==r){
        //배치 완료 bfs 시작
        
        //정원 복사
        int copyGarden[52][52];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                copyGarden[i][j] = garden[i][j];
            }
        }
        
        
        
        cout << "정원배치:" << endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cout << copyGarden[i][j] << " ";
            }
            cout << endl;
        }
        
        
        int subFlower=0;
        queue<pair<int, int>>q;
        
        //녹색 q에 넣는다.
        cout << "녹색위치:";
        for(unsigned i=0; i<possibleGarden.size(); i++){
            int vy = possibleGarden[i].first;
            int vx = possibleGarden[i].second;
            if(copyGarden[vy][vx]==3){
                cout << vy << " " << vx << endl;
                q.push(make_pair(vy, vx));
            }
        }
        
        //적색 q에 넣는다
        cout << "적색위치:";
        for(unsigned i=0; i<possibleRgarden.size(); i++){
                int vy = possibleRgarden[i].first;
                int vx = possibleRgarden[i].second;
            if(copyGarden[vy][vx]==4){
                cout << vy << " " << vx << endl;
                q.push(make_pair(vy, vx));
            }
            
        }
        
        
        while(!q.empty()){
            
            unsigned qSz = q.size();
            
            queue<rgChk>q1; //배양 유발 칸이 뭐였는지 check하기 위해서
            cout << "같은 타이밍" << endl;
            for(unsigned i=0; i<qSz; i++){
                cout << "배양된 곳을 보자:" << " " << q.front().first << " " << q.front().second<< endl;
                for(int j=0; j<4; j++){
                    int qy = q.front().first+dy[j];
                    int qx = q.front().second+dx[j];
                    
                    if(qy>0 && qy<=n && qx>0 && qx<=m){
                        if(copyGarden[qy][qx] == 1 || copyGarden[qy][qx] == 2){//정원의 하얀칸이거나 황토칸일때
                            rgChk q1C = {qy,qx,copyGarden[q.front().first][q.front().second]};
                            q1.push(q1C);
                        }
                       
                    }
                }
                
                q.pop();
            }
            
            while(!q1.empty()){
                int qy = q1.front().y;
                int qx = q1.front().x;
                int color = q1.front().color;
   
                cout << "q1은 뭔가?:"<< endl;
                
                if((copyGarden[qy][qx]==3 && color==4) || (copyGarden[qy][qx]==4 && color==3)){// 색이 위에서 3또는 4로 바뀌었다면
                    cout << "꽃이 피었다:" << " " << qy << " " << qx<< endl;
                    subFlower++;
                    copyGarden[qy][qx]=5; // 꽃이 되면 5로 바껴라
                }else{
                    cout << qy << " " << qx<< endl;
                    if(color==3){
                        copyGarden[qy][qx]=3;
                    }else{
                        copyGarden[qy][qx]=4;
                    }
                    q.push(make_pair(qy, qx));
                }
                
                q1.pop();
            }

        } //q가 비었을 때
        
        
        if(subFlower>resultFlower){
            resultFlower=subFlower;
        }
        
    
        return;
    }
    
    else{
        for(unsigned i=index; i<possibleRgarden.size(); i++){
            int vy = possibleRgarden[i].first;
            int vx = possibleRgarden[i].second;
            if(rCheck[i]==false){
                rCheck[i]=true;
                garden[vy][vx] = 4;
                ArrayRmedium(rCnt+1,i+1);
                rCheck[i]=false;
                garden[vy][vx] = 1;
            }
        }
    }
}


//녹색 배치
void Arraymedium(int gCnt, int index){
    
    if(gCnt==g){
        // 녹색 배양액 배치가 완료됐다면 적색 배양액 배치
        
        //적색 가능 벡터 초기화
        while (possibleRgarden.size()>0) {
            possibleRgarden.pop_back();
        }
        
        //적색 가능 백터에 적색 가능 칸 넣기
        for(unsigned i=0; i<possibleGarden.size(); i++){
            if(gCheck[i]==false){
                int vy = possibleGarden[i].first;
                int vx = possibleGarden[i].second;
                possibleRgarden.push_back(make_pair(vy, vx));
                }
        }
        

        for(unsigned i=0;i<possibleRgarden.size();i++){
            int vy = possibleRgarden[i].first;
            int vx = possibleRgarden[i].second;
            garden[vy][vx] = 4;
            rCheck[i]=true;
            ArrayRmedium(1,i+1);
            rCheck[i]=false;
            garden[vy][vx] = 1;
        }
        
        return;
        
        

    }else{
        for(unsigned i=index; i<possibleGarden.size(); i++){
            int vy = possibleGarden[i].first;
            int vx = possibleGarden[i].second;
            if(gCheck[i]==false){
                gCheck[i]=true;
                garden[vy][vx] = 3;
                Arraymedium(gCnt+1,i+1);
                gCheck[i]=false;
                garden[vy][vx] = 1;
            }
        }
    }
}



int main(void) {
    cin >> n >> m >> g >> r;
    
    //잔디 초기 setting
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> garden[i][j];
            if(garden[i][j]==1){ //황토 칸이면 배양액 가능한 벡터에 넣는다
                possibleGarden.push_back(make_pair(i, j));
            }
        }
    }
    
    
    //초기 배양액(녹,적색) setting
    
    //녹색 배양액 부터 setting
    //녹색이면 3으로
    //적색이면 4로
    
    for(unsigned i=0;i<possibleGarden.size();i++){
        int vy = possibleGarden[i].first;
        int vx = possibleGarden[i].second;
        garden[vy][vx] = 3;
        gCheck[i]=true;
        Arraymedium(1,i+1);
        gCheck[i]=false;
        garden[vy][vx] = 1;
    }
    
    
    cout << resultFlower;
    return 0;
}
