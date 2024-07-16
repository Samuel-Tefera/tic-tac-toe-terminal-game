#include <iostream>
#include <string>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void sayWellcome();
void intializeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentGameBoard(string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
void getUserInput (bool xTurn, string gameBorad[ROWS][COLS]);
bool isgameBoardFull(int count);


void runGame();


int main ()
{
    runGame();

    return 0;
}                   

void intializeGameBoard(string gameBoard[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            gameBoard[i][j] = " ";
        }
    }
}
void printCurrentGameBoard(string gameBoard[ROWS][COLS])
{
    cout<<endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout<<gameBoard[i][j];
            if(j < 2)
            {
                cout<<" | ";
            }
        }
        cout<<endl;
        if(i < 2)
        {
            cout<<"- - - - - -"<<endl;
        }
    }
    cout<<endl<<endl;
}
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS])
{
    int row;
    int col;
    if(xTurn == true)
    {
        cout<<"It's X turn"<<endl;
        cout<<"Please enter rows and columns from 0, 1, or 2, separated by space."<<endl;

        cin>>row;
        cin.get();
        cin>>col;
        if (row < 3 && col < 3)
        {
            if(gameBoard[row][col] == " ")
            {
                gameBoard[row][col] = "X";
            }
            else
            {
                cout<<"You select already occupaied cell, Please choose another one"<<endl;
                getUserInput(xTurn, gameBoard);
            }
        }
        else
        {
            cout<<"You select cell out of range, Please choose in range"<<endl;
            getUserInput(xTurn, gameBoard);
        }
    }
    else if (xTurn == false)
    {
        cout<<"It's O turn"<<endl;
        cout<<"Please enter rows and columns from 0, 1, or 2, separated by space."<<endl;

        cin>>row;
        cin.get();
        cin>>col;
        if (row < 3 && col < 3)
        {
            if(gameBoard[row][col] == " ")
            {
                gameBoard[row][col] = "O";
            }
            else
            {
                cout<<"You select already occupaied cell, Please choose another one"<<endl;
                getUserInput(xTurn, gameBoard);
            }
        }
        else
        {
            cout<<"You select cell out of range, Please choose in range"<<endl;
            getUserInput(xTurn, gameBoard);
        }
    }
}
bool isGameBoardFull(int& count)
{
    if (count == 8)
    {
        return true;
    }
    else
    {
        return false;
    }
}
string getWinner(string gameboard[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        if (gameboard[i][0] != " " && gameboard[i][0] == gameboard[i][1] && gameboard[i][1] == gameboard[i][2])
        {
            return gameboard[i][0];
        }
    }
    for (int i = 0; i < COLS; i++)
    {
        if (gameboard[0][i] != " " && gameboard[0][i] == gameboard[1][i] && gameboard[1][i] == gameboard[2][i])
        {
            return gameboard[0][i];
        }
    }
    if(gameboard[0][0]=="X" && gameboard[1][1] =="X" && gameboard[2][2]=="X")
    {
        return "X";
    }
    if(gameboard[2][0]=="X" && gameboard[1][1] =="X" && gameboard[0][2]=="X")
    {
        return "X";
    }
    return "  ";

}
void runGame()
{
    string gameBoard[ROWS][COLS];
    bool xTurn;
    int count = 0;
    intializeGameBoard(gameBoard);
    while (count >= 0)
    {
        if(count % 2 == 0 )
        {
            xTurn = true;
        }
        else
        {
            xTurn = false;
        }
        printCurrentGameBoard(gameBoard);
        getUserInput(xTurn, gameBoard);
        string winner = getWinner(gameBoard);

        if (winner == "X")
        {
            printCurrentGameBoard(gameBoard);
            cout<<"The winner is 'X'"<<endl;
            break;
        }
        if (winner == "O")
        {
            printCurrentGameBoard(gameBoard);
            cout<<"The winner is  'O'"<<endl;
            break;
        }
        bool draw = isGameBoardFull(count);
        if (draw == true)
        {
            printCurrentGameBoard(gameBoard);
            cout<<"The game ends Draw, Cats Game."<<endl;
            break;
        }
        
        count++;
    }
   
}
