#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string filepath = "D:\\Codes\\Projects\\NN-from-scratch\\dataset\\dataset.csv";
    ifstream data;

    data.open(filepath);
    if (data.fail()) {
        cerr << "Error opening file: " << filepath << endl;
        return 1;
    }

    bool firstLine = true;
    string records;

    while(data.peek() != EOF){ 
        getline(data, records);
        if (records.empty()) continue; 
        
        cout << records << endl;
        cout << firstLine << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }

    return 0;
}