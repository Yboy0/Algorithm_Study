//
//  main.cpp
//  프로그래머스_수식 최대화(Level2)
//
//  Created by 유영우 on 2021/05/07.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 대회 참가자들에게 숫자와 연산문자3개(+,-,*)로 이루어진 연산 수식이 전달됨
// 연산수식 포함된 연산자의 우선순위를 배치하여 만들 수 있는 최대 숫자 제출해야함
// 결과가 음수라면 해당 숫자의 절댓값으로 변환하여 제출
// 만들 수 있는 최대 숫자 뽑기
// expression은 중위 표기법으로 주어지고 숫자에 음수가 주어지지는 않는다

char a[3] = {'+','-','*'};
char  pri[3];
long long solution(string expression) {
    long long answer = 0;
    

    
    // 백트래킹으로 우선순위 경우의 수 뽑기
    
    // expression 연산자, 숫자 구분해서 큐에 넣기
    
    // 큐 2개로 값 구하고 answer와 비교하기
    
    
    
    
    return answer;
}


int main(void) {
    
    string expression = "100-200*300-500+20";

    return 0;
}
