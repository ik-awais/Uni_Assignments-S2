// Use Double Pointer to solve it:
// The Education Department selects one student for a merit-based scholarship from two
// candidates. Their marks are stored in separate integer variables in main, and a pointer is
// used to track the selected student. Write a C++ program with one function that takes
// the addresses of both students’ marks and a double pointer to the selection pointer.
// The function should compare the marks and update the pointer to the higher score.
// Note: If both marks are equal, set the pointer to NULL. After returning to main, display
// the selected marks or a message indicating that both students have equal marks.

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