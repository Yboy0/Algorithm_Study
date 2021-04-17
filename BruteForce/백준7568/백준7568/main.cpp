//
//  main.cpp
//  백준7568
//
//  Created by 유영우 on 2021/01/29.
//

#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> grade;
int main(void) {
    cin >> n;
    int data[n][2];
    grade.assign(n,1);
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        data[i][0]=x;
        data[i][1]=y;
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(data[i][0] > data[j][0] && data[i][1] > data[j][1]){
                grade[j]++;
            }
            else if(data[i][0] < data[j][0] && data[i][1] < data[j][1]){
                grade[i]++;
            }
        }
       
    }
    for(int i=0; i<n; i++){
        cout<< grade[i] << " ";
    }
    return 0;
}
