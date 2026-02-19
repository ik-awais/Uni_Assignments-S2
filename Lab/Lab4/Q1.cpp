#include <iostream>
#include <iomanip>
using namespace std;

struct Car{
    string Model;
    int  year;
    float price;
};

int main(){
    int size;
    cout << "Enter the number of cars: ";
    cin >> size;
    Car Showroom[size];
    cout << "Enter details of " << size << " cars: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Model of car " << i + 1 << ":";
        cin >> Showroom[i].Model;
        cout << "Year of car " << i + 1 << ":";
        cin >> Showroom[i].year;
        cout << "Price of car " << i + 1 << ":";
        cin >> Showroom[i].price;
    }
    cout << endl;

    for(int i = 0; i < size; i++)
    {
        if(Showroom[i].price > 500000)
        {
            cout << "Data of car " << i << ":" << endl;
            cout << Showroom[i].Model << endl;
            cout << Showroom[i].year << endl;
            cout << fixed << setprecision(0) << Showroom[i].price << endl;
        }
    }
    return 0;
}
