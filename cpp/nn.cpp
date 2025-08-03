#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <typeinfo>

using namespace std;

class CsvReader {
  int rows = 0, cols = 0;

  public:
    int GetRows() const {
      return rows;
    }

    int GetCols() const {
      return cols;
    }

    vector<vector<double>> ReadCsv(string path){
      ifstream file(path);
      string line;
      vector<vector<double>> data;

      if (!getline(file, line)) {
        cerr << "Error: File is empty or cannot read header.\n";
        return data;
      }

      while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        vector<double> row;

        while (getline(ss, cell, ',')) {
          try {
            row.push_back(stod(cell));
          } catch (const invalid_argument& e) {
            cerr << "Invalid double value: " << cell << '\n';
            row.push_back(0.0);
          }
        }
        data.push_back(row);
      }

      file.close();

      rows = data.size();
      cols = rows > 0 ? data[0].size() : 0;

      return data;
    }
};

vector<vector<double>> shuffle_data(vector<vector<double>> data){
    random_device rd;
    mt19937 gen(rd());

    shuffle(data.begin(), data.end(), gen);

    return data;
}

vector<vector<double>> Transpose(vector<vector<double>> data){
  
} 

int main() {
    string abs_path = "D:\\Codes\\Projects\\NN-from-scratch\\dataset\\dataset.csv";

    CsvReader csv_reader = CsvReader();
    vector<vector<double>> table = csv_reader.ReadCsv(abs_path);

    table = shuffle_data(table);

    cout << typeid(table[0][0]).name() << endl;

    cout << "Rows: " << csv_reader.GetRows() << ", Columns: " << csv_reader.GetCols() << endl;

    return 0;
}