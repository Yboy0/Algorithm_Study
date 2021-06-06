//
//  main.cpp
//  프로그래머스_등굣길(Level3)
//
//  Created by 유영우 on 2021/06/06.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> puddless;
int area[101][101];
int dp[101][101];

int goSchool(int n, int m){
    
    if(n ==1 && m ==1){
        return 1;
    }
    if(dp[n][m] !=0){
        return dp[n][m]%1000000007;
    }
    
    if(area[n-1][m] != 1 && n-1 >= 1){
        dp[n][m] += goSchool(n-1, m)%1000000007;
    }
    if(area[n][m-1] != 1 && m-1 >= 1){
        dp[n][m] += goSchool(n, m-1)%1000000007;
    }
    
    return dp[n][m]%1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0; i<puddles.size(); i++){
        area[puddles[i].at(1)][puddles[i].at(0)] = 1;
    }
    
    answer = goSchool(n,m);
//    answer = (int)answerT;
    
//    cout << "area" << endl;
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=m; j++){
//            cout << area[i][j] << " ";
//        }cout << endl;
//    }
//
//    cout << "dp" << endl;
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=m; j++){
//            cout << dp[i][j] << " ";
//        }cout << endl;
//    }
    
    return answer;
}


int main(void) {
    vector<int> a;
    a.push_back(2);
    a.push_back(2);
    
    int b = 2000;
    cout << b%1000000007;

}
