#include<iostream>
#include <vector>

using namespace std;

#define SIZE 7
#define POSSIBLE_N 33

#define N 'N'
#define O 'O'
#define X 'X'

vector<vector<char>> board(SIZE);
vector<vector<int>> indices(POSSIBLE_N);

struct possible_moves{
    string move;
    int pos_col;
    int pos_row;
};
const struct possible_moves directions[4]={{"UP",0,-2},{"DOWN",0,2},{"RIGHT",2,0},{"LEFT",-2,0}};

void Vector_init(){
    char x;
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cin>>x;
            board[i].push_back(x);
        }
    }
}
int conditions(int pos_row, int pos_col){
    if(pos_col >= SIZE || pos_row >= SIZE || pos_col < 0 || pos_row < 0) return 1;
    else return 0;
}
int make_move( int move_type, int pos_row, int pos_col, int go_back){
    int prior_row,prior_col;
    int next_row = pos_row + directions[move_type].pos_row;
    int next_col = pos_col + directions[move_type].pos_col;

    prior_row = (next_row + pos_row)/2;
    prior_col = (next_col + pos_col)/2;

    if(go_back==0){
        if(conditions(next_row, next_col) || board[next_row][next_col]!= O || board[prior_row][prior_col]!= N) return 0;
    }
    if(go_back){
        board[pos_row][pos_col] = N;
        board[next_row][next_col] = O;
        board[prior_row][prior_col] = N;
    }
    else{
        board[pos_row][pos_col] =O;
        board[next_row][next_col] =N;
        board[prior_row][prior_col] =O;
    }
    
    return 1;
}
int countNs(){
    int count=0;
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(board[i][j]== N) count++;
        }
    }
    return count;
}
void findNs() {
    int j=0;
    char target = N;
    for(int i=0; i<SIZE; i++){
        for (auto element = board[i].begin(); element != board[i].end(); element++) {
            if (*element == target) {
                indices[j].push_back(i);
                indices[j].push_back(distance(board[i].begin(), element));
                j++;
            }
        }
    }
}
int solve(int number_of_n, vector<struct possible_moves>& next_moves){

    if(countNs()==1 && board[3][3]==N) return 1;
    for(int i=0; i<number_of_n; i++){
        int pos_row = indices[i][0];
        int pos_col = indices[i][1];
        if(board[pos_row][pos_col]==X or board[pos_row][pos_col]==O) continue;
        for(int move_no=0; move_no < 4; move_no++){
        if(make_move(move_no, pos_row, pos_col,0)==0) continue;
            if(solve(number_of_n, next_moves)){
                next_moves.push_back({directions[move_no].move, pos_row, pos_col});
                return 1;
            }
            make_move( move_no, pos_row, pos_col, 1);
        }
    }
    return 0;
}
int main(){
    Vector_init();
    vector<struct possible_moves> next_moves;
    findNs();
    char alphabet[SIZE]={'A','B','C','D','E','F','G'};
    int number_of_n=countNs();

    if(solve(number_of_n, next_moves)){
        for(int count=next_moves.size()-1; count>-1; count--){
            int num_col=next_moves[count].pos_col;
            int num_row=next_moves[count].pos_row+1;
            cout<< alphabet[num_col] << num_row <<" "<< next_moves[count].move <<endl;
        }
    }
    else cout<<"loser"<<endl;
    return 0;
}