#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


struct City {
    string name;
    int population;
    double cost;
};

struct Country {
    string name;
    vector<City> cities;
};

struct Tour {
    string name;
    vector<Country> countries;
};

void print_header();
void print_data(const string& country, const string& city, const int& population, const double& price);

int main() {
    Tour tour {
        "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", {
                    {"Bogota", 8778000, 400.98},
                    {"Cali", 2401000, 424.12},
                    {"Medellin", 2464000, 350.98},
                },
            },
            {
                "Brazil", {
                    {"Rio De Janiero", 13500000, 567.45},
                    {"Sao Paulo", 11310000, 975.45},
                    {"Salvador", 18234000, 855.99},
                },
            },
            {
                "Chile", {
                    {"Valdivia", 260000, 569.12},
                    {"Santiago", 7040000, 520.00},
                },
            },
            {
                "Argentina", {
                    {"Buenos Aires", 3010000, 723.77},
                },
            },
        },
    };

    print_header();
    for (const Country &country : tour.countries) {
        string country_name = country.name;
        for (const City &city : country.cities) {
            print_data(country_name, city.name, city.population, city.cost);
            country_name = "";
        }
    }

    return 0;
}

void print_header() {
    cout << setprecision(2) << fixed << left;
    cout << setw(20) << "Country"
         << setw(25) << "City"
         << setw(10) << right << "Population"
         << setw(15) << right << "Price" << "\n"
         << setw(70) <<  setfill('-') << "" << setfill(' ') << endl;
};

void print_data(const string& country, const string& city, const int& population, const double& price) {
    cout << setprecision(2) << fixed << left;
    cout << setw(20) << country
        << setw(25) << city
        << setw(10) << right << population
        << setw(15) << right << price << endl;
};
