//
//  main.cpp
//  백준2206(벽 부수고 이동하기) -2
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

int n,m; //n:y, m:x
string num;
int check[1001][1001];
bool checkk[1001][1001][2];
int a,b,c;
bool chk;
bool ch;
bool cho;
vector<int>v;

void block(int a, int b,int cnt){
 
    if(a==n-1 && b==m-1){
        v.push_back(cnt);
    }
    
    if(a+1<n){
        if(check[a+1][b]==0 && checkk[a+1][b][0]==false){
            checkk[a+1][b][0]=true;
            block(a+1, b, cnt+1);
            checkk[a+1][b][0]=false;

        }
        else if(check[a+1][b]==1 && checkk[a+1][b][1]==false && cho==false){
            checkk[a+1][b][1]=true;
            cho=true;
            block(a+1, b, cnt+1);
            cho=false;

        }
      
    }
    if(a-1>=0){
        if(check[a-1][b]==0 && checkk[a-1][b][0]==false){
            checkk[a-1][b][0]=true;
            block(a-1, b, cnt+1);
            checkk[a-1][b][0]=false;

        }
        else if(check[a-1][b]==1 && checkk[a-1][b][1]==false && cho==false){
            checkk[a-1][b][1]=true;
            cho=true;
            block(a-1, b, cnt+1);
            cho=false;

            
        }
    }
    if(b+1<m){
        if(check[a][b+1]==0 && checkk[a][b+1][0]==false){
            checkk[a][b+1][0]=true;
            block(a, b+1, cnt+1);
            checkk[a][b+1][0]=false;
        }
        else if(check[a][b+1]==1 && checkk[a][b+1][1]==false && cho==false){
            checkk[a][b+1][1]=true;
            cho=true;
            block(a, b+1, cnt+1);
            cho=false;

            
        }
    }
    if(b-1>=0){
        if(check[a][b-1]==0 && checkk[a][b-1][0]==false ){
            checkk[a][b-1][0]=true;
            block(a, b-1, cnt+1);
            checkk[a][b-1][0]=false;
   

        }
        else if(check[a][b-1]==1 && checkk[a][b-1][1]==false && cho==false){
            checkk[a][b-1][1]=true;
            cho=true;
            block(a, b-1, cnt+1);
            cho=false;

        }
    }

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
    
    checkk[0][0][0]=true;
    block(0,0,1);
        
    if(v.empty()){
        cout << -1;
    }else{
        sort(v.begin(),v.end(),compare);
        cout << v[0];
    }
 

    
    return 0;
}
