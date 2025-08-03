#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "ReadingCsv.h"

using namespace std;

vector<vector<int>> shuffle_data(vector<vector<int>> data){
    random_device rd;
    mt19937 gen(rd());

    shuffle(data.begin(), data.end(), gen);
    
    return data;
}

int main() {
    // Define a 2D vector
    // vector<vector<int>> matrix = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9},
    //     {10, 11, 12}
    // };

    // // Seed and engine for randomness
    // random_device rd;
    // mt19937 gen(rd());

    // // Shuffle the rows of the 2D vector
    // shuffle(matrix.begin(), matrix.end(), gen);

    string abs_path = "D:\\Codes\\Projects\\NN-from-scratch\\dataset\\dataset.csv";

    CsvReader csv_reader = CsvReader();
    vector<vector<int>> table = csv_reader.ReadCsv(abs_path);

    table = shuffle_data(table);

    cout << table[0][0] << endl;

    cout << "Rows: " << csv_reader.GetRows() << ", Columns: " << csv_reader.GetCols() << endl;

    return 0;
}
