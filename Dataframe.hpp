#include <unordered_map>
#include <set>
#include <map>
#include <string>
#include <vector>
using namespace std;
#ifndef DATAFRAME_H
#define DATAFRAME_H

class Dataframe
{
private:
    // Cookies are stored as keys and the values are how many
    // times that cookie appears on the query day. I use
    // and unordered map to keep operations at O(1) time
    // complexity.
    unordered_map<string, int> umap;

    // stores the names of all cookies in order so the top
    // cookies can be printed in order.
    vector<string> allCookies;

    // stores the number of tied cookies
    int numTied;

    // Stores the count of the most active cookie(s).
    int mostActive;
public:
    // Constructor.
    Dataframe(string fname, string date);

    // Prints out the most active cookies.
    void printMostActiveCookie();
};

#endif