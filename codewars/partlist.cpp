// https://www.codewars.com/kata/56f3a1e899b386da78000732

#include<iostream>
#include<vector>

using namespace std;

vector<pair <string, string> > partlist(vector<string> &arr) {
    vector<pair <string, string> > partsOut;
    partsOut.reserve(arr.size() - 1);

    for (int i=1; i<arr.size(); i++) {
        pair<string, string> temp;
        
        temp.first = arr[0];
        for (int j=1; j<i; j++)
            temp.first += " " + arr[j];

        temp.second = arr[i];
        for (int j=i+1; j<arr.size(); j++)
            temp.second += " " + arr[j];

        partsOut.push_back(temp);
    }

    return partsOut;
}

int main(void) {
    int n;

    cout << "How many elements? ";
    cin >> n;

    vector<string> elems;
    elems.reserve(n);

    cout << endl << "Enter items: " << endl;

    for (int i=0; i<n; i++) {
        cout << "[" << i << "]" << ": ";
        string elem;
        cin >> elem;
        elems.push_back(elem);
    }

    cout << endl << "Input vector:" << endl << "[";
    vector<string>::iterator it;
    for (it = elems.begin(); it != elems.end() - 1; it++)
        cout << *it << ", ";
    cout << *it << "]" << endl;

    vector<pair<string, string> > parts = partlist(elems);

    cout << endl << "Output vector:" << endl << "[";
    vector<pair <string, string> >::iterator it2; 
    for (it2 = parts.begin(); it2 != parts.end() - 1; it2++)
        cout << "[" << it2->first << ", " << it2->second << "], ";
    cout << "[" << it2->first << ", " << it2->second << "]]" << endl;

    return 0;
}

