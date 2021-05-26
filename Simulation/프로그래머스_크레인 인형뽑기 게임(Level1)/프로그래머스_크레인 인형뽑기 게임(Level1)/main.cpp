#include <string>
#include <vector>
using namespace std;

// 인형이 없는 칸은 빈 칸
// 인형은 격자의 가장 아래 칸부터 차곡차곡 쌓여 있다
// 게임 사용자는 크레인을 좌우로 움직여서 멈춘 위치에서 가장 위에 있는 인형 집어 올릴 수 있다
// 집어 올린 인형은 바구니에 쌓인다
// 바구니의 가장 아래 칸 부터 인형이 순서대로 쌓이게 된다
// 같은 모양의 인형 두 개가 바구니에 연속해서 쌓이게 되면 두 인형은 바구니에서 사라진다.
// board: 격자의 상태가 담겨있음
// moves: 인형의 집기 위해 크레인을 작동시킨 위치가 담긴 배열

// 크레인을 모두 작동시킨 후 터트려져 사라진 인헝의 개수를 return

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer =0;
    vector<int>bucket;
    
    for(int i=0;i<moves.size();i++){
        for(int j=0; j<board.size();j++){
            if(board[j][moves[i]-1]>0){
                if(bucket.size()==0){
                    bucket.push_back(board[j][moves[i]-1]);
                }else{
                    if(bucket.back() == board[j][moves[i]-1]){
                        answer+=2;
                        bucket.pop_back();
                    }else{
                        bucket.push_back(board[j][moves[i]-1]);
                    }
                }
                 board[j][moves[i]-1]=0;
                 break;
            }
           
        }
    }
    return answer;
}
}
