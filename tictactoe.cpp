#include<iostream>
#include<vector>
using namespace std;
void displayBoard(vector<vector<char> >& board)
{
    for(int i=0;i<board.size();i++)
    {
        cout<<endl;
        cout<<"|";
        for(int j=0;j<board[i].size();j++)
        {
            cout<<board[i][j]<<"|";
        }
        cout<<endl;
        if(i==2)
        break;
        cout<<"-------";
    }
    cout<<endl;
}
bool checkWin(vector<vector<char> >& board,char player)
{
    for(int i=0;i<3;i++)
    {
        if((board[i][0]==player&&board[i][1]==player&&board[i][2]==player)||(board[0][i]==player&&board[1][i]==player&&board[2][i]==player))
        {
            return true;
        }
    }
    //check for diagonals
    if((board[0][0]==player&&board[1][1]==player&&board[2][2]==player)||(board[2][0]==player&&board[1][1]==player&&board[0][2]==player))
    {
        return true;
    }
    return false;
}
bool isBoardFull(vector<vector<char> >& board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            if(board[i][j]==' ')
            {
                return false;
            }
        }
    }
    return true;
}
char switchPlayer(char currentPlayer)
{
    if(currentPlayer=='X')
    {
        currentPlayer='O';
    }
    else
    {
        currentPlayer='X';
    }
    return currentPlayer;
}
int main()
{
    char pa='y';
    while(pa=='y'||pa=='Y')
    {
        vector<vector<char> >board(3,vector<char>(3,' '));
        char currentPlayer='X';
        while(true)
        {
            displayBoard(board);
            int row,col;
            cout<<"Player "<<currentPlayer<<" Enter the position for input(row and column):"<<endl;
            cin>>row;
            cin>>col;
            if(board[row][col]==' ')
            {
                board[row][col]=currentPlayer;
                if(checkWin(board,currentPlayer)==true)
                {
                    displayBoard(board);
                    cout<<"Player "<<currentPlayer<<" wins."<<endl;
                    break;
                }
                if(isBoardFull(board)==true)
                {
                    displayBoard(board);
                    cout<<"The Game is a Tie."<<endl;
                    break;
                }
                currentPlayer=switchPlayer(currentPlayer);
            }
            else
            {
                cout<<"The input row and col is already occupied, Invalid Input."<<endl;
            }
        }
        cout<<"Do you want to play again?(y/n)"<<endl;
        cin>>pa;
    }
    return 0;
}