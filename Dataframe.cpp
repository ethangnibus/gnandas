#include "Dataframe.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <filesystem>
using namespace std;

// Dataframe constructor
Dataframe::Dataframe(string fname, string date)
{
    // open the csv in read mode
    ifstream csv;
    csv.open(fname);
    bool iskey = false;
    bool dateHasBeenFound = false;
    mostActive = 0;
    numTied = 1;

    // Read lines of the csv one by one. Skip operations on
    // days that aren't the query day. Once we find the day,
    // Store cookie names and how many times they appear in an
    // unordered map (umap).
    while (csv) {
        string s;
        if (!getline(csv, s)) break;
        istringstream ss(s);
        string datetime;
        string cookie;

        // Read everything before the comma into cookie
        // and everythig after into datetime
        while (ss)
        {
            if (iskey) {
                if (!getline(ss, datetime, ',' )) break;
            } else {
                if (!getline(ss, cookie, ',' )) break;
            }
            iskey = !iskey;
        }

        // Continue if query date has not been seen yet.
        // Break if we pass the query date.
        if (datetime.find(date) == std::string::npos) {
            if (dateHasBeenFound) break;
            continue;
        }

        // we only reach this part if we have found the
        // date at least once since we are given the
        // dates in order.
        dateHasBeenFound = true;

        // start a cookie's count at 1 and add it to
        // allCookies if the cookie doesn't
        // exist or update the cookie's count if the cookie
        // is already recorded
        if (umap.find(cookie) == umap.end()) {
            umap[cookie] = 1;
            allCookies.push_back(cookie);
        } else {
            this->umap[cookie] += 1;
        }

        // update the count of the most active cookie
        // and how many cookies are tied at that count
        if (umap[cookie] > mostActive) {
            mostActive = umap[cookie];
            numTied = 1;
        } else if (umap[cookie] == mostActive) {
            numTied += 1;
        }
    }
}

// Print the cookies that tie as the most active cookie.
void Dataframe::printMostActiveCookie() {
    int numPrinted = 0;
    for (int i = 0; i < allCookies.size(); i += 1) {
        string cookie = allCookies[i];
        if (umap[cookie] == mostActive) {
            cout << cookie << endl;
            numPrinted += 1;
        }

        if (numPrinted >= numTied) break;
    }
}
