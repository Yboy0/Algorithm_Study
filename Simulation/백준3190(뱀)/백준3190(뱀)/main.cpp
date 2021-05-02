//
//  main.cpp
//  백준3190(뱀)
//
//  Created by 유영우 on 2021/05/02.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// 뱀은 1,1부터
//사과를 먹으면 길이가 늘어난다
// 매 초 마다 이동
// 사과 있으면 사과없어지고 이동
// 사과 없으면 꼬리칸 소멸
// 벽 또는 자기자신과 몸 충돌나면 게임오버

struct Move{
    int sec;
    char dir;
};

//struct snakeBody{
//    int y;
//    int x;
//}


int n; //보드의 크기
int k; // 사과의 개수
int y,x; // 사과 있는 곳
int l; // 뱀의 방향 전환 횟수 L:왼쪽 D:오른쪽 으로 990도 회전
int arr[102][102]; //보드판
queue<Move>q;
int s;
char d;
int endT;
//int dy[2]={1,6};
//int dx[2]={1,6};
bool check;
//vector<snakeBody>v;


void snake(int second, int yy, int xx, int type){ //yy,xx는 뱀의 머리
    cout << xx << " " << yy << "\n";
    
    if(xx > n || yy > n || xx < 1 || yy < 1){
        check = true;
        cout << second;
        return;
    }
           
    // 자기 몸에 부딫이는 경우
    if(arr[yy][xx] == 2){
        check = true;
        cout << second;
        return;
    }
    
    if(!check){ // 게임 진행
        //사과있는지 check
        if(arr[yy][xx] == 1){
            arr[yy][xx]++; // 몸커지기
        }
        // 방향 전환 되는지 확인
        bool ch =false;
        if(!q.empty()){
            if(second == q.front().sec){
                    ch=true;
                    if(q.front().dir == 'D'){//오른쪽
                        if(type == 1){ // xx++
                            snake(second+1,++yy,xx,2);
                        }else if(type == 2){ //yy++
                            snake(second+1,yy,++xx,1);
                        }else if(type == 3){ //xx--
                            snake(second+1,--yy,xx,4);
                        }else{ //yy--
                            snake(second+1,yy,++xx,1);
                        }
                    }else{ //왼쪽
                        if(type == 1){ // xx++
                            snake(second+1,--yy,xx,4);
                        }else if(type == 2){ //yy++
                            snake(second+1,yy,--xx,3);
                        }else if(type == 3){ //xx--
                            snake(second+1,++yy,xx,2);
                        }else{ //yy--
                            snake(second+1,yy,--xx,3);
                        }
                    }
                    q.pop();
            }
        }
       
        if(!ch){
            if(type == 1){ // xx++
                snake(second+1,yy,++xx,1);
            }else if(type == 2){ //yy++
                snake(second+1,++yy,xx,2);
            }else if(type == 3){ //xx--
                snake(second+1,yy,--xx,3);
            }else{ //yy--
                snake(second+1,--yy,xx,4);
            }
        }
    }
}
    


int main(void) {
    cin >> n;
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> y>> x;
        arr[y][x] = 1;
    }
    cin >> l;
    for(int i=0; i<l; i++){
        cin >> s >> d;
        Move move = {s,d};
        q.push(move);
    }
    
   snake(0,1,1,1);
}
