#include <iostream>
#include "Dataframe.hpp"

using namespace std;
int main(int argc, char** argv) {
    string fname = argv[1];
    string date = argv[3];

    // cout << "filename: " << csv_name << "\n";
    // cout << "date: " << date << "\n";

    // load the data from the csv into a dataframe
    Dataframe df = Dataframe(fname, date);
    df.printMostActiveCookie();

    return 0;
}