#include <iostream>
using namespace std;

int main(){
    struct Address{
        string City;
        string Country;
    };
    struct contact_info{
        string Name;
        int PhoneNo;
        Address address;
        };
    int size;
    cout << "Enter number of people: ";
    cin >> size;
    contact_info People[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter names of person " << i + 1 << ":";
        cin >> People[i].Name;
        cout << "Enter phone number of person " << i + 1 << ":";
        cin >> People[i].PhoneNo;
        cout << "Enter City of person " << i + 1 << ":";
        cin.ignore();
        cin >> People[i].address.City;
        cout << "Enter Country of person " << i + 1 << ":";
        cin.ignore();
        cin >> People[i].address.Country;
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Name of person" << i + 1 << ":" << People[i].Name << endl;
        cout << "Phone Number of person" << i + 1 << ":" << People[i].PhoneNo << endl;
        cout << "City of person" << i + 1 << ":" << People[i].address.City << endl;
        cout << "Name of person" << i + 1 << ":" << People[i].address.Country << endl;
    }
    return 0;
}