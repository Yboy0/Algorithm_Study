//
//  main.cpp
//  벡준11724(연결 요소의 개수)
//
//  Created by 유영우 on 2021/02/24.
//

#include <iostream>
using namespace std;

int n,m;
int a,b;
int cnt;
int arr[1001][1001];
bool check[1001];

void component(int num){
       check[num]=true;
        for(int j=1;j<n+1;j++){
            if(arr[num][j] == 1 && check[j]==false){
                component(j);
                
            }
        }
}


int main(void) {
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    
    for(int i=1;i<n+1;i++){
        if(check[i] == false){
            component(i);
            cnt++;
        }
    }
    cout << cnt;
   
    return 0;
}
