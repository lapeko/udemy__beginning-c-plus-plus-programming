#include <iostream>
#include <cstring>
#include <cctype>


using namespace std;

int main() {
    char first_name[20] {};
    char last_name[20] {};
    char full_name[50] {};
    char full_name_2[50] {};
    char temp_string[50] {};

    cout << "first_name: " << first_name << endl; // try it without initialization
    cout << "Enter your first name: ";
    cin.getline(first_name, 20);
    
    cout << "Enter your last name: ";
    cin.getline(last_name, 20);
    
    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);
    
    cout << "Your first name is: " << first_name << ". The length of your first name is: " << strlen(first_name) << endl;
    cout << "Your last name is: " << last_name << ". The length of your last name is: " << strlen(last_name) << endl;
    cout << "Your full name is: " << full_name << endl;
    
    cout << "Enter your full name: " << endl;
    cin.getline(full_name_2, 50);
    cout << "Your full name is: " << full_name_2 << endl;
    
    strcpy(temp_string, full_name_2);
    if (strcmp(temp_string, full_name_2) == 0)
        cout << "\"" << temp_string << "\"" << " and " << "\"" << full_name_2 << "\"" << " are equal" << endl;
    else 
        cout << "\"" << temp_string << "\"" << " and " << "\"" << full_name_2 << "\"" << " are different" << endl;
        
    for (size_t i {0}; i < strlen(full_name_2); i++)
        if (isalpha(full_name_2[i]))
            full_name_2[i] = toupper(full_name_2[i]);
            
    if (strcmp(temp_string, full_name_2) == 0)
        cout << "\"" << temp_string << "\"" << " and " << "\"" << full_name_2 << "\"" << " are equal" << endl;
    else 
        cout << "\"" << temp_string << "\"" << " and " << "\"" << full_name_2 << "\"" << " are different" << endl;
    
    return 0;
}