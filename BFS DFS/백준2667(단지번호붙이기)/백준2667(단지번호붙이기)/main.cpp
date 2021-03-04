//
//  main.cpp
//  백준2667(단지번호붙이기)
//
//  Created by 유영우 on 2021/03/05.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//1: 집이 있는 곳, 0: 집이 없는 곳

bool compare(int a, int b){
    return a<b;
}


struct Coord{
    int y;
    int x;
};

int n;
string str;
int totalCnt;
int houseCnt;
int check[30][30];
//bool ch[30][30];
queue<Coord>q;
int a,b;
vector<int>v;

void house(){
    a=q.front().y;
    b=q.front().x;

    if(a+1<n && check[a+1][b]==1){
        check[a+1][b]++;
        Coord coord = {a+1,b};
        q.push(coord);
       
    }
    if(a-1>=0 && check[a-1][b]==1){
        check[a-1][b]++;
        Coord coord = {a-1,b};
        q.push(coord);
       
    }
    if(b+1<n && check[a][b+1]==1){
        check[a][b+1]++;
        Coord coord = {a,b+1};
        q.push(coord);
       
    }
    if(b-1>=0 && check[a][b-1]==1){
        check[a][b-1]++;
        Coord coord = {a,b-1};
        q.push(coord);
       
    }
    q.pop();
    houseCnt++;
}


int main(void) {
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        for(int j=0;j<n;j++){
            if(str[j] == '0'){
                check[i][j]=0;
            }else{
                check[i][j]=1;
            }
        }
    }
   

    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]==1){
                houseCnt=0;
                totalCnt++;
                check[i][j]++;
                Coord coord={i,j};
                q.push(coord);
                while(!q.empty()){
                   house();
                }
                v.push_back(houseCnt);
                
            }
        }
    }

    
    sort(v.begin(),v.end(),compare);
    
    cout << totalCnt << endl;
    for(unsigned i =0;i<v.size();i++){
        cout << v[i] << endl;
    }
    
    return 0;
}
