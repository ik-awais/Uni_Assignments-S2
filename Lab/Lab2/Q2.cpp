#include <iostream>
#include <iomanip>
using namespace std;

int *calcTrainingScore(*arrSize);

int main(){
    int size;
    cout << "Enter number of teachers: ";
    cin >> size;
    int *scores[size];
    

    return 0;
}

int *calcTrainingScore(int *arrSize){
    
    int *arr = new int [*arrSize];
    cout << "Enter scores: ";
    for (int i = 0; i < *arrSize; i++)
        cin >> *arr;
        arr++;
    return arr-*arrSize;
}
