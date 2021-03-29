//
//  main.cpp
//  백준4963(섬의 개수)
//
//  Created by 유영우 on 2021/03/30.
//

#include <iostream>
#include <queue>

using namespace std;
int w,h; //w:x, h:y 1:땅, 0:바다
int arr[51][51];
bool check[51][51];
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};
int cnt;

struct coord{
    int y,x;
};

queue<coord>q;
queue<int>result;
void island(){
    while(!q.empty()){
        int x = q.front().x;
        int y= q.front().y;
        
        q.pop();
        
        for(int i=0;i<8;i++){
                if(check[y+dy[i]][x+dx[i]]==false && arr[y+dy[i]][x+dx[i]]==1 && x+dx[i]>=0 && x+dx[i]<w && y+dy[i]>=0 && y+dy[i]<h){
                 
                    check[y+dy[i]][x+dx[i]]=true;
                    
                    coord crd = {y+dy[i],x+dx[i]};
                    q.push(crd);
                }
        }
        
    }
}

int main(void) {
    
    while(true){
        cnt=0;
        cin >> w >> h;
        if(w==0 && h==0)
            break;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> arr[i][j];
            }
        }
  
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(arr[i][j]==1 && check[i][j]==false){
                    coord crd = {i,j};
                    q.push(crd);
                    island();
                    cnt++;
                }
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                check[i][j]=false;
                }
            }
        
        result.push(cnt);
    }
        
    while(!result.empty()){
        cout << result.front() << endl;
        result.pop();
    }

    
    return 0;
}
