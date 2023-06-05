#include <iostream>

using namespace std;

int row_move=1;
int col_move=1;

void find_pos(int n, int pos_row, int pos_col, int& count){
    if(pos_row == n && pos_col == n){
        count++;
        return;
    }
    if(pos_row > n || pos_col > n || pos_col > pos_row) return;

    find_pos(n, pos_row + row_move, pos_col, count);
    find_pos(n, pos_row, pos_col + col_move, count);
}

int main(){
    int n;
    cin >> n;

    int pos_row=0, pos_col= 0;
    int count=0;
    find_pos(n, pos_row, pos_col, count);
    cout << count << endl;
}