#include <iostream>
#include <iomanip>

using namespace std;
void calcTotal(int *ptr1, int *ptr2, int *ptr3, int *total);
void calcPercent(int *ptr1, int *ptr2, int *ptr3, int *total, float *percent);

int main(){
    int subj1, subj2, subj3, total = 0;
    float percent = 0;
    cout << "Enter marks of 3 Subjects: ";
    cin >> subj1 >> subj2 >> subj3;
    cout << subj1 << " " << subj2 << " " << subj3 << endl;
    calcTotal(&subj1, &subj2, &subj3, &total);
    calcPercent(&subj1, &subj2, &subj3, &total, &percent);
    cout << "Total: " << total << " / 300" << endl;
    cout << "Percentage: " << percent << "%" << endl;

    return 0;
}

void calcTotal(int *ptr1, int *ptr2, int *ptr3, int *total){
    *total = *ptr1+*ptr2+*ptr3;
}
void calcPercent(int *ptr1, int *ptr2, int *ptr3, int *total, float *percent){
    *percent = float((*total*100)/300);
}