#include <stdlib.h>
#include <stdio.h>

void setMatrix(int arr[][4]);
void display(int arr[][4]);
int Win(int arr[][4]);
int shiftRight(int arr[][4], int move);
int shiftLeft(int arr[][4], int move);
int shiftUp(int arr[][4], int move);
int shiftDown(int arr[][4], int move);

int main()
{
    int arr[4][4], move = 400, key;
    int winArr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};

    printf("\n          RULE OF THIS GAME         \n");
    printf("\n1.You can move only 1 step at a time by arrow key\n");
    printf("Move UP    : by Up arrow key\n");
    printf("Move Down  : by Down arrow key\n");
    printf("Move Left  : by Left arrow key\n");
    printf("Move Right : by Right arrow key\n");
    printf("\n2.You can move number at empty position only\n");
    printf("3.For each valid move : your total number of move will decreased by 1\n");
    printf("4.Wining situation : number in a 4*4 matrix should be in order from 1 to 15\n");

    printf("\n      Wining situation:\n");
    display(winArr);

    printf("\n5.You can exit the game at any time by pressing 'e'\nSo Try to win in minimum no of move\n");
    printf("\n    Happy gaming, Good Luck\n");

    printf("Enter any key to start......\n\n");
    getch();

    setMatrix(arr);
    while (move)
    {
        printf("\nMove Remaining: %d", move);
        display(arr);

        if (Win(arr))
        {
            printf("\nCongratulation you win in %d moves", 400 - move);
            printf("\nPress any key to exit...");
            getch();
            exit(0);
        }

        key = getch();

        switch (key)
        {

        case 72:
            move = shiftUp(arr, move);
            break;
        case 80:
            move = shiftDown(arr, move);
            break;
        case 75:
            move = shiftLeft(arr, move);
            break;
        case 77:
            move = shiftRight(arr, move);
            break;
        case 101:
            exit(0);
            break;
        default:
            move++;
        }
        system("cls");
        move--;
    }


    if (Win(arr))
    {
        printf("\nCongratulation you win in %d moves", 400 - move);
        printf("\nPress any key to exit...");
        move+=1;
        getch();
    }

    if (move == 0)
        printf("\nGame Over..\n");

    return 0;
}

int shiftRight(int A[][4], int move)
{
    int i, j, temp, Found = 0;

    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            if (A[i][j] == 0)
            {
                Found = 1;
                break;
            }
        }
        if (Found)
            break;
    }
    if (j == 0)
        move += 1;
    else
    {
        temp = A[i][j];
        A[i][j] = A[i][j - 1];
        A[i][j - 1] = temp;
    }
    return move;
}

int shiftLeft(int A[][4], int move)
{
    int i, j, temp, Found = 0;

    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            if (A[i][j] == 0)
            {
                Found = 1;
                break;
            }
        }
        if (Found)
            break;
    }
    if (j == 3)
        move += 1;
    else
    {
        temp = A[i][j];
        A[i][j] = A[i][j + 1];
        A[i][j + 1] = temp;
    }
    return move;
}

int shiftUp(int A[][4], int move)
{
    int i, j, temp, Found = 0;

    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            if (A[i][j] == 0)
            {
                Found = 1;
                break;
            }
        }
        if (Found)
            break;
    }
    if (i == 3)
        move += 1;
    else
    {
        temp = A[i][j];
        A[i][j] = A[i + 1][j];
        A[i + 1][j] = temp;
    }
    return move;
}

int shiftDown(int arr[][4], int move)
{
    int i, j, temp, Found = 0;

    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            if (arr[i][j] == 0)
            {
                Found = 1;
                break;
            }
        }
        if (Found)
            break;
    }
    if (i == 0)
        move += 1;
    else
    {
        temp = arr[i][j];
        arr[i][j] = arr[i - 1][j];
        arr[i - 1][j] = temp;
    }
    return move;
}

int Win(int arr[][4])
{

    int i, j, check = 0;

    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 2; j++)
        {

            if (i <= 2 && arr[i][j + 1] < arr[i][j])
                return 0;

            if (i == 3 && arr[i][j + 1] > arr[i][j])
                check = 1;
            else if (i == 3 && (j + 1) == 3)
                check = 1;
            else if (i == 3)
            {
                check = 0;
                break;
            }
        }

        if (check == 1)
            return 1;
        else
            return 0;
    }

    return check;
}

void display(int arr[][4])
{
    int i, j;
    printf("\n-------------------------\n");
    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            if (j == 0)
                printf("|");

            if (arr[i][j] != 0)
                printf(" %-2d | ", arr[i][j]);
            else
                printf("    | ");
        }
        printf("\n-------------------------\n");
    }
}

void setMatrix(int arr[][4])
{
    int A[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int i, j, maxInd = 14, index;
    srand(time(NULL));

    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            if (maxInd >= 0)
            {
                index = rand() % (maxInd + 1);
                arr[i][j] = A[index];
                A[index] = A[maxInd];
                maxInd--;
            }
            else
                arr[i][j] = 0;
        }
    }
}
