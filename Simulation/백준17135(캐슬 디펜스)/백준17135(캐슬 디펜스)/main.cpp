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
int n,m,d;
int a;
int area[16][16];
int enemyCnt;
int catchCnt, maxValue;
int dy[4] = {0,-1,0,1}; //왼 위 오 아래
int dx[4] = {-1,0,1,0};

struct ccmp{
    bool operator()(pair<int,int> &a, pair<int, int> &b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        
        return a.first>b.first;
    }
};

void game(int a1, int a2, int a3){
    
    int copyememyCnt=enemyCnt;
    int copyArea[16][16];
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<m; j++){
            copyArea[i][j] = area[i][j];
        }
    }
    
    
    vector<pair<int, int>>archor;
    archor.push_back(make_pair(n, a1));
    archor.push_back(make_pair(n, a2));
    archor.push_back(make_pair(n, a3));
    
    copyArea[n][a1] = 2;
    copyArea[n][a2] = 2;
    copyArea[n][a3] = 2;
    
    while(copyememyCnt>0){
        queue<pair<int, int>> realCatchEnemy;
        
        for(int i=0; i<3; i++){
            
            priority_queue<pair<int,int>, vector<pair<int, int>>,ccmp>subCatchEnemy;
            
            bool check[16][16];
            
            for(int j=0; j<n; j++){
                for(int k=0; k<m; k++){
                    check[j][k] = false;
                }
            }
            
            queue<pair<int, int>> q;
            q.push(make_pair(archor[i].first, archor[i].second));
            
            bool findEnemy = false;
            int turn=0;
            
            while(!q.empty()){
                turn ++;
                
                if(turn>d || findEnemy == true){
                    break;
                }
                
                unsigned long qsize = q.size();
                
                for(unsigned j=0; j<qsize; j++){
                    int cx = q.front().first;
                    int cy = q.front().second;
                    
                    q.pop();
                    
                    for(int k=0; k<4; k++){
                        int ny = cx+dy[k];
                        int nx = cy+dy[k];
                        
                        if(nx>=0 && ny>=0 && nx<m && ny<n){
                            if(check[ny][nx] && copyArea[ny][nx]==0){
                                q.push(make_pair(ny, nx));
                                check[ny][nx] = true;
                            }else if(copyArea[ny][nx]==1 && !check[ny][nx]){
                                subCatchEnemy.push(make_pair(ny, nx));
                                findEnemy=true;
                            }
                        }
                    }
                    
                }

            }
            if(!subCatchEnemy.empty()){
                realCatchEnemy.push(make_pair(subCatchEnemy.top().first, subCatchEnemy.top().second));
            }
        }
        
        while(!realCatchEnemy.empty()){
            if(copyArea[realCatchEnemy.front().first][realCatchEnemy.front().second] !=0){
                copyArea[realCatchEnemy.front().first][realCatchEnemy.front().second] = 0;
                catchCnt ++;
                copyememyCnt --;
            }
            realCatchEnemy.pop();
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(copyArea[i][j]==1){
                    if(i==n-1){
                        copyArea[i][j]=0;
                        copyememyCnt--;
                    }else{
                        copyArea[i+1][j] = 1;
                        copyArea[i][j]=0;
                    }
                }
            }
        }
    }
    
    
    
    
    
}


int main(void) {
    cin >> n >> m >> d;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a;
            area[n][j] = 3;
            area[i][j] = a;
            if(a == 1){
                enemyCnt++;
            }
        }
    }
    
    for(int i=0; i<m-2; i++){
        for(int j=i+1; j<m-1; j++){
            for(int k=j+1; k<m; k++){
                catchCnt=0;
                game(i,j,k);
                
                if(maxValue < catchCnt){
                    maxValue = catchCnt;
                }
            }
        }
    }
    
    cout << maxValue;
    
}
