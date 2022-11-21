//Isak Sabelko OS Programming Algorithm 2
#include <fstream>
#include <iostream>
using namespace std;

const int Processes = 5;
const int Resources = 3;
  
// Function for need
void findNeed(int needed[Processes][Resources], int maximum[Processes][Resources], int allocation[Processes][Resources])
{
    for (int x = 0 ; x < Processes ; x++)
        for (int y = 0 ; y < Resources ; y++) 
            needed[x][y] = maximum[x][y] - allocation[x][y];
}
  
// Funtion for safe or not
bool safeOrNot(int processes[], int available[], int maximum[][Resources], int allocation[][Resources])
{
    int need[Processes][Resources];
    findNeed(need, maximum, allocation);
    
    int safeSequence[Processes];
    bool completed[Processes] = {0};

    int copyR[Resources];
    for (int i = 0; i < Resources ; i++)
        copyR[i] = available[i];

    int counter;
    counter = 0;

    while (counter < Processes)
    {
        bool spotted = false;
        for (int p = 0; p < Processes; p++)
        {
            if (completed[p] == 0)
            {
                int q;
                for (q = 0; q < Resources; q++)
                    if (need[p][q] > copyR[q])
                        break;
                if (q == Resources)
                {
                    for (int r = 0 ; r < Resources; r++)
                        copyR[r] += allocation[p][r];

                    safeSequence[counter++] = p;
                    completed[p] = 1;
                    spotted = true;
                }
            }
        }
        if (spotted == false)
        {
            cout << "The system isn't in a safe state :(";
            return false;
        }
    }

    cout << "System is in a safe state! :)\nSafe sequence = ";
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

    cout << "making sure data entered in correctly from table:\nAvailable column: ";
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
    cout << "\nMaximum column: ";
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
    cout << "\nAllocation column: ";
    for(int i = 0; i < 5; ++i) { 
        for(int j = 0; j < 3; ++j)
        {
            cout << allocation[i][j] << " ";
        }
    }

    cout << endl;
    fclose(input_file);

    // check if system is safe or isn't and find the safe sequence if safe
    safeOrNot(processes, available, maximum, allocation);

    return EXIT_SUCCESS;
    return 0;
}