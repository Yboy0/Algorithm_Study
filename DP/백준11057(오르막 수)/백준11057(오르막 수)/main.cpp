//
//  main.cpp
//  백준11057(오르막 수)
//
//  Created by 유영우 on 2021/05/30.
//

#include <iostream>
using namespace std;
//오르막 수는 수의 자리가 오름차순을 이루는 수를 말함
// 인접한 수가 같아도 오름차순

//n이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 만들어라.

int n;
long long dp[1002][10];
int result;

int main(void) {
    cin >> n;
    
    for(int i=0;i<10;i++){ //첫째 자리수 setting
        dp[1][i]=1;
    }
    
    for(int i=2;i<=n;i++){

        for(long long j=0;j<10;j++){
            
            

                for(long long k=j;k<10;k++){
                    dp[i][k]++;
                }

        }
        
        for(int k=0; k<10; k++){
            cout<< dp[i][k] << " ";
        }
        cout << endl;
    }

    for(int i=0;i<10;i++){
        result+=dp[n][i];
    }
    cout << result;
    
    return 0;
}
