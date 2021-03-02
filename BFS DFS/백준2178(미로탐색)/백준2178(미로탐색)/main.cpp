//
//  main.cpp
//  백준2178(미로탐색)
//
//  Created by 유영우 on 2021/03/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n,m; //n:y, m:x
string num;
int check[200][200];
//int cnt;
vector<int>v;

bool compare(int a, int b){
    return a<b;
}

void maze(int y, int x,int cnt){

    if(y==n && x==m){
//        cout << cnt << endl;
        v.push_back(cnt);
    }
    else{
        if(x+1<=m && check[y][x+1]==1){
            check[y][x+1]++;
            maze(y,x+1,cnt+1);
            check[y][x+1]--;
                      
        }
        if(y+1<=n && check[y+1][x]==1){
            check[y+1][x]++;
            maze(y+1,x,cnt+1);
            check[y+1][x]--;
        }
        if(y-1>0 && check[y-1][x]==1){
            check[y-1][x]++;
            maze(y-1,x,cnt+1);
            check[y-1][x]--;
        }
        if(x-1>0 && check[y][x-1]==1){
            check[y][x-1]++;
            maze(y,x-1,cnt+1);
            check[y][x-1]--;
        }

    }
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
    maze(1,1,1);
    sort(v.begin(),v.end(),compare);
    printf("%d",v[0]);
    
    return 0;
}
