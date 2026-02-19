#include <iostream>
using namespace std;

void func();
int main(){
    func();
    return 0;
}

void func(){
    struct Camera{
        int megapixels;
    };
    struct Mobile{
        int price;
        Camera pixels;
    };
    int size;
    cin >> size;
    Mobile data[size];
    cout << "Enter the specs of " << size << " mobiles" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "\nEnter Megapixels of mobile " << i + 1 << ":";
        cin >> data[i].pixels.megapixels;
        cout << "Enter price of mobile " << i + 1 << ":";
        cin >> data[i].price;
        if(data[i].pixels.megapixels <= 0 || data[i].price < 0)
        {
            cout << "Invalid data" << endl;
            i--;
        }
    }

    // Data of all mobiles
    cout << "All mobiles data: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Mobile" << i + 1 << " megapixel: "<<data[i].pixels.megapixels << endl;
        cout << "Mobile" << i + 1 << " price: "<<data[i].price << endl;
    }
    //Most expensive Mobile
    int max = 0;

    for (int i = 0; i < size; i++)
    {
        if(data[i].price > max)
        {
            max = data[i].price;
        }
    }
    cout << "Highest price: " << max << endl;

    //Highest Megapixel camera
    max = 0;
    for (int i = 0; i < size; i++)
    {
        if(data[i].pixels.megapixels > max)
        {
            max = data[i].pixels.megapixels;
        }
    }
    cout << "Highest Megapixels: " << max << endl;

    // Average price of mobiles
    float average = 0;
    for(int i = 0; i < size; i++)
    {
        average += data[i].price;
    }
    cout << "Average price is: " << average/size << endl;

    // Count of cellphones with megapixels >= 50
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(data[i].pixels.megapixels >= 50)
        {
            count++;
        }
    }
    cout << "Mobiles with Megapixels >= 50: " << count << endl;

}