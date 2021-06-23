//
//  main.cpp
//  프로그래머스_약수와 개수와 덧셈(Level1)
//
//  Created by 유영우 on 2021/06/23.
//

#include <iostream>
#include <vector>
using namespace std;

// 두 정수 left, right
// left 부터 right까지 모든 수들 중, 약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수를 return

int solution(int left, int right) {
    int answer = 0;
    
    for(int i=left; i<right+1; i++){
        int count =0;
        for(int j=1; j<i+1; j++){
            if(i%j==0){
                count ++;
            }
        }
        if(count%2==0){
            answer+=i;
        }else{
            answer-=i;
        }
    }
    
    return answer;
}


int main(void) {
    return 0;
}
