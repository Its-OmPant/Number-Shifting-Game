#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//          Macro Declarations
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

//          Function Declarations

void rules();                       
void RandNum(int a[][4], int, int);
void startGame(int a[][4], int, int, int, char name[]);
void PrintMatrix(int a[][4], int, int, char name[], int); 
int compare(int a[4][4], int);
int MoveUp(int a[][4], int row, int column, int move);
int MoveDown(int a[][4], int row, int column, int move);
int MoveRight(int a[][4], int row, int column, int move);
int MoveLeft(int a[][4], int row, int column, int move);




int main()
{

    while (1)
    {

        int matrix[4][4] = {};
        int moves = 60, x = 0;
        char name[25], c;

        printf("\n Welcome to The Number Shifting game. To Play the game -");
        printf("\n\nPlease enter your name : ");
        gets(name);
        system("cls");

        // // Printing Intro and Game Rules
        rules();
        printf("\nEnter any Key to Start the game....\n");
        getchar();
        system("cls");


        char key;
        system("cls");
        RandNum(matrix, 4, 4);
        startGame(matrix, 4, 4, moves, name);

        printf("\t\tPlay Again: Press Y\t\t");
        printf("To Exit :Press Any Key\n ");

        switch (c = getch())
        {
        case 'Y':
            x = 0;
            break;
        case 'y':
            x = 0;
            break;
        default:
            x = 1;
            break;
        }

        if (x)
        {
            break;
        }
    }

    return 0;
}

//  Function definitions

void rules()
{
    printf("\033[0;32m");
    printf("\n\t\t\t\t NUMBER SHIFTING GAME BY OM PANT\n\n");
    printf("\033[0m");
    printf("\033[0;31m");
    printf("\t\t   ===============  Rules Of This Game  ===============\t\n");
    printf("\n1) You can move only 1 step at a time by arrow key\n\n");
    printf("\033[0m");

    printf("\tMOVE UP   :  by Up arrow key ");
    printf(" %c\n", 24);
    printf("\tMOVE DOWN :  by down arrow key ");
    printf(" %c\n", 25);
    printf("\tMOVE LEFT :  by left arrow key ");
    printf(" <-\n");
    printf("\tMOVE RIGHT:  by right arrow key ");
    printf(" %c\n", 26);

    printf("\033[0;31m");
    printf("\n2) You can move number at empty position only.\n");
    printf("\n3) For each valid move : Your total number of move will be decreased by 1.\n");
    printf("\n4) Winning Situation : number in a 4X4 Matrix should be in order from 1 to 15.\n\n");
    printf("\033[0m");

    printf("\033[0;36m");
    printf("\t\t\t WINNING SITUATION \n\n");
    printf("\033[0m");

    printf("\033[0;33m");
    printf("\t\t\t------------------\n");
    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        printf("\t\t\t|");
        for (int j = 0; j < 4; j++)
        {
            if (count == 16)
                printf("%3c ", 32);
            else
                printf("%3d ", count++);
        }
        printf("|");
        printf("\n");
    }
    printf("\t\t\t------------------\n");
    printf("\033[0m");

    printf("\033[0;31m");
    printf("\n\n5) You can exit the game at any time by pressing 'E' or 'e'.\n\t Try to win in minimum number of move \n");
    printf("\033[0m");
}

void RandNum(int matrix[][4], int rows, int columns)
{
    int i, j, count = 1, x = 0, y = 0;
    matrix[3][3] = 0;
    srand(time(NULL));

    while (count < 16)
    {

        int randNum = rand() % 15 + 1;
        int flag = 1;

        // Checking duplicate
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (matrix[i][j] == randNum)
                {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag)
        {
            matrix[x][y] = randNum;
            y++;
            if (y > 3)
            {
                x++;
                y = 0;
            }
            count++;
        }
    }
}

void startGame(int a[][4], int rows, int columns, int totalMoves, char name[])
{

    PrintMatrix(a, 4, 4, name, totalMoves);

    // detecting arrow keys and e in infinite loop
    int c, flag = 0, x;
    while (1)
    {
        c = getch();
        if (c == 0)
            c = getch();
        switch (c)
        {
        case 69:
            flag = 1;
            break;
        case 101:
            flag = 1;
            break;

        case KEY_UP:
            totalMoves = MoveUp(a, 4, 4, totalMoves);
            x = compare(a, totalMoves);
            if (x == 1)
            {   
                printf("\033[0;31m");
                printf("\n\n\t\t\t YOU WON\n\n");
                printf("\033[0m");
                flag = 1;
            }

            else if (x == 0)
            {
                printf("\033[0;31m");
                printf("\n\n\t\t\t You Lose\n\n");
                printf("\033[0m");
                flag = 1;
            }
            else
            {
                system("cls");
                PrintMatrix(a, 4, 4, name, totalMoves);
            }
            break;

        case KEY_DOWN:
            totalMoves = MoveDown(a, 4, 4, totalMoves);
            x = compare(a, totalMoves);
            if (x == 1)
            {   
                printf("\033[0;31m");
                printf("\n\n\t\t\t YOU WON\n\n");
                printf("\033[0m");
                flag = 1;
            }
            
            else if (x == 0)
            {
                printf("\033[0;31m");
                printf("\n\n\t\t\t You Lose\n\n");
                printf("\033[0m");
                flag = 1;
            }
            else
            {
                system("cls");
                PrintMatrix(a, 4, 4, name, totalMoves);
            }
            break;

        case KEY_LEFT:
            totalMoves = MoveLeft(a, 4, 4, totalMoves);
            x = compare(a, totalMoves);
            if (x == 1)
            {   
                printf("\033[0;31m");
                printf("\n\n\t\t\t YOU WON\n\n");
                printf("\033[0m");
                flag = 1;
            }
            
            else if (x == 0)
            {
                printf("\033[0;31m");
                printf("\n\n\t\t\t You Lose\n\n");
                printf("\033[0m");
                flag = 1;
            }
            else
            {
                system("cls");
                PrintMatrix(a, 4, 4, name, totalMoves);
            }
            break;
        case KEY_RIGHT:
            totalMoves = MoveRight(a, 4, 4, totalMoves);
            x = compare(a, totalMoves);
            if (x == 1)
            {   
                printf("\033[0;31m");
                printf("\n\n\t\t\t YOU WON\n\n");
                printf("\033[0m");
                flag = 1;
            }
            
            else if (x == 0)
            {
                printf("\033[0;31m");
                printf("\n\n\t\t\t You Lose\n\n");
                printf("\033[0m");
                flag = 1;
            }
            else
            {
                system("cls");
                PrintMatrix(a, 4, 4, name, totalMoves);
            }
            break;
        }
        if (flag)
            break;
    }
}

void PrintMatrix(int a[][4], int row, int column, char name[], int totalMoves)
{

    printf("\033[0;36m");
    printf("\n\n\t\tPlayer Name : ");
    printf("%s\t", name);
    printf("Moves remaining: %d\n\n\n", totalMoves);

    printf("\033[0m");

    printf("\033[0;33m");
    printf("\t\t\t---------------------\n");

    for (int i = 0; i < row; i++)
    {
        printf("\t\t\t|");
        for (int j = 0; j < column; j++)
        {
            if (a[i][j] == 0)
            {
                printf("%3c |", 32);
                continue;
            }
            printf("%3d |", a[i][j]);
        }
        // printf("|");
        printf("\n");
    }
    printf("\t\t\t---------------------\n\n");
    printf("\033[0m");
}

int compare(int a[4][4], int moves)
{
    int b[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0}, i, j, f = 1;

    if (moves >= 0)
    {
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (a[i][j] != b[i][j])
                {
                    f = 0;
                    break;
                }
            }
        }
        if (f)
        {
            return f;
        }
    }
    else
        return 0;
}


int MoveUp(int a[][4], int row, int column, int move)
{
    int i, j, temp, flag = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (a[i][j] == 0 && i != 3)
            {

                temp = a[i][j];
                a[i][j] = a[i + 1][j];
                a[i + 1][j] = temp;
                move--;
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    return move;
}



int MoveDown(int a[][4], int row, int column, int move)
{
    int i, j, temp;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (a[i][j] == 0 && i != 0)
            {
                temp = a[i][j];
                a[i][j] = a[i - 1][j];
                a[i - 1][j] = temp;
                move--;
            }
        }
    }
    return move;
}

int MoveRight(int a[][4], int row, int column, int move)
{
    int i, j, temp, flag = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (a[i][j] == 0 && j != 0)
            {
                temp = a[i][j];
                a[i][j] = a[i][j - 1];
                a[i][j - 1] = temp;
                move--;
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    return move;
}

int MoveLeft(int a[][4], int row, int column, int move)
{
    int i, j, temp, flag = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (a[i][j] == 0 && j != 3)
            {
                temp = a[i][j];
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = temp;
                move--;
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    return move;
}