#include <iostream>
#include <iomanip>

using namespace std;
void funSwap(int *ptr1, int *ptr2);
void calcRange(int *ptr1, int *ptr2 , float *range);
void calcMean(int *ptr1, int *ptr2,float *mean);
void calcNorm(int *ptr, int *norm);

int main(){
    int num1 = 100, num2 = 20, norm;
    float mean = 0, range = 0;
    cout << "Before Swap: " << num1 << " " << num2 << endl;
    funSwap(&num1, &num2);
    cout << "After Swap: " << num1 << " " << num2 << endl;
    calcRange(&num1, &num2, &range);
    calcMean(&num1, &num2, &mean);
    calcNorm(&num1, &norm);
    cout << "Nomalizing num1: " << norm << endl;
    calcNorm(&num2, &norm);
    cout << "Nomalizing num2: " << norm << endl;
    cout << "Mean: " << mean << endl;
    cout << "Range: " << range << endl;
    return 0;
}

void funSwap(int *ptr1, int *ptr2){

    int temp = *ptr2;
    *ptr2 = *ptr1;
    *ptr1 = temp;
}

void calcRange(int *ptr1, int *ptr2, float *range){
    int max  = 0, min = 1000;
    if(*ptr1 < *ptr2)
    {
        max = *ptr2;
    }
    else
    {
        max = *ptr1;
    }
    if(*ptr1 > *ptr2)
    {
        min = *ptr2;
    }
    else
    {
        min = *ptr1;
    }
    *range = max - min;
    
}
void calcMean(int *ptr1, int *ptr2, float *mean){

    *mean = float(*ptr1 + *ptr2) / 2;
}
void calcNorm(int *ptr, int *norm){
    *norm = *ptr/(*ptr);
}