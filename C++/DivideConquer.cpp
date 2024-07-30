#include<bits/stdc++.h>
using namespace std;
//merge Sort
void merge(int*arr,int s,int e){//for merging two sorted arrays
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    // creating different new arrays
    int* left=new int[len1];
    int* right=new int[len2];
    //copying the actual values to arrays
    int k=s;
    for (int i = 0; i < len1; i++,k++)
    {
        left[i]=arr[k];
    }
    for(int i=0;i<len2;i++,k++){
        right[i]=arr[k];
    }
    int ptrLeft=0;
    int ptrRight=0;
    while (ptrLeft<len1 && ptrRight<len2)
    {
        if(left[ptrLeft]<right[ptrRight]){
            arr[s]=left[ptrLeft];
            ptrLeft++;
        }
        else{
            arr[s]=right[ptrRight];
            ptrRight++;
        }
        s++;
    }
    while(ptrLeft<len1){
        arr[s] = left[ptrLeft];
        ptrLeft++;
        s++;
    }
    while(ptrRight<len2){
        arr[s] = right[ptrRight];
        ptrRight++;
        s++;
    }   
}
void mergeSort(int*arr,int s,int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    //leftPart karke lau recursion
    mergeSort(arr,s,mid);
    //rightPart karke lau recursion
    mergeSort(arr,mid+1,e);
    //now merge two sorted arrays
    merge(arr,s,e);

}

//Quick Sort
int partition(int arr[], int s, int e) {
  //step1: chooose pivotelement
  int pivotIndex = s;
  int pivotElement = arr[s];

  //step2: find right position for pivot Element and place it there
  int count = 0;
  for(int i=s+1; i<=e; i++) {
    if(arr[i] <= pivotElement) {
      count++;
    }
  }
  //jab main loop se bahar hua, toh mere paas pivot ki right position ka index ready h 
  int rightIndex = s + count;
  swap(arr[pivotIndex], arr[rightIndex]);
  pivotIndex = rightIndex;

  //Step3: left me chote and right me bade
  int i = s;
  int j = e;

  while( i < pivotIndex && j > pivotIndex) {
    while(arr[i] <= pivotElement) {
      i++;
    }
    while( arr[j] > pivotElement){
      j--;
    }

    //2 case ho sakte h -> 
    //A-> you found the elements to swap
    //B-> no need to swap
    if(i < pivotIndex && j > pivotIndex)
      swap(arr[i],arr[j]);
  }
  return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
  //base case
  if(s >= e)
    return ;

  //partition logic, return pivotIndex
  int p = partition(arr, s, e);

  //recursive calls
  //pivot element -> left
  quickSort(arr, s, p-1);

  //pivot element -> right
  quickSort(arr, p+1, e);

}

//permutations of string
void printPermutations(string& s,int i){
  //base case
  if(i>=s.length()){
    cout<<s<<" ";
    return;
  }
  //swapping
  for(int j=i;j<s.length();j++){
    //swap
    swap(s[i],s[j]);
    //rec all
    printPermutations(s,i+1);
    //backtracking->to recreate the original input string;
    swap(s[i],s[j]);

  }

}

//Rat Maze Problem
bool isSafe(int i, int j, int row, int col, int arr[][4],
            vector<vector<bool>> &visited)
{
  if (((i >= 0 && i < row) && (j >= 0 && j < col)) &&
      (arr[i][j] == 1) &&
      (visited[i][j] == false))
  {
    return true;
  }
  else
  {
    return false;
  }
}

void solveMaze(int arr[][4], int row, int col, int i, int j,vector<vector<bool>> &visited, vector<string> &path, string output)
{

  // base case
  if (i == row - 1 && j == col - 1)
  {
    // answer found
    path.push_back(output);
    return;
  }

  // Down -> i+1, j
  if (isSafe(i + 1, j, row, col, arr, visited))
  {
    visited[i + 1][j] = true;
    solveMaze(arr, row, col, i + 1, j, visited, path, output + 'D');
    // backtrack
    visited[i + 1][j] = false;
  }

  // Left -> i, j-1
  if (isSafe(i, j - 1, row, col, arr, visited))
  {
    visited[i][j - 1] = true;
    solveMaze(arr, row, col, i, j - 1, visited, path, output + 'L');
    // backtrack
    visited[i][j - 1] = false;
  }

  // Right -> i, j+1
  if (isSafe(i, j + 1, row, col, arr, visited))
  {
    visited[i][j + 1] = true;
    solveMaze(arr, row, col, i, j + 1, visited, path, output + 'R');
    // backtrack
    visited[i][j + 1] = false;
  }

  // Up-> i-1, j
  if (isSafe(i - 1, j, row, col, arr, visited))
  {
    visited[i - 1][j] = true;
    solveMaze(arr, row, col, i - 1, j, visited, path, output + 'U');
    // backtrack
    visited[i - 1][j] = false;
  }
}


//N -Qneen Problem
void printSolution(vector<vector<char>>&board,int n){
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <n; j++)
    {
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
    
  }
  cout<<endl;
  
}
unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperLeftDiagnolCheck;
unordered_map<int, bool> bottomLeftDiagnolCheck;
bool isSafe(int row,int col,vector<vector<char>>&board,int n){
  /*
  int i=row;
  int j=col;
  //check now
  while (j>=0)  
  {
    if(board[i][j]=='Q'){
      return false;
    }
    j--;
  }
  //check upper left diagonal
  i=row;
  j=col;
  while (i>=0 && j>=0)
  {
    if(board[i][j]=='Q'){
      return false;
    }
    i--;
    j--;
  }
   //bottom left diagonal
  i=row;
  j=col;
  while (i<n && j>=0)
  {
    if(board[i][j]=='Q'){
      return false;
    }
    i++;
    j--;
  }
  //kahin pr bhi queen nahi mili
  //iska matlab ye position safe hai
  //iska matlab eturn kardo true
  return true;
  */

  if (rowCheck[row] == true){
    return false;
  }
  if (upperLeftDiagnolCheck[n - 1 + col - row] == true){
    return false;
  }
  if (bottomLeftDiagnolCheck[row + col] == true){
    return false;
  }
  return true;
}
void N_Queen(vector<vector<char>>&board,int col,int n){
  if(col>=n){
    printSolution(board,n);
    return;
  }
  //1 case solve karna hai,baki recursion karega
  /*
  for(int row=0;row<n;row++){
    if(isSafe(row,col,board,n)){
      //rhk do
      board[row][col]='Q';
      //recursion soln layega
      N_Queen(board,col+1,n);
      //backtracking
      board[row][col]='-'; 

    }
    
  }
  */
  for (int row = 0; row < n; row++)
  {
    if (isSafe(row, col, board, n))
    {
      // rakh do
      board[row][col] = 'Q';
      rowCheck[row] = true;
      upperLeftDiagnolCheck[n - 1 + col - row] = true;
      bottomLeftDiagnolCheck[row + col] = true;

      // recursion solution laega
      N_Queen(board, col + 1, n);
      // backtracking
      board[row][col] = '_';
      rowCheck[row] = false;
      upperLeftDiagnolCheck[n - 1 + col - row] = false;
      bottomLeftDiagnolCheck[row + col] = false;
    }
  }
}





//Generate all Paranthesis
void generate(vector<string>&ans,int n,int used_open,int used_close,int rem_open,int rem_close,string output){
  //base case
  if(rem_open==0 && rem_close==0){
    ans.push_back(output);
    return;
  }
  //include open bracket
  if(rem_open>0){
    output.push_back('(');
    generate(ans,n,used_open+1,used_close,rem_open-1,rem_close,output);
    //backtracking
    output.pop_back();
  }
  // include close bracket
  if(rem_close>rem_open){
    output.push_back(')');
    generate(ans,n,used_open,used_close+1,rem_open,rem_close-1,output);
    output.pop_back();

  }

}
vector<string>generateParanthesis(int n){
  int used_open=0;
  int used_close=0;
  int rem_open=n;
  int rem_close=n;
  string output="";
  vector<string>ans;
  generate(ans,n,used_open,used_close,rem_open,rem_close,output);
  return ans;

}

//Letter Combinations of a Phone Number
void solve(vector<string> &ans, int index, string output, string digits, vector<string> &mapping)
{
  // base case
  if (index >= digits.length())
  {
    ans.push_back(output);
    return;
  }

  // 1 case solve, baaki recursion
  int digitInteger = digits[index] - '0';
  string value = mapping[digitInteger];
  for (int i = 0; i < value.length(); i++)
  {
    // include
    output.push_back(value[i]);
    // recursive call
    solve(ans, index + 1, output, digits, mapping);
    // backtrack
    output.pop_back();
  }
}

vector<string> letterCombinations(string digits)
{
  vector<string> ans;
  // empty string k liye answer empty array hoga
  if (digits.length() == 0)
    return ans;

  int index = 0;
  string output = "";
  vector<string> mapping(10);
  mapping[2] = "abc";
  mapping[3] = "def";
  mapping[4] = "ghi";
  mapping[5] = "jkl";
  mapping[6] = "mno";
  mapping[7] = "pqrs";
  mapping[8] = "tuv";
  mapping[9] = "wxyz";
  solve(ans, index, output, digits, mapping);

  return ans;
}




//Suduku Solver
bool isSafe(int row, int col, vector<vector<char>> &board, char value)
{
  int n = board.size();
  // row check
  for (int j = 0; j < n; j++)
  {  
    if (board[row][j] == value)
      return false;
  }
  // col check
  for (int i = 0; i < n; i++)
  {
    if (board[i][col] == value)
      return false;
  }
  // 3*3 box check
  for (int i = 0; i < n; i++)
  {
    if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == value)
      return false;
  }

  return true;
}

bool solve(vector<vector<char>> &board)
{
  int n = board.size();

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // check for empty cell
      if (board[i][j] == '.')
      {
        // try to fill with values ranging from 1 to 9
        for (char val = '1'; val <= '9'; val++)
        {
          // check for safety
          if (isSafe(i, j, board, val))
          {
            // insert
            board[i][j] = val;
            // recursion sambal lega
            bool remainingBoardSolution = solve(board);
            if (remainingBoardSolution == true)
            {
              return true;
            }
            else
            {
              // backtrack
              board[i][j] = '.';
            }
          }
        }
        // if 1 se 9 tak koi bhi value se solution
        // nahi nikla ,current cell pr,
        // that means piche kahin pr galti h ,
        // go back by returning false
        return false;
      }
    }
  }
  // all cells filled
  return true;
}
void solveSudoku(vector<vector<char>> &board)
{
  solve(board);
}

int main(){
    // int arr[]={1,5,2,3,7,4,8,6};
    // mergeSort(arr,0,7);
    // for(int i=0;i<8;i++){
    //     cout<<arr[i]<<" ";
    // }

    // int arr[] = {8, 1, 3, 4, 20, 50, 50, 50, 50, 50, 5, 1, 1, 1, 1, 2, 2, 2, 50, 30};
    // int n = 20;
    // int s = 0;
    // int e = n - 1;
    // quickSort(arr, s, e);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // string s="abc";
    // printPermutations(s,0);


  // int maze[4][4] = {{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
  // if (maze[0][0] == 0)
  // {
  //   cout << "No Path Exists " << endl;
  //   return 0;
  // }
  // int row = 4;
  // int col = 4;
  // vector<vector<bool>> visited(row, vector<bool>(col, false));
  // // src ki value k true mark kredete h
  // visited[0][0] = true;
  // vector<string> path;
  // string output = "";
  // solveMaze(maze, row, col, 0, 0, visited, path, output);
  // cout << "printing the results " << endl;
  // for (auto i : path)
  // {
  //   cout << i << " ";
  // }
  // cout << endl;
  // if (path.size() == 0)
  // {
  //   cout << "No Path Exists " << endl;
  // }
  // return 0;



  // int n=4;
  // vector<vector<char>>board(n,vector<char>(n,'-'));
  // int col=0;//to which position Q is placed
  // // 0->empty cell
  // //1->qneen at the cell
  // N_Queen(board,col,n);



  // int n=2;
  // vector<string>ans=generateParanthesis(n);
  // for(auto i:ans){
  //   cout<<i<<endl;
  // }

  string digits = "245";
  vector<string> ans = letterCombinations(digits);
  for (auto i : ans)
  {
    cout << i << endl;
  }
}


