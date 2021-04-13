//
//  main.cpp
//  백준1182(부분수열의 합)
//
//  Created by 유영우 on 2021/04/12.
//

#include <iostream>
using namespace std;

int n,s; // n: 정수의 개수 s: 정수
int arr[21];
bool check[21];
int answer[21];
int cnt;

void sequence(int cntt,int sum){
    
    if(cntt>n){
        return;
    }
    
    if(sum==s){
        if(s==0 && cntt==0){
                cnt--;
        }
        cnt++;
    }
    
    for(int i=cntt; i<n; i++){
        if(check[i]==false){
            check[i]=true;
            answer[cntt]=arr[i];
            sequence(i+1, sum+arr[i]);
            check[i]=false;
        }
    }
}
    
    
int main(void) {
    
    cin >> n >> s;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    sequence(0,0);
    
    cout << cnt;
    
    return 0;
}
