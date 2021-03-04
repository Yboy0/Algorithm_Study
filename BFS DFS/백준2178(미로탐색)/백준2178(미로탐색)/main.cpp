//
//  main.cpp
//  백준2178(미로탐색)
//
//  Created by 유영우 on 2021/03/02.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Coord{
    int y;
    int x;
    int cnt;
};

int n,m; //n:y, m:x
string num;
int check[200][200];
vector<int>v;
queue<Coord>q;
int a,b,c;

bool compare(int a, int b){
    return a<b;
}

void maze(){
    
    a=q.front().y;
    b=q.front().x;
    c=q.front().cnt;
    
    if(a==n && b==m){
        v.push_back(c);
    }
    else{
        if(b+1<=m && check[a][b+1]==1){
            check[a][b+1]++;
            Coord coord = {a,b+1,c+1};
            q.push(coord);
                      
        }
        if(a+1<=n && check[a+1][b]==1){
            check[a+1][b]++;
            Coord coord = {a+1,b,c+1};
            q.push(coord);
                   
        }
        if(a-1>0 && check[a-1][b]==1){
            check[a-1][b]++;
            Coord coord = {a-1,b,c+1};
            q.push(coord);
                    
        }
        if(b-1>0 && check[a][b-1]==1){
            check[a][b-1]++;
            Coord coord = {a,b-1,c+1};
            q.push(coord);
                    
        }

    }
    q.pop();

}


int main(void) {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        cin >> num;
        for(int j=0;j<m;j++){
            if(num[j]=='0'){
                check[i][j+1]=0;
            }
            else{
                check[i][j+1]=1;
            }
        }
    }
    Coord coord={1,1,1};
    q.push(coord);
    
    while(!q.empty()){
        maze();
    }

    sort(v.begin(),v.end(),compare);
    printf("%d",v[0]);
    
    return 0;
}
