//
//  main.cpp
//  백준2606(바이러스)
//
//  Created by 유영우 on 2021/02/24.
//

#include <iostream>
using namespace std;

int n,m;
int a,b;
int cnt;
int arr[100][100];
bool check[100];

void virus(int num){
    for(int i=1; i<n+1; i++){
        if(arr[num][i] == 1){
            if(check[i] == false){
                cnt++;
                check[i]=true;
                virus(i);
            }
            
        }
    }
}

int main(void) {
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    check[1]=true;
    virus(1);
    cout << cnt;
    
    
    return 0;
}
