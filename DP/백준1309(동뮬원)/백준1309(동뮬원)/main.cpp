//
//  main.cpp
//  백준1309(동뮬원)
//
//  Created by 유영우 on 2021/04/05.
//

#include <iostream>
using namespace std;

int n;
int arr[1000][3];

void lion(int a){
    arr[0][1]=1;
    arr[0][2]=1;
    arr[1][0]=1;
 
    for(int i=1;i<=a;i++){
        arr[i][1]=arr[i-1][0]+arr[i-1][1];
        arr[i][2]=arr[i-1][0]+arr[i-1][2];
    
        arr[i+1][0]=arr[i][0]+arr[i][1]+arr[i][2];
    }
    
}


int main(void) {
    cin >> n;
    lion(n);

    cout << arr[n+1][0]%9901;
    return 0;
}
