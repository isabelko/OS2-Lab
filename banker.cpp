// Isak Sabelko OS Programming Algorithm 2
#include <fstream>
#include <iostream>
using namespace std;

const int Processes = 5;
const int Resources = 3;
  
// Function to find the need of each process
void findNeed(int need[Processes][Resources], int maxm[Processes][Resources], int allot[Processes][Resources])
{
    for (int i = 0 ; i < Processes ; i++)
        for (int j = 0 ; j < Resources ; j++) 
            need[i][j] = maxm[i][j] - allot[i][j];
}
  
// Function to find the system is in safe state or not
bool safeOrNot(int processes[], int avail[], int maxm[][Resources], int allot[][Resources])
{
    int need[Processes][Resources];
    findNeed(need, maxm, allot);
    bool finish[Processes] = {0};
    int safeSeq[Processes];

    int work[Resources];
    for (int i = 0; i < Resources ; i++)
        work[i] = avail[i];

    int count = 0;
    while (count < Processes)
    {
        bool found = false;
        for (int p = 0; p < Processes; p++)
        {
            if (finish[p] == 0)
            {
                int j;
                for (j = 0; j < Resources; j++)
                    if (need[p][j] > work[j])
                        break;
                if (j == Resources)
                {
                    for (int k = 0 ; k < Resources; k++)
                        work[k] += allot[p][k];

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }

        if (found == false)
        {
            cout << "System is not in safe state";
            return false;
        }
    }

    cout << "The current system is in safe state.\nThe safe sequence is: ";
    for (int i = 0; i < Processes ; i++)
        cout << safeSeq[i] << " ";
  
    cout << "\n";
    return true;
}
  

int main()
{
    //open data file
    string filename("data.txt");

    FILE* input_file = fopen(filename.c_str(), "r");
    if(input_file == nullptr) {
        return EXIT_FAILURE;
    }

    char character = 0;

    int processes[] = {0, 1, 2, 3, 4};

    //enter data from .txt file
    int avail[3];
    character = getc(input_file);
    int i = character - '0';
    avail[0] = i;
    character = getc(input_file);
    i = character - '0';
    avail[1] = i;
    character = getc(input_file);
    i = character - '0';
    avail[2] = i;

    //check to make sure that the data was entered correctly
    for(int i = 0; i < 3; ++i)
    {
        cout << avail[i] << " ";
    }


    //enter data from .txt file
    int maxm[5][Resources];
    character = getc(input_file);
    i = character - '0';
    maxm[0][0] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[0][1] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[0][2] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[1][0] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[1][1] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[1][2] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[2][0] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[2][1] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[2][2] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[3][0] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[3][1] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[3][2] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[4][0] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[4][1] = i;
    character = getc(input_file);
    i = character - '0';
    maxm[4][2] = i;

    //check to make sure that the data was entered correctly
    cout << "\n";
    for(int i = 0; i < 5; ++i) { 
        for(int j = 0; j < 3; ++j)
        {
            cout << maxm[i][j] << " ";
        }
    }

    //enter data from .txt file
    int allot[5][Resources];
    character = getc(input_file);
    i = character - '0';
    allot[0][0] = i;
    character = getc(input_file);
    i = character - '0';
    allot[0][1] = i;
    character = getc(input_file);
    i = character - '0';
    allot[0][2] = i;
    character = getc(input_file);
    i = character - '0';
    allot[1][0] = i;
    character = getc(input_file);
    i = character - '0';
    allot[1][1] = i;
    character = getc(input_file);
    i = character - '0';
    allot[1][2] = i;
    character = getc(input_file);
    i = character - '0';
    allot[2][0] = i;
    character = getc(input_file);
    i = character - '0';
    allot[2][1] = i;
    character = getc(input_file);
    i = character - '0';
    allot[2][2] = i;
    character = getc(input_file);
    i = character - '0';
    allot[3][0] = i;
    character = getc(input_file);
    i = character - '0';
    allot[3][1] = i;
    character = getc(input_file);
    i = character - '0';
    allot[3][2] = i;
    character = getc(input_file);
    i = character - '0';
    allot[4][0] = i;
    character = getc(input_file);
    i = character - '0';
    allot[4][1] = i;
    character = getc(input_file);
    i = character - '0';
    allot[4][2] = i;

    //check to make sure that the data was entered correctly
    cout << "\n";
    for(int i = 0; i < 5; ++i) { 
        for(int j = 0; j < 3; ++j)
        {
            cout << allot[i][j] << " ";
        }
    }

    cout << endl;
    fclose(input_file);

    // See if system is safe or isn't
    safeOrNot(processes, avail, maxm, allot);

    return EXIT_SUCCESS;
    return 0;
}