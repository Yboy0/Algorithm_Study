//
//  main.cpp
//  백준1260
//
//  Created by 유영우 on 2021/02/10.
//

#include <iostream>
#include <queue>
using namespace std;
int n,m,v;  //n: 정점 개수 m: 간선 개수 v: 시작 정점
int a,b;
int arr[1001][1001];
bool check[1001];
bool check1[1001];
queue<int> q;


void dfs(int start){
    if(check[start] == false){
        cout << start << " ";
        check[start] = true;
        
        for(int i=1; i<=n; i++){
            if(arr[start][i] == 1){
                dfs(i);
            }
        }
    }
    else{
        return;
    }
}

void bfs(int start){
    q.push(start);
    check1[start]=true;
    
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        cout << fr << " ";
        for(int i=1; i<=n; i++){
            if(arr[fr][i] == 1 && check1[i] == false ){
                q.push(i);
                check1[i] = true;
            }
        }
    }

}

int main(void) {
    cin >> n >> m >> v;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        arr[a][b] =1;
        arr[b][a] =1;
    }
    dfs(v);
    cout << endl;
    bfs(v);
    
    return 0;
}
