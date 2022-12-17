#include<iostream>

using namespace std;

void elementGroup(string groupArr[],int groupArrSize);
void elementSort(string sortArr[],int coutnerArr[],int sortArrSize);

int main ()
{
    int n;
    cin >> n;
    string mainArray[n];



    for(int i = 0; i < n; i++)
    {
        cin >> mainArray[i];
    }

    elementGroup(mainArray,n);
return 0;
}

void elementGroup(string groupArr[],int groupArrSize)
{
    int outputCoutner[groupArrSize];
    int counter = 1;
    for(int i = 0 ; i < groupArrSize; i++)
    {

        for(int k = i+1; k < groupArrSize;k++)
        {
            if(groupArr[i] == groupArr[k])
            {
                counter++;
                groupArr[k] = "delete";
            }
            else if (groupArr[i] != groupArr[k])
            {
                continue;
            }
        }
        outputCoutner[i] = counter;
        counter = 1;
    }
    for(int i = 0; i < groupArrSize; i++)
    {
        if(groupArr[i] == "delete")
        {
           groupArr[i].clear();
           outputCoutner[i] = 0;
        }
    }

    elementSort(groupArr, outputCoutner, groupArrSize);

    for(int i = 0; i < groupArrSize; i++)
    {
        if(outputCoutner[i] != 0)
        {
          cout << outputCoutner[i] << " - " << groupArr[i] << endl;
        }
    }
}

void elementSort(string sortArr[],int counterArr[],int sortArrSize)
{
    int j = 0;
    for(int i = 0; i < sortArrSize; i++ )
    {
        for(int k = i+1; k < sortArrSize; k++)
        {
            while(sortArr[i][j] == sortArr[k][j])
            {
                j++;
            }
            if(sortArr[i][j] > sortArr[k][j] && counterArr != 0)
            {
                swap(sortArr[i], sortArr[k]);
                swap(counterArr[i], counterArr[k]);
            }
            j = 0;
        }
    }
}
