#include <iostream> 
#include <stdbool.h>
using namespace std;

int main(){
    int row = 3, col = 3;
    bool **matrix = new bool*[row];
    for(int i = 0; i < row; i++)
    {
        matrix[i] = new bool[col];
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> *(*(matrix + i) + j);
        }
    }

    int one, two;
    int count = 0;
    do
    {
        count = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == true)
                {
                    count++;
                }
            }
        }
        if (count == 0)
            break;
        cout << "Enter row and column:";
        cin >> one >> two;
        
        cout << "Total live enemies: " << count << endl;
        if (one >= row || one < 0 || two >= col || two < 0)
        {
            cout << "Invalid indexes" << endl;
            continue;
        }
        if(matrix[one][two] == true)
        {
            matrix[one][two] = false;
            cout << "Hit. Enemy destroyed.\n";
        }       
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cout << *(*(matrix + i) + j) << ' ';
            }
            cout << endl;
        }
    } while (count != 0);

    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}