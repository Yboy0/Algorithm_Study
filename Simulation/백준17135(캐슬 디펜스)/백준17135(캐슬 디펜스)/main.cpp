//
//  main.cpp
//  백준17135(캐슬 디펜스)
//
//  Created by 유영우 on 2021/05/04.
//

#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>

using namespace std;

int N,M,D; // NxM 최대 길이
int a;
int area[16][16];
int enemyCnt;
int catchCnt,maxValue;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

struct ccmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        if(a.second == b.second){
           return a.first < b.first;
        }
        return a.second > b.second;
    }
};

void game(int a1, int a2, int a3){
    //게임에 필요한 복사본 만들고 시작을 하자
    
    int copyenemyCnt = enemyCnt;
    int copyarea[16][16];
    
    for(int i=0; i<=N; i++){
        for(int j=0; j<M; j++){
            copyarea[i][j] = area[i][j];
        }
    }
    
    vector<pair<int, int>> archor;
    archor.push_back(make_pair(N, a1));
    archor.push_back(make_pair(N, a2));
    archor.push_back(make_pair(N, a3));
    
    copyarea[N][a1] = 2;
    copyarea[N][a2] = 2;
    copyarea[N][a3] = 2;
    

    while(copyenemyCnt>0){
        queue<pair<int, int>> realCatchEnemy;
        
        for(int i=0; i<3; i++){
            priority_queue<pair<int, int>,vector<pair<int, int>>,ccmp> subCatchEnemy;
            
            bool check[16][16];
            
            for(int j= 0; j<N; j++){
                for(int k =0; k<M; k++){
                    check[j][k] = false;
                }
            }
            
            queue<pair<int, int>> q;
            q.push(make_pair(archor[i].first, archor[i].second));
            
            bool findEnemy = false;
            int turn = 0;
            
            while (!q.empty()) {
                turn ++;
                
                if(turn > D || findEnemy == true){
                    break;
                }
                
                unsigned long qsize = q.size();
                
                for(unsigned j = 0; j<qsize; j++){
                    int cx = q.front().first;
                    int cy = q.front().second;
                    
                    q.pop();
                    
                    for(int k = 0; k <4; k++){
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        
                        if(nx >=0 && ny >=0 && nx < N && ny < M){
                            if(!check[nx][ny] && copyarea[nx][ny] == 0){
                                q.push(make_pair(nx, ny));
                                check[nx][ny] = true;
                            }//적 못발견해서 다음 루트 넣는 것
                            
                            else if(copyarea[nx][ny] == 1 && !check[nx][ny]){
                                subCatchEnemy.push(make_pair(nx, ny));
                                findEnemy = true;
                                //cout << nx << " " << ny << "후보군" << endl;
                             }
                        }
                    }
                }
            }//각 궁수 타이밍
            if(!subCatchEnemy.empty()){
                realCatchEnemy.push(make_pair(subCatchEnemy.top().first, subCatchEnemy.top().second));
            }
            
        }//궁수가 다 끝난 타이밍
        
        while(!realCatchEnemy.empty()){
            if(copyarea[realCatchEnemy.front().first][realCatchEnemy.front().second] != 0){
                copyarea[realCatchEnemy.front().first][realCatchEnemy.front().second] = 0;
                catchCnt ++;
                copyenemyCnt --;
            }
            realCatchEnemy.pop();
        }
        
        for(int i=N-1; i>=0; i--){
            for(int j= M-1; j>=0; j--){
                if(copyarea[i][j]==1){
                    if(i == N-1){
                        copyarea[i][j]=0;
                        copyenemyCnt --;
                    }
                    else{
                        copyarea[i+1][j] = 1;
                        copyarea[i][j]=0;
                    }
                }
            }
        }//적 한칸 이동 타이밍
        
    }//게임 다 끝난 타이밍
    
}

int main(void) {

    cin >> N >> M >> D;

    for(int i=0; i< N; i++){
        for(int j=0; j< M; j++){
            cin >> a;
            area[N][j] = 3;
            area[i][j] = a;
            if(a == 1){
                enemyCnt++;
            }
        }
    }


    for(int i=0; i< M-2; i++){
        for(int j = i+1; j<M-1; j++){
            for(int k = j+1; k < M; k++){
                catchCnt =0;
                game(i,j,k);

                if(maxValue < catchCnt){
                    maxValue = catchCnt;
                }
            }
        }
    }
    
    cout << maxValue;
}
