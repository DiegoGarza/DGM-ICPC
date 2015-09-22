#include <iostream>
#include <vector>

using namespace std;

bool validateSudoku(vector<vector<int> >& mat){
    vector<bitset<9> > rows(9), cols(9), squares(9);

    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat.size(); j++){
            int val = mat[i][j] - 1;
            if(rows[i][val] || cols[j][val] || squares[(i/3)*3 + j/3][val]) {
                return false;
            }
            rows[i][val] = 1;
            cols[j][val] = 1;
            squares[(i/3)*3 + j/3][val] = 1;
        }
    }

    return true;
}

int main(){
    vector<vector<int> > sudoku(9, vector<int>(9));
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>sudoku[i][j];
        }
    }
    cout<<validateSudoku(sudoku)<<endl;
    return 0;
}
