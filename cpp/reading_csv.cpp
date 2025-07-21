#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string filepath = "D:\\Codes\\Projects\\NN-from-scratch\\dataset\\dataset.csv";
    string outputpath = "D:\\Codes\\Projects\\NN-from-scratch\\dataset\\hellokitty.txt";
    ifstream data(filepath);
    ofstream output(outputpath);

    bool firstLine = true;
    string records;

    while(data.peek() != EOF){
        if (firstLine){
          firstLine = false;
          getline(data, records);
          continue;  
        }

        getline(data, records);
        if (records.empty()) continue; 
        
        cout << records << endl;
        output << records << endl;
        cout << firstLine << endl;
    }

    return 0;
}