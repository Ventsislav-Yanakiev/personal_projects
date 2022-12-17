#include<iostream>

const int MAX_ARRAY_VALUE = 9;

using namespace std;

int fielSizeCheck(int fieldSizeInput);
void fillArrayBlank(char fillArr[MAX_ARRAY_VALUE][MAX_ARRAY_VALUE],int fillArrSize);
void userMainInput();
bool freeSpaceCheck(char freeSpaceArr[MAX_ARRAY_VALUE][MAX_ARRAY_VALUE],int freeSpaceSize);
bool victoryCheck(char victoryArr[MAX_ARRAY_VALUE][MAX_ARRAY_VALUE],int victoryArrSize); // not working

int main ()
{
    char victoryChar;
    int N, posX_X, posY_X, posX_O, posY_O;
    bool victoryX = false, victoryO = false, draw = false, spotTakenCheck = false;
    char playFieldArr[MAX_ARRAY_VALUE][MAX_ARRAY_VALUE];
    cout << "Please enter field size(number should be larger than 3 and smaller than 9): ";
    cin >> N;

    N = fielSizeCheck(N);

    fillArrayBlank(playFieldArr, N);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << playFieldArr[i][j] << " ";
        }
        cout << endl;
    }

    while(!freeSpaceCheck(playFieldArr, N) && !victoryCheck(playFieldArr, N))
     {

        freeSpaceCheck(playFieldArr, N);
        victoryCheck(playFieldArr, N);

        if(freeSpaceCheck(playFieldArr, N))
        {
            break;
        }

        cout << "Player X turn!" << endl;
        cout << "Enter position on row: ";
        cin >> posX_X;
        cout << "Enter position on column: ";
        cin >> posY_X;

        if(playFieldArr[posY_X][posX_X] != '*')
        {
            spotTakenCheck = true;
        }
        while(spotTakenCheck)
        {
            cout << "This spot is taken! Try another one!" << endl;
            cout << "Enter position on row: ";
            cin >> posX_X;
            cout << "Enter position on column: ";
            cin >> posY_X;
            if(playFieldArr[posY_X][posX_X] == '*')
            {
                spotTakenCheck = false;
            }
        }

        victoryChar = 'X';

        playFieldArr[posY_X][posX_X] = 'X';

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                {
                cout << playFieldArr[i][j] << " ";
                }
            cout << endl;
        }

        if(victoryCheck(playFieldArr, N))
        {
            break;
        }

        if(freeSpaceCheck(playFieldArr, N))
        {
            break;
        }

        cout << "Player O turn!" << endl;
        cout << "Enter position on row: ";
        cin >> posX_O;
        cout << "Enter position on column: ";
        cin >> posY_O;

        if(playFieldArr[posY_O][posX_O] != '*')
        {
            spotTakenCheck = true;
        }
        while(spotTakenCheck)
        {
            cout << "This spot is taken! Try another one!" << endl;
            cout << "Enter position on row: ";
            cin >> posX_O;
            cout << "Enter position on column: ";
            cin >> posY_O;
            if(playFieldArr[posY_O][posX_O] == '*')
            {
                spotTakenCheck = false;
            }
        }

        victoryChar = 'O';

        if(victoryCheck(playFieldArr, N))
        {
            break;
        }

        playFieldArr[posY_O][posX_O] = 'O';

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                {
                cout << playFieldArr[i][j] << " ";
                }
            cout << endl;
        }
    }
    if(freeSpaceCheck(playFieldArr, N))
    {
        cout << "It's a draw!";
    }
    else{
        cout << "Player " << victoryChar << " has won!" << endl;
    }
return 0;
}

int fielSizeCheck(int fieldSizeInput)
{
    while(fieldSizeInput < 3 || fieldSizeInput > 9)
    {
        cout << "Incorrect input for N, please enter a number between 3 and 9: ";
        cin >> fieldSizeInput;
    }
    return fieldSizeInput;
}

void fillArrayBlank(char fillArr[MAX_ARRAY_VALUE][MAX_ARRAY_VALUE],int fillArrSize)
{
    for(int i = 0; i < fillArrSize; i++)
    {
        for(int j = 0; j < fillArrSize; j++)
        {
            fillArr[i][j] = '*';
        }
    }
}

bool freeSpaceCheck(char freeSpaceArr[MAX_ARRAY_VALUE][MAX_ARRAY_VALUE],int freeSpaceSize)
{
    bool endGameCheck;
     for(int i = 0; i < freeSpaceSize; i++)
    {
        for(int j = 0; j < freeSpaceSize; j++)
        {
            endGameCheck = true;
            if( freeSpaceArr[i][j] == '*')
                {
                endGameCheck = false;
                break;
                }
        }
        if(endGameCheck == false)
        {
            break;
        }
    }
    return endGameCheck;
}

bool victoryCheck(char victoryArr[MAX_ARRAY_VALUE][MAX_ARRAY_VALUE],int victoryArrSize)
{
    int secondDiagonalCounter = victoryArrSize -1;

    bool horizontalCheck = false;
    for(int i = 0; i < victoryArrSize; i++)
    {
        for(int j = 0; j < victoryArrSize-1; j++)
            {
                if(victoryArr[i][j] == victoryArr[i][j+1] && victoryArr[i][j] != '*')
                {
                    horizontalCheck = true;
                }
                else
                {
                    horizontalCheck = false;
                    break;
                }
            }
            if(horizontalCheck)
            {
                break;
            }
    }

    bool verticalCheck = false;
    for(int j = 0; j < victoryArrSize; j++)
    {
        for(int i = 0; i < victoryArrSize - 1; i++)
            {
                if(victoryArr[i][j] == victoryArr[i+1][j] && victoryArr[i][j] != '*')
                {
                    verticalCheck = true;
                }
                else
                {
                    verticalCheck = false;
                    break;
                }
            }
            if(verticalCheck == true)
            {
                break;
            }
    }

    bool mainDiagonalCheck;
    for(int i = 0; i < victoryArrSize - 1; i++)
    {
        if(victoryArr[i][i] == victoryArr[i+1][i+1] && victoryArr[i][i] != '*')
        {
            mainDiagonalCheck = true;
        }
        else{
            mainDiagonalCheck = false;
            break;
        }

    }

    bool secondaryDiagonalCheck;
     for(int i = 0; i < victoryArrSize - 1; i++)
    {
           if(victoryArr[i][secondDiagonalCounter] == victoryArr [i+1][secondDiagonalCounter-1] && victoryArr[i][secondDiagonalCounter] != '*')
            {
                secondaryDiagonalCheck = true;
            }
            else{
                secondaryDiagonalCheck = false;
                break;
            }
            secondDiagonalCounter--;
    }

    if(horizontalCheck || verticalCheck || mainDiagonalCheck || secondaryDiagonalCheck)
    {
        return true;
    }
    else{
        return false;
    }
}
