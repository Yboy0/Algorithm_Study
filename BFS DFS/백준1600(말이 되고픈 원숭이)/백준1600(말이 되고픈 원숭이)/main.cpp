//
//  main.cpp
//  백준1600(말이 되고픈 원숭이)
//
//  Created by 유영우 on 2021/03/11.
//

#include <iostream>
#include <queue>
using namespace std;
//원숭이는 말이되고 싶다.
//그래서 말을 따라한다.
//말은 체스의 나이트와 같이 이동.(인접한 곳에서 대각선 점프)
//원숭이는 k번만 말과 같이 이동가능.
//보통은 인접한 네 칸으로만 이동가능.
//가장 빨리 갈 수 있는 방법.
//0으로만 갈 수 이동가능.

queue<pair<pair<int,int>,int>>q;
int k,w,h; // h:y w:x
int arr[250][250];
int check[250][250];
//동 서 북 남
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int cnt;
int a,b,c;
int ay,ax;
int kay,kax;
bool finish;

void monkey(){
    q.push(make_pair(make_pair(0, 0), 0));
    check[0][0]=1;
    while(!q.empty()){
        
        unsigned long lsize=q.size();
        
        for(int i=0;i<lsize;i++){
            a=q.front().first.first; //y
            b=q.front().first.second; //x
            c=q.front().second; //kcount
            
            q.pop();
            cout << a << " "<< b<< " "<<c << " "<< cnt<< endl;
            if(a==h-1 && b==w-1){
                //cout << c <<  " "<< cnt << endl;
                finish=true;
                return;
            }
            
            // 원숭이의 움직임
            for(int j=0;j<4;j++){
                ay=a+dy[j];
                ax=b+dx[j];
                if(ay>=0 && ax>=0 && ay<h && ax<w){
                    if(arr[ay][ax]==0 && check[ay][ax]==0){
                        check[ay][ax]=1;
                        q.push(make_pair(make_pair(ay, ax),c));
                    }
                    
                    // 말의 움직임
                   
                    if(c<k){
                        for(int l=0;l<=1;l++){
                                if(j==0){//동
                                     kax=ax+1;
                                     kay=ay-1;
                                     if(l==1){
                                         kay=ay+1;
                                     }
                                 }
                                 else if(j==1){//서
                                     kax=ax-1;
                                     kay=ay-1;
                                     if(l==1){
                                         kay=ay+1;
                                     }
                                     
                                 }
                                 else if(j==2){//남
                                     kay=ay+1;
                                     kax=ax-1;
                                     if(l==1){
                                         kax=ax+1;
                                     }
                                     
                                 }
                                 else{//북
                                     kay=ay-1;
                                     kax=ax-1;
                                     if(l==1){
                                         kax=ax+1;
                                     }
                                     
                                 }
                                if(kay>=0 && kax>=0 && kay<h && kax<w){
                                    if(arr[kay][kax]==0 && check[kay][kax]==0){
                                        check[kay][kax]=1;
                                        q.push(make_pair(make_pair(kay, kax),c+1));
                                    }
                                }
                                             
                        }
                    }
                                       
                }
                
            }
        }
        cnt++;
    }
    
    
}


int main(void) {
    cin >> k;
    cin >> w >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> arr[i][j];
        }
    }
    
    monkey();
    
    if(finish==true){
        cout << cnt;
    }else{
        cout << -1;
    }
    
    return 0;
}
