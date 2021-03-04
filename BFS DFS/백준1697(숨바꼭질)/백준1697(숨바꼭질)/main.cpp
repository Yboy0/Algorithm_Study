//
//  main.cpp
//  백준1697(숨바꼭질)
//
//  Created by 유영우 on 2021/03/05.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct binTime{
    int loc;
    int time;
};

int n,k;
vector<int>v;
queue<binTime>q;
bool check[1000001];
int loc,tm;


bool compare(int a, int b){
    return a<b;
}

void HideAndCatch(){
    loc=q.front().loc;
    tm=q.front().time;
    
    if(loc == k){
        v.push_back(tm);
    }
    else{
        if(loc+1<=k && check[loc+1]==false){
            check[loc+1]=true;
            binTime bt={loc+1,tm+1};
            q.push(bt);
           
        }
        if(loc-1>=0 && check[loc-1]==false){
            check[loc-1]=true;
            binTime bt={loc-1,tm+1};
            q.push(bt);
            
        }
        if(2*loc<=2*k && check[2*loc]==false){
            check[2*loc]=true;
            binTime bt={2*loc,tm+1};
            q.push(bt);
            
        }
    }
    q.pop();
    
}



int main(void) {
    cin >> n >> k;
    binTime bt={n,0};
    q.push(bt);
    
    while(!q.empty()){
        
        HideAndCatch();
    }
    
    sort(v.begin(),v.end(),compare);
    cout << v[0];
    return 0;
}
