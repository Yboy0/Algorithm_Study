//
//  main.cpp
//  백준11399(ATM)
//
//  Created by 유영우 on 2021/02/12.
//

#include <iostream>
#include <algorithm>
using namespace std;
int n; //n: 사람 수
int atmT;
int arr[1001];

void atm(){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for(int i=0;i<n;i++){
        atmT+=arr[i];
        for(int j=0;j<i;j++){
            atmT+=arr[j];
        }
    }
    cout << atmT;
}

int main(void) {
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    atm();  
    return 0;
}
