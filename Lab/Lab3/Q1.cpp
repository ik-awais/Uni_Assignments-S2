#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

int main(){
    int dept = 3, campus = 3;
    char **Campus = new char*[3];
    for(int i = 0; i < 3; i++)
    {
        Campus[i] = new char[10];
    }
    
    strcpy(Campus[0], "Peshawar");
    strcpy(Campus[1], "Islamabad");
    strcpy(Campus[2], "Lahore");
    int **twoDarr = new int*[campus];
    for(int i = 0; i < dept; i++)
    {
        *(twoDarr + i) = new int[dept];
    }
    cout << "Enter number of Students in each department: ";
    for(int i = 0; i < dept; i++)
    {
        for(int j = 0; j < dept; j++)
        {
            cin >> *(*(twoDarr + i)+j);
        }
    }
    cout << setw(10) <<"\t\tCE \tAI \tSE \n";
    for(int i = 0; i < dept; i++)
    {
        cout << setw(10) << *(Campus + i);
        for(int j = 0; j < dept; j++)
        {
            cout << setw(8) << *(*(twoDarr + i)+j) << ' ';
        }
        cout << endl;
    }
    for(int i = 0; i < dept; i++)
    {
        delete[] *(twoDarr + i);
    }
    delete[] twoDarr, Campus;
    return 0;
}