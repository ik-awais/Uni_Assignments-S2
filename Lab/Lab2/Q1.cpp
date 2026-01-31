#include <iostream>
using namespace std;

int **ScholarCalc(int *ptr1, int *ptr2);

int main(){
    int marks1, marks2;
    cout << "Enter Marks of 2 Students: ";
    cin >> marks1 >> marks2;
    int **merit = ScholarCalc(&marks1, &marks2);
    if(merit != 0)
    {
        cout << "Selected student marks: " << **merit << endl;
        delete merit;
    }
    else
    {
        cout << "Both students have equal marks." << endl;
    }
    return 0;
}

int **ScholarCalc(int *ptr1, int *ptr2){
    int **result = new int*;
    if(*ptr1 > *ptr2)
    {
        *result = ptr1;
    }
    else if(*ptr2 > *ptr1)
    {
        *result = ptr2;
    }
    else
    {
        delete result;
        result = NULL;
    }
    return result;
}