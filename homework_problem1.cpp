#include<iostream>
#include<cmath>
using namespace std;

const int MAX_ARRAY_VALUE = 3;
const int SECOND_MAX_ARRAY_VALUE = 100;


int weekDay(int day, int month, int year);
int decimalToUrsaMajor_first(int decimal);

//add documentation!

int main ()
{
    string input1;
    string inputUrsaMajor[MAX_ARRAY_VALUE];
    int k = 0;
    string temporaryToArray;
    cin >> input1;
    int secondInput;
    cin >> secondInput;
    int date_final = 0;
    int result[MAX_ARRAY_VALUE];
    int tempForPower;
    int tempForFinalArr;
    int weekDayCheck;


    for(int i = 0;i < input1.size();i++)
    {
        if(input1[i] == '.')
        {
            inputUrsaMajor[k] = temporaryToArray;
            temporaryToArray.clear();
            k++;
        }
        else if ((i+1) == input1.size())
        {
            temporaryToArray += input1[i];
            inputUrsaMajor[k] = temporaryToArray;
            temporaryToArray.clear();
            k++;
        }
        else{
            temporaryToArray += input1[i];
        }
     }

    for(int i = 0 ; i < MAX_ARRAY_VALUE; i++)
    {
        if(inputUrsaMajor[i].length() == 1)
        {
            for (char c : inputUrsaMajor[i])
            {
            tempForFinalArr = (int)c -96;
            }
            result[i] = tempForFinalArr;

        }
        if(inputUrsaMajor[i].length() > 1)
            {
            tempForPower = inputUrsaMajor[i].length() - 1;
            for(char c: inputUrsaMajor[i])
            {
                if(c >= 'a' && c <= 'm')
                {
            date_final += (((int)c -96) * pow(14, tempForPower));
            tempForPower--;
                }
                else if(c == 0)
                {
                    date_final += ((0 * pow(14, tempForPower)));
                    tempForPower--;
                }
            }
            result[i] = date_final;
            date_final = 0;
        }

    }
    weekDayCheck = weekDay(result[0], result[1], result[2]);
    if(weekDayCheck == 0 || weekDayCheck == 6) {
        cout << "Yes, " << result[0] <<"."<< result[1] << "."<< result[2]<<" isn't a working day." << endl;
    }
    else {
        cout << "No, " << result[0] <<"."<< result[1] << "."<< result[2]<<" is a working day." << endl;
    }
    decimalToUrsaMajor_first(secondInput);

    return 0;
}


int weekDay(int day, int month, int year)
{
    int MonthCheck[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    if(month < 3)
    {
        year = year - 1;
    }
    else
    {
      year = year - 0;
    }
    return(year + year / 4 - year/100 + year/400 + MonthCheck[month - 1] + day)%7;

}



int decimalToUrsaMajor_first(int decimal)
{
    long int secondArray[SECOND_MAX_ARRAY_VALUE];
    long c;
    int n = 0;
    static int counter = 0;
    if(decimal == 0)
    {
        cout << 0;
    }
    while(decimal > 0)
    {
        c = decimal % 14;
        decimal /= 14;
        counter ++;
        secondArray[n] = c;
        n++;
    }
    for(int i = n-1; i >= 0 ;i--)
    {
        switch(secondArray[i]){
            case 0:
                cout << "0";
                break;
            case 1:
                cout << 'a';
                break;
            case 2:
                cout << 'b';
                break;
            case 3:
                cout << 'c';
                break;
            case 4:
                cout << 'd';
                break;
            case 5:
                cout << 'e';
                break;
            case 6:
                cout << 'f';
                break;
            case 7:
                cout << 'g';
                break;
            case 8:
                cout << 'h';
                break;
            case 9:
                cout << 'i';
                break;
            case 10:
                cout << 'j';
                break;
            case 11:
                cout << 'k';
                break;
            case 12:
                cout << 'l';
                break;
            case 13:
                cout << 'm';
                break;
            case 14:
                cout << 'n';
                break;
        }
    }
}
