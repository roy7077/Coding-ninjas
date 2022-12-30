N-Queen Problem
_______________
Send Feedback
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Note: Don't print anything if there isn't any valid configuration.



#include <bits/stdc++.h>

using namespace std;

int board[11][11];

bool isPossible(int n,int row,int col){

// Same Column
  for(int i=row-1;i>=0;i--){
    if(board[i][col] == 1){
      return false;
    }
  }
//Upper Left Diagonal
  for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--){
    if(board[i][j] ==1){
      return false;
    }
  }

  // Upper Right Diagonal

  for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++){
    if(board[i][j] == 1){
      return false;
    }
  }

  return true;
}
void nQueenHelper(int n,int row){
  if(row==n){
    // We have reached some solution.
    // Print the board matrix
    // return

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout << board[i][j] << " ";
      }
    }
    cout<<endl;
    return;

  }

  // Place at all possible positions and move to smaller problem
  for(int j=0;j<n;j++){

    if(isPossible(n,row,j)){
      board[row][j] = 1;
      nQueenHelper(n,row+1);
      board[row][j] = 0;
    }
  }
  return;

}
void placeNQueens(int n){

  memset(board,0,11*11*sizeof(int));

  nQueenHelper(n,0);

}
int main(){

    int n;
    cin>>n;
  placeNQueens(n);
  return 0;
}








--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Rat In A Maze Problem
_____________________
Send Feedback
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.




#include<iostream>
using namespace std;

void printSolution(int **solution, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << solution[i][j] << " ";
    }
  }
  cout << endl;
}
void mazeHelp(int maze[][20], int n, int **solution, int x, int y) {

  if (x == n - 1 && y == n - 1) {
    solution[x][y] = 1;
    printSolution(solution, n);
    solution[x][y] = 0;
    return;
  }
  if (x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 ||
      solution[x][y] == 1) {
    return;
  }
  solution[x][y] = 1;
  mazeHelp(maze, n, solution, x - 1, y);
  mazeHelp(maze, n, solution, x + 1, y);
  mazeHelp(maze, n, solution, x, y - 1);
  mazeHelp(maze, n, solution, x, y + 1);
  solution[x][y] = 0;
}
void ratInAMaze(int maze[][20], int n) {

  int **solution = new int *[n];
  for (int i = 0; i < n; i++) {
    solution[i] = new int[n];
  }
  mazeHelp(maze, n, solution, 0, 0);
}
int main() {
  int n;
  cin >> n;
  int arr[n][20];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  }
  ratInAMaze(arr, n);
}









--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Sudoku Solver
_____________
Send Feedback
Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.




#include<bits/stdc++.h>
using namespace std;
bool cellCheck(int board[][9],int a,int b,int key){
    
    for(int i=a;i<a+3;i++){
        for(int j=b;j<b+3;j++){
            if(board[i][j]==key)
                return false;
        }
    }
    return true;
}

bool rowCheck(int board[][9],int r,int key){
    
    for(int i=0;i<9;i++){
        if(board[r][i]==key)
            return false;
    }
    return true;
}

bool colCheck(int board[][9],int c,int key){
    
    for(int i=0;i<9;i++){
        if(board[i][c]==key)
            return false;
    }
    return true;
}

void printboard(int board[][9]){
    //Print Board
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    
    cout<<"= = = = = = = = = "<<endl;
}
bool solve(int board[][9],int i,int j){
    if(i==8 && j==8){
        if(board[8][8]==0){
            for(int t=1;t<=9;t++){
                if(rowCheck(board,8,t) && colCheck(board,8,t) && cellCheck(board,6,6,t))
                    return true;
            }
            return false;
        }
        else
            return true;
    }    
    bool ans;
    if(board[i][j]==0){
        for(int t=1;t<=9;t++){
                if(rowCheck(board,i,t) && colCheck(board,j,t) && cellCheck(board,3*(i/3),3*(j/3),t)){
                    board[i][j]=t;
                    //cout<<"i: "<<i<<" j: "<<j<<endl;
                    //printboard(board);
                    if(j<8)
                        ans=solve(board,i,j+1);
                    if(j==8)
                        ans=solve(board,i+1,0);
                }
            }
        if(board[i][j]==0)
            return false;
        if(ans==false)
            board[i][j]=0;
    }
    else{
        if(j<8)
            ans=solve(board,i,j+1);
        if(j==8)
            ans=solve(board,i+1,0);
    }
    return ans;
    
}


bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    bool ans=solve(board,0,0);
    
    return ans;


}

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Subset Sum
__________
Send Feedback
You are given an array of integers and a target K. You have to find the count of subsets of the given array that sum up to K.
Note:
1. Subset can have duplicate values.
2. Empty subset is a valid subset and has sum equal to zero.




#include<iostream>
using namespace std;

int subsetsum(int *arr,int k,int n)
{
    
    if(n==0)
    {
        if(k==0)
            return 1;
        else
            return 0;
            
    }
    int i=subsetsum(arr+1,k-arr[0],n-1);
    int j=subsetsum(arr+1,k,n-1);
    return i+j;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int *arr=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<subsetsum(arr,k,n)<<endl;
        
    }
    return 0;
}






-----------------------------------------------------------------------------------------------END-------------------------------------------------------------------------------------------