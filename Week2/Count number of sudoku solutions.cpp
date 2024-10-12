/*Description
Write a program to compute the number of sudoku solutions (fill the zero elements of a given partial sudoku table)
Fill numbers from 1, 2, 3, .., 9 to 9 x 9 table so that:
Numbers of each row are distinct
Numbers of each column are distinct
Numbers on each sub-square 3 x 3 are distinct
Input
Each line i (i = 1, 2, ..., 9) contains elements of the ith
row of the Sudoku table: elements are numbers from 0 to 9 (value 0 means the empty cell of the table)
Output
Write the number of solutions found
Example
Input
0 0 3 4 0 0 0 8 9
0 0 6 7 8 9 0 2 3
0 8 0 0 2 3 4 5 6
0 0 4 0 6 5 0 9 7
0 6 0 0 9 0 0 1 4
0 0 7 2 0 4 3 6 5
0 3 0 6 0 2 0 7 8
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
Output
64*/
#include<iostream>
#include<vector>
using namespace std;
bool check(vector<vector<int>> &board, int row, int col, int num){
    //check the row 
     for(int x=0; x < 9; x++){
        if(board[row][x]==num){
            return false;
        }
     }
     //check the col
     for(int x=0; x < 9; x++){
        if(board[x][col]==num){
            return false;
        }
     }
     //check the square
     int row1=row-row%3;
     int col1=col-col%3;
     for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i+row1][j+col1]==num){
                return false;
            }
        }
     }
     return true;
}
int solve(vector<vector<int>> &board){
   for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
        if(board[i][j]==0){
            int count=0;
        for(int num=1; num<=9; num++){
            if(check(board, i,j,num)){
                board[i][j]=num;
                count+=solve(board);
                board[i][j]=0;
            }
        }
        return count;
    }
   }
}
return 1;
}
int main(){
   vector<vector<int>> board(9, vector<int>(9));
   for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
        cin>>board[i][j];
    }
   }
   int sol=solve(board);
   cout<<sol;
}
