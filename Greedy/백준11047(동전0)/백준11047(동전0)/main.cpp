//
//  main.cpp
//  백준11047(동전0)
//
//  Created by 유영우 on 2021/02/15.
//

#include <iostream>
using namespace std;

//k원 만드는데 총 필요한 동전 개수의 최솟값 구하기
int n,k; //n: 동전의 종류, k: 총 금액
int coinCnt;
int arr[11];

void coin(){
    for(int i=n-1; i>=0; i--){
        if(k == 0){
            return;
        }
        if(arr[i]<=k){
            while(arr[i]<=k){
                k = k-arr[i];
                coinCnt++;
            }
        }
    }
}

int main(void) {
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    coin();
    cout << coinCnt;
    return 0;
}
