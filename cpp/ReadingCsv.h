#ifndef READINGCSV_H
#define READINGCSV_H

#include <string>
#include <vector>

class CsvReader {
        int rows = 0, cols = 0;
    public:
        int GetRows() const;

        int GetCols() const;

        std::vector<std::vector<int>> ReadCsv(std::string path);
};

#endif