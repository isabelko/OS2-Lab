//Isak Sabelko OS Programming Algorithm 2
#include <fstream>
#include <iostream>
using namespace std;

const int Processes = 5;
const int Resources = 3;
  
// Function to find the need of each process
void findNeed(int need[Processes][Resources], int maximum[Processes][Resources], int allocation[Processes][Resources])
{
    for (int i = 0 ; i < Processes ; i++)
        for (int j = 0 ; j < Resources ; j++) 
            need[i][j] = maximum[i][j] - allocation[i][j];
}
  
// Function to find the system is in safe state or not
bool safeOrNot(int processes[], int available[], int maximum[][Resources], int allocation[][Resources])
{
    int need[Processes][Resources];
    findNeed(need, maximum, allocation);
    bool finish[Processes] = {0};
    int safeSequence[Processes];

    int work[Resources];
    for (int i = 0; i < Resources ; i++)
        work[i] = available[i];

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
                        work[k] += allocation[p][k];

                    safeSequence[count++] = p;
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
        cout << safeSequence[i] << " ";
  
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
    int available[3];
    character = getc(input_file);
    int i = character - '0';
    available[0] = i;
    character = getc(input_file);
    i = character - '0';
    available[1] = i;
    character = getc(input_file);
    i = character - '0';
    available[2] = i;

    //check to make sure that the data was entered correctly
    for(int i = 0; i < 3; ++i)
    {
        cout << available[i] << " ";
    }


    //enter data from .txt file
    int maximum[5][Resources];
    character = getc(input_file);
    i = character - '0';
    maximum[0][0] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[0][1] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[0][2] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[1][0] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[1][1] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[1][2] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[2][0] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[2][1] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[2][2] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[3][0] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[3][1] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[3][2] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[4][0] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[4][1] = i;
    character = getc(input_file);
    i = character - '0';
    maximum[4][2] = i;

    //check to make sure that the data was entered correctly
    cout << "\n";
    for(int i = 0; i < 5; ++i) { 
        for(int j = 0; j < 3; ++j)
        {
            cout << maximum[i][j] << " ";
        }
    }

    //enter data from .txt file
    int allocation[5][Resources];
    character = getc(input_file);
    i = character - '0';
    allocation[0][0] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[0][1] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[0][2] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[1][0] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[1][1] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[1][2] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[2][0] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[2][1] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[2][2] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[3][0] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[3][1] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[3][2] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[4][0] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[4][1] = i;
    character = getc(input_file);
    i = character - '0';
    allocation[4][2] = i;

    //check to make sure that the data was entered correctly
    cout << "\n";
    for(int i = 0; i < 5; ++i) { 
        for(int j = 0; j < 3; ++j)
        {
            cout << allocation[i][j] << " ";
        }
    }

    cout << endl;
    fclose(input_file);

    // See if system is safe or isn't
    safeOrNot(processes, available, maximum, allocation);

    return EXIT_SUCCESS;
    return 0;
}