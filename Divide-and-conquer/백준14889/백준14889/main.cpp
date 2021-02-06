//
//  main.cpp
//  백준14889
//
//  Created by 유영우 on 2021/02/04.
//

#include <iostream>
#include <vector>

using namespace std;
int N,cnt;
int arr[20][20];

struct ST{
    int y;
    int x;
    int value;
};

vector<ST> v;

int soccer(){
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            ST st = {i,j,arr[i][j]+arr[j][i]};
            v.push_back(st);
        }
    }
    int min = 200;
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1; j<v.size();j++){
            if(v[i].x != v[j].x && v[i].y != v[j].y){
                if(abs(v[i].value-v[j].value)<min){
                    min = abs(v[i].value-v[j].value);
                }
            }
        }
    }
    return min;
}

int main(void) {
    cin >> N;
    for(int i=0 ; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    cout << soccer();
    
    
    return 0;
}
