//
//  main.cpp
//  부스트캠프 연습문제1
//
//  Created by 유영우 on 2021/06/23.
//

// 직사강형을 만든다
// 4개 중 3개의 좌표가 주어진다
// v: 점 3개의 좌표가 들어있는 배열
// 직사각형을 만드는 데 필요한 나머지 한 점의 좌표를 return 해라
// 직사각형의 각 변은 x축, y축에 평행
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;

    int x1=0;
    int x1c=0;
    int x2=0;
    int x2c=0;
    int y1=0;
    int y1c=0;
    int y2=0;
    int y2c=0;
    for(int i=0; i<v.size(); i++){
        if(x1c==0){
            x1=v[i][0];
            x1c++;
        }else if(x1 != v[i][0]){
            x2=v[i][0];
            x2c++;
        }else{
            x1c++;
        }
        
        
        if(y1c==0){
            y1=v[i][1];
            y1c++;
        }else if(y1 != v[i][1]){
            y2=v[i][1];
            y2c++;
        }else{
            y1c++;
        }
    }
    
    if(x1c==2){
        ans.push_back(x2);
    }else if(x2c==2){
        ans.push_back(x1);
    }
    
    if(y1c==2){
        ans.push_back(y2);
    }else if(y2c==2){
        ans.push_back(y1);
    }
    
    cout << "Hello Cpp" << endl;

    return ans;
}

int main(void) {
    
    return 0;
}
