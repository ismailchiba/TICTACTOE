#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

char Board[3][3];
const char Player = 'X';
const char Computer = 'O';

void ResetBoard();
void ShowBoard();
void PlayerMove();
int CheckFreeSpace();
void ComputerMove();
void WhoWin(char);
char CheckWinner();

int main(void)
{

    char winner = ' ';

    ResetBoard();

    while (winner == ' ' && CheckFreeSpace() != 0)
    {
        ShowBoard();
        PlayerMove();
        ComputerMove();
        winner = CheckWinner();
        if (winner != ' ' || CheckFreeSpace() == 0)
        {
            break;
        }
        
    }
    ShowBoard();
    WhoWin(winner);

    return 0;
}

void ResetBoard()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Board[i][j] = ' ';
        }
    }
}

void ShowBoard()
{

    printf("\n  %c | %c | %c ", Board[0][0], Board[0][1], Board[0][2]);
    printf("\n ---|---|---");
    printf("\n  %c | %c | %c ", Board[1][0], Board[1][1], Board[1][2]);
    printf("\n ---|---|---");
    printf("\n  %c | %c | %c ", Board[2][0], Board[2][1], Board[2][2]);
    printf("\n ");
}

void PlayerMove()
{

    int x = 0, y = 0;

    printf("");
    printf("\nChoose a position : \n\n\tEnter row #(1-3) : ");
    scanf("%d", &x);
    printf("\n\tEnter colum #(1-3) : ");
    scanf("%d", &y);
    x--;
    y--;

    if (Board[x][y] != ' ')
    {
        printf("\n\t /!\\ \"Invalid move\" \n");
        PlayerMove();
    }
    else
    {
        Board[x][y] = Player;
    }
}

void ComputerMove()
{
    srand(time(0));
    int x;
    int y;

    if (CheckFreeSpace() > 0)
    {

        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (Board[x][y] != ' ');

        Board[x][y] = Computer;
    }
    else {
        WhoWin(' ');
            }
}

int CheckFreeSpace()
{

    int FreeSpace = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] != ' ')
            {
                FreeSpace--;
            };
        }
    }
    return FreeSpace;
}

void WhoWin(char winner)
{

    if (winner == 'X')
    {
        printf("You WIN!");
    }

    else if (winner == 'O')
    {
        printf("Game over you lOSE");
    }

    else if (winner == ' ')
    {
        printf(" Its a DRAW");
    }
    
       
}

char CheckWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2])
        {
            return Board[i][0];
        }
        if (Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i])
        {
            return Board[0][i];
        }
    }

    if (Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2])
    {
        return Board[0][0];
    }
    if (Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0])
    {
        return Board[0][2];
    }
    return ' ';
}