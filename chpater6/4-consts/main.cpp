#include <iostream>

using namespace std;

int main() {
    const float pricePerSmallRoom {25};
    const float pricePerLargeRoom {35};
    const float taxesRate {0.06};
    const short paymentIntervalDays {30};
    
    cout << "How many small room would you like to be cleaned ?" << endl;
    int numberSmallRooms {0};
    cin >> numberSmallRooms;
    
    cout << "How many large room would you like to be cleaned ?" << endl;
    int numberLargeRooms {0};
    cin >> numberLargeRooms;
    
    cout << "Estimate for carpet cleaning service";
    cout << "Number of small rooms: " << numberSmallRooms << endl;
    cout << "Number of large rooms: " << numberLargeRooms << endl;
    
    cout << "Price per small room: $" << pricePerSmallRoom << endl;
    cout << "Price per large room: $" << pricePerLargeRoom << endl;
    
    const float cost = pricePerLargeRoom * numberLargeRooms + pricePerSmallRoom * numberSmallRooms;
    cout << "Cost: $" << cost << endl;
    const float taxe = cost * taxesRate;
    cout << "Taxe: $" << taxe << endl;
    cout << "==================================================" << endl;
    cout << "Total estimate: $" << cost + taxe << endl;
    cout << "This estimate is valid for " << paymentIntervalDays << " days" << endl;
    
    return 0;
}