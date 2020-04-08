#include <iostream>
#include <vector>
#include <string> 
using namespace std;
int main()
{
    vector<int> cisla;
    while (true) {
        string vstup;
        string end = "q";
        cin >> vstup;
        if (!vstup.compare(end)) {
            break;
        }
        try {
            cisla.push_back(stoi(vstup));
        }
        catch (const std::exception & e){
            cout << "Spatny format zadani" << endl;
        }
    }
    cout << "Zadana cislo jsou:" << endl;
    for(int cislo : cisla) {
        cout << cislo << endl;
    }
}
