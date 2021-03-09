//
//  main.cpp
//  백준2206(벽 부수고 이동하기)
//
//  Created by 유영우 on 2021/03/05.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//0: 이동가능, 1: 이동불가
//최단경로
//벽뿌시는거 고려-> 한개 까지만 뿌실 수 있다

queue<pair<pair<int, int>, int>> loc;

int n,m;
int num;
int arr[1001][1001];
int check[1001][1001][2];
int cnt;
bool finish;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void Move(){
    
    loc.push(make_pair(make_pair(1, 1), 0));
    cnt ++;
    
    while(!loc.empty()){
        
        unsigned long lsize = loc.size();
        
        for(unsigned i=0; i<lsize; i++){
            int fx = loc.front().first.first;
            int fy = loc.front().first.second;
            int ch = loc.front().second;
            
            loc.pop();
            
            if(fx == n && fy == m){
                finish = true;
                return;
            }
            for(int j=0; j<4; j++){
                int nx = fx + dx[j];
                int ny = fy + dy[j];
                
                if(nx>=1 && ny>=1 && nx<=n && ny <= m){
                    if(arr[nx][ny] ==0 && check[nx][ny][ch] == 0){
                        
                        check[nx][ny][ch] = 1;
                        loc.push(make_pair(make_pair(nx, ny), ch));
                    }
                    
                    if(arr[nx][ny]==1 && ch ==0 && check[nx][ny][ch]){
                        check[nx][ny][ch] = 1;
                        loc.push(make_pair(make_pair(nx, ny), 1));
                    }
                }
                
            }
        }
        
        cnt ++;
    }
}


int main(void) {
    cin >> n >>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&num);
            arr[i][j] = num;
        }
    }
    
    Move();

    if(finish){
        cout << cnt;
    }
    else{
        cout << -1;
    }
    return 0;
}
