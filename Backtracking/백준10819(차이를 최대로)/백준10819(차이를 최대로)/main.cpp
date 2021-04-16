//
//  main.cpp
//  백준10819(차이를 최대로)
//
//  Created by 유영우 on 2021/04/17.
//

#include <iostream>
using namespace std;


int n;
int arr[9];
bool check[9];
int result;

void diff(int cnt, int sum, int sub){
    if(cnt==n){
        result=max(result,sum);
    }else{
        for(int i=0; i<n; i++){
            if(check[i]==false){
                check[i]=true;
                diff(cnt+1,sum+abs(sub-arr[i]),arr[i]);

                check[i]=false;
            }
        }
    }
    
}


int main(void) {
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int j=0; j<n; j++){
        check[j]=true;
        diff(1,0,arr[j]);
        check[j]=false;
    }
    
    cout << result;

    return 0;
}
