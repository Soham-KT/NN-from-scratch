#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

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

    vector<vector<int>> ReadCsv(string path){
      ifstream file(path);
      string line;
      vector<vector<int>> data;

      if (!getline(file, line)) {
        cerr << "Error: File is empty or cannot read header.\n";
        return data;
      }

      while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        vector<int> row;

        while (getline(ss, cell, ',')) {
          try {
            row.push_back(stoi(cell));
          } catch (const invalid_argument& e) {
            cerr << "Invalid integer value: " << cell << '\n';
            row.push_back(0);
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


int main() {
  string abs_path = "D:\\Codes\\Projects\\NN-from-scratch\\dataset\\dataset.csv";

  CsvReader csv_reader = CsvReader();
  vector<vector<int>> table = csv_reader.ReadCsv(abs_path);

  cout << table[0][0] << endl;

  cout << "Rows: " << csv_reader.GetRows() << ", Columns: " << csv_reader.GetCols() << endl;

  return 0;
}