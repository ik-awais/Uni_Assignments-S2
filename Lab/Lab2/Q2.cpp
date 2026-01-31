// Write a C++ program in which the user first enters the number of teachers. The program
// should include a function calculate_training_score() that dynamically allocates an array
// to store the scores, reads the scores from the user, and returns a pointer to the array back
// to the main function. In the main function, a pointer array should be declared to store the
// addresses of the individual scores.
// // Another function, display_score(),should be used to display the scores by dereferencing
// the pointers.
// Note: Finally, all dynamically allocated memory must be properly deallocated before
// the program ends.

#include <iostream>
#include <iomanip>
using namespace std;

int *CalScore(int size);
void DispScore(int *score, int size);

int main(){
    int num, *arrScore;
    cout << "Enter number of Teachers in training: ";
    cin >> num;
    arrScore = CalScore(num);
    DispScore(arrScore, num);
    delete[] arrScore;
    cout << "Memory Deallocated Successfully." << endl;
    return 0;
}

int *CalScore(int size){
    int *score = new int[size], *temp = score;
    for(int i = 0; i < size; i++)
    {
        cout << "Enter training score for Teacher ";
        cout << i + 1 << ": ";
        cin >> *score;
        score++;
    }
    return temp;
}

void DispScore(int *score, int size){
    cout << "Training scores: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Teacher" << i + 1 << ": ";
        cout << *score << endl;
        score++; 
    }
}