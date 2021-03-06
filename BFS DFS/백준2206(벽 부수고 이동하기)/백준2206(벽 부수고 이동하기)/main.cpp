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

bool compare(int a, int b){
    return a<b;
}

struct Coord{
    int y;
    int x;
    int cnt;
};

int n,m; //n:y, m:x
string num;
int check[1001][1001];
bool checkk[1001][1001][2];
queue<Coord>q;
int a,b,c;
bool chk;
vector<int>v;
bool ch;
bool cho;

int block(){
 while(!q.empty()){
    a=q.front().y;
    b=q.front().x;
    c=q.front().cnt;
    if(a==n-1 && b==m-1){
        return c;
    }
    
    if(a+1<n){
        if(check[a+1][b]==0 && checkk[a+1][b][0]==false){
            checkk[a+1][b][0]=true;
            Coord coord = {a+1,b,c+1};
            q.push(coord);
        }
        else if(check[a+1][b]==1 && checkk[a+1][b][1]==false && cho==false){
            checkk[a+1][b][1]=true;
            ch=true;
            Coord coord = {a+1,b,c+1};
            q.push(coord);
            
        }
      
    }
    if(a-1>=0){
        if(check[a-1][b]==0 && checkk[a-1][b][0]==false){
            checkk[a-1][b][0]=true;
            Coord coord = {a-1,b,c+1};
            q.push(coord);
        }
        else if(check[a-1][b]==1 && checkk[a-1][b][1]==false && cho==false){
            checkk[a-1][b][1]=true;
            ch=true;
            Coord coord = {a-1,b,c+1};
            q.push(coord);
            
        }
    }
    if(b+1<m){
        if(check[a][b+1]==0 && checkk[a][b+1][0]==false){
            checkk[a][b+1][0]=true;
            Coord coord = {a,b+1,c+1};
            q.push(coord);
        }
        else if(check[a][b+1]==1 && checkk[a][b+1][1]==false && cho==false){
            checkk[a][b+1][1]=true;
            Coord coord = {a,b+1,c+1};
            ch=true;
            q.push(coord);
            
        }
    }
    if(b-1>=0){
        if(check[a][b-1]==0 && checkk[a][b-1][0]==false ){
            checkk[a][b-1][0]=true;
            Coord coord = {a,b-1,c+1};
            q.push(coord);
        }
        else if(check[a][b-1]==1 && checkk[a][b-1][1]==false && cho==false){
            checkk[a][b-1][1]=true;
            Coord coord = {a,b-1,c+1};
            ch=true;
            q.push(coord);
        }
    }

    q.pop();
     
     if(ch==true){
         cho=true;
     }
 }
    return -1;
}


int main(void) {
    cin >> n >>m;
    for(int i=0;i<n;i++){
        cin >> num;
        for(int j=0;j<m;j++){
            if(num[j]=='0'){
                check[i][j]=0;
            }else{
                check[i][j]=1;
            }
        }
    }
    
    Coord coord = {0,0,1};
    checkk[0][0][0]=true;
    q.push(coord);
    cout << block();


    
    return 0;
}
