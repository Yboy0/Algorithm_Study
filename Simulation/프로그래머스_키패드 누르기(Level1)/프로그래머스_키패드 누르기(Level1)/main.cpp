//
//  main.cpp
//  프로그래머스_키패드 누르기(Level1)
//
//  Created by 유영우 on 2021/05/07.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 엄지손가락만 이용하여 폰의 숫자 입력 해야함
// 왼손은 처음에 * ,  오른손은 #에서 시작
// 손가락 규칙
  // 이동 한 칸은 거리 1에 해당
  // 엄지는 상하좌우 4가지 방향으로만 이동가능.
  // x=0를 입력할때는 왼만 사용
  // x=2를 입력할때는 오만 사용
  // x=1 입력할때는 왼, 오 중 더 가까운 위치에 있는 쪽 사용
  // 오, 왼 거리가 같다면 오른손잡이는 오, 왼손잡이는 왼을 사용

// numbers: 순서대로 누를 번호가 담긴 배열 크기: 1~1000 원소값: 0~9
// hands: 왼손잡인지 오른손잡이인지 나타내는 문자열

//000
//000
//000
//000
// -> y=3, x=2인 배열

//int keypad[4][3];
//queue<pair<int, int>>q;


string solution(vector<int> numbers, string hand) {
    string answer = "";

    int ly=3;
    int lx=0;
    int ry=3;
    int rx=2;
    
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            answer = answer+"L";
            //왼엄지 위치 이동
            if(numbers[i]==1){
                ly=0;
                lx=0;
            }else if(numbers[i]==4){
                ly=1;
                lx=0;
                
            }else{ //7
                ly=2;
                lx=0;
            }
            
            
        }else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
            answer = answer+"R";
            //오엄지 위치 이동
            if(numbers[i]==3){
                ry=0;
                rx=2;
                
            }else if(numbers[i]==6){
                ry=1;
                rx=2;
            }else{ //9
                ry=2;
                rx=2;
            }
            
            
        }else{ // 2 5 8
            // 왼손, 오른손 거리 가까운 곳 선택
            //두 엄지의 거리가 같다면 hands에 따라 선택
            int ld=0; //왼 거리
            int rd=0; //오 거리
            if(numbers[i]==2){ //0,1
                ld = abs(ly-0)+abs(lx-1);
                rd = abs(ry-0)+abs(rx-1);
                if(ld>rd){//오거리가 작을 때
                    answer=answer+"R";
                    ry = 0;
                    rx = 1;
                    
                }else if(ld<rd){// 왼거리가 작을 때
                    answer=answer+"L";
                    ly = 0;
                    lx = 1;
                    
                }else{//같다면
                    if(hand=="right"){
                        answer=answer+"R";
                        ry = 0;
                        rx = 1;
                    }else{
                        answer=answer+"L";
                        ly = 0;
                        lx = 1;
                    }
                }
                
            }else if(numbers[i]==5){//1,1
                ld = abs(ly-1)+abs(lx-1);
                rd = abs(ry-1)+abs(rx-1);
                if(ld>rd){//오거리가 작을 때
                    answer=answer+"R";
                    ry = 1;
                    rx = 1;
                    
                }else if(ld<rd){// 왼거리가 작을 때
                    answer=answer+"L";
                    ly = 1;
                    lx = 1;
                    
                }else{//같다면
                    if(hand=="right"){
                        answer=answer+"R";
                        ry = 1;
                        rx = 1;
                    }else{
                        answer=answer+"L";
                        ly = 1;
                        lx = 1;
                    }
                }
                
            }else if(numbers[i]==8){//2,1
                ld = abs(ly-2)+abs(lx-1);
                rd = abs(ry-2)+abs(rx-1);
                if(ld>rd){//오거리가 작을 때
                    answer=answer+"R";
                    ry = 2;
                    rx = 1;
                    
                }else if(ld<rd){// 왼거리가 작을 때
                    answer=answer+"L";
                    ly = 2;
                    lx = 1;
                    
                }else{//같다면
                    if(hand=="right"){
                        answer=answer+"R";
                        ry = 2;
                        rx = 1;
                    }else{
                        answer=answer+"L";
                        ly = 2;
                        lx = 1;
                    }
                }
                
            }else{ //0   3,1
                ld = abs(ly-3)+abs(lx-1);
                rd = abs(ry-3)+abs(rx-1);
                if(ld>rd){//오거리가 작을 때
                    answer=answer+"R";
                    ry = 3;
                    rx = 1;
                    
                }else if(ld<rd){// 왼거리가 작을 때
                    answer=answer+"L";
                    ly = 3;
                    lx = 1;
                    
                }else{//같다면
                    if(hand=="right"){
                        answer=answer+"R";
                        ry = 3;
                        rx = 1;
                    }else{
                        answer=answer+"L";
                        ly = 3;
                        lx = 1;
                    }
                }
            }
        }
    }
    
    return answer;
}


int main(void) {
    //"LRLLLRLLRRL"
    vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    
    string hand = "right";
    
    cout << solution(numbers, hand);
}
