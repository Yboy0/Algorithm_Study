//
//  main.cpp
//  백준2805(나무 자르기)
//
//  Created by 유영우 on 2021/05/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 나무 m미터
// 목재절단기
//   높이 h미터
// 높이가 h보다 큰 나무는 h위의 부분이 잘린다
// 낮은 부분은 잘리지 않는다
// 적어도 m미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구해라

long long n,m; // n:나무의 수, m:나무의 길이
long long tree;
long long h;
long long answerH;
long long  high;
long long  low;
vector<long long>trees;

void cut(){
    
    while(low<high){
//
//        cout << low << " " << high << endl;
        h = (low+high)/2;
    
        long long copym = m;
        
        for(long long i=0; i<n; i++){
            if(h<trees[i]){
                copym-=trees[i]-h;
            }
        }
        
        if(copym<=0){
            if(answerH<h){
                answerH=h;
            }
            low=h+1;
        }else{
            high=h;
        }
        
    }
}

int main(void) {
    cin >> n >> m;
    for(long long i=0; i<n; i++){
        cin >> tree;
        if(tree>high){
            high=tree;
        }
        trees.push_back(tree);
    }
    
    cut();
    cout << answerH;
}
