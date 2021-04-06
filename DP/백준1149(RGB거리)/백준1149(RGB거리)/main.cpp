//
//  main.cpp
//  백준1149(RGB거리)
//
//  Created by 유영우 on 2021/04/07.
//

#include <iostream>
using namespace std;

int arr[1001][3];
int dp[1001][3];


int n; //집 RGB 비용
// 모든 집을 칠하는 비용의 최솟값

void house(int num){
    dp[1][0]=arr[1][0];
    dp[1][1]=arr[1][1];
    dp[1][2]=arr[1][2];
    
    for(int i=1;i<num;i++){
        for(int j=0;j<3;j++){
            if(j==0){ //1 2
                if(dp[i+1][j+1]==0 || dp[i+1][j+1]>arr[i+1][j+1]+dp[i][j]){
                    dp[i+1][j+1]=arr[i+1][j+1]+dp[i][j];
                }
                if(dp[i+1][j+2]==0 || dp[i+1][j+2]>arr[i+1][j+2]+dp[i][j]){
                    dp[i+1][j+2]=arr[i+1][j+2]+dp[i][j];
                }
                
            }else if(j==1){  // 0 2
                if(dp[i+1][j-1]==0 || dp[i+1][j-1]>arr[i+1][j-1]+dp[i][j]){
                    dp[i+1][j-1]=arr[i+1][j-1]+dp[i][j];
                }
                if(dp[i+1][j+1]==0 || dp[i+1][j+1]>arr[i+1][j+1]+dp[i][j]){
                    dp[i+1][j+1]=arr[i+1][j+1]+dp[i][j];
                }
                
            }else{ // 0 1
                if(dp[i+1][j-2]==0 || dp[i+1][j-2]>arr[i+1][j-2]+dp[i][j]){
                    dp[i+1][j-2]=arr[i+1][j-2]+dp[i][j];
                }
                if(dp[i+1][j-1]==0 || dp[i+1][j-1]>arr[i+1][j-1]+dp[i][j]){
                    dp[i+1][j-1]=arr[i+1][j-1]+dp[i][j];
                }
            }
        }
    }
    
}


int main(void) {
    
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    
    house(n);
    
    int min = dp[n][0];
    for(int j=1; j<3; j++){
        if(min>dp[n][j]){
            min=dp[n][j];
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << min;
    
    return 0;
}
