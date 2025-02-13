#include <iostream>
#include <vector>

using namespace std;

class Grid {
    private:
        int numRows, numCols;
        vector<vector<int>> data;

    public:
        Grid(int n, int m) : numRows(n), numCols(m), data(n, vector<int>(m, 0)) {}

        int getRowCount() {
            return numRows;
        }

        int getColCount() {
            return numCols;
        }

        void updateElement(int x, int y, int value) {
            if (x >= 0 && x < numRows && y >= 0 && y < numCols) {
                data[x][y] = value;
            }
        }

        void show() const {
            for (const auto& row : data) {
                for (int element : row) {
                    cout << element << " ";
                }
                cout << endl;
            }
        }

        Grid operator+(const Grid& other) {
            if (numRows != other.numRows || numCols != other.numCols) {
                cout << "Grids cannot be added" << endl;
                return *this;
            }

            Grid result(numRows, numCols);
            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < numCols; ++j) {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
            return result;
        }

        Grid operator*(const Grid& other) {
            if (numCols != other.numRows) {
                cout << "Grids cannot be multiplied" << endl;
                return *this;
            }
            Grid result(numRows, other.numCols);
            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < other.numCols; ++j) {
                    for (int k = 0; k < numCols; ++k) {
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
            return result;
        }
};

int main(int argc, char* argv[]) {
    int a1 = stoi(argv[1]), a2 = stoi(argv[2]);
    int b1 = stoi(argv[3]), b2 = stoi(argv[4]);

    Grid grid1(a1, a2), grid2(b1, b2);
    int index = 5;

    for (int i = 0; i < a1; ++i) {
        for (int j = 0; j < a2; ++j) {
            grid1.updateElement(i, j, stoi(argv[index++]));
        }
    }

    for (int i = 0; i < b1; ++i) {
        for (int j = 0; j < b2; ++j) {
            grid2.updateElement(i, j, stoi(argv[index++]));
        }
    }

    cout << "Grid 1:" << endl;
    grid1.show();

    cout << "Grid 2:" << endl;
    grid2.show();

    Grid gridSum = grid1 + grid2;
    cout << "Grid 1 + Grid 2:" << endl;
    gridSum.show();

    Grid gridProduct = grid1 * grid2;
    cout << "Grid 1 * Grid 2:" << endl;
    gridProduct.show();

    return 0;
}

