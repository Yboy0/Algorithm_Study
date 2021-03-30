//
//  main.cpp
//  백준2589(보물섬)
//
//  Created by 유영우 on 2021/03/31.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
// 욱지:L->1, 바다:W->0
//욱지로만 이동가능
//한 칸 이동하는데 1시간 상하좌우
//보물은 서로 간 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 있음
int y,x;
int arr[51][51];
bool check[51][51];
string str;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

struct Coord{
    int y;
    int x;
    int cnt;
};

queue<Coord>q;
vector<int>v;

bool compare(int a, int b){
    return a>b;
}

void treasure(){
    
    while(!q.empty()){
        int a = q.front().y;
        int b = q.front().x;
        int c = q.front().cnt;
       
        
        for(int i=0; i<4;i++){
            if(a+dy[i]>=0 && a+dy[i]<y && b+dx[i]>=0 && b+dx[i]<x){
                if(arr[a+dy[i]][b+dx[i]]==1 && check[a+dy[i]][b+dx[i]]==false){
                    check[a+dy[i]][b+dx[i]]=true;
                    Coord coord = {a+dy[i],b+dx[i],c+1};
                    q.push(coord);
                }
            }
        }
        if(q.size()==1){
            v.push_back(c);
        }
        q.pop();
    }
}



int main(void) {
    cin >> y >> x;
    for(int i=0; i<y; i++){
        cin >> str;
        for(int j=0; j<x; j++){
            if(str[j]=='W'){
                arr[i][j]=0;
            }else{
                arr[i][j]=1;
            }
        }
    }
    
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(arr[i][j]==1){
                for(int i=0; i<y; i++){
                    for(int j=0; j<x; j++){
                        check[i][j]=false;
                    }
                }
                Coord coord = {i,j,0};
                check[i][j]=true;
                q.push(coord);
                treasure();
            }
        }
    }
    
    sort(v.begin(),v.end(),compare);
    cout << v[0];
        
    return 0;
}
