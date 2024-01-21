#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Define a structure to store non-zero elements
struct NonZeroElement {
    int row;
    int column;
    int value;
};

class SparseMatrix {
private:
    vector<NonZeroElement> elements;
    vector<vector<int>> fullMatrix;
    int numRows;
    int numColumns;

public:
    // Constructor initializes the full matrix size
    SparseMatrix(int m, int n) : numRows(m), numColumns(n), fullMatrix(m, vector<int>(n, 0)) {}

    // Function to read a sparse matrix from user input
    void readMatrix() {
        cout << "Enter the elements for a " << numRows << "x" << numColumns << " matrix:" << endl;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numColumns; ++j) {
                cout << "Enter element for Row [" << i << "] Column [" << j << "]: ";
                cin >> fullMatrix[i][j];
                if (fullMatrix[i][j] != 0) {
                    elements.push_back({i, j, fullMatrix[i][j]});
                }
            }
        }
    }

    // Function to display the original full matrix
    void displayFullMatrix() {
        cout << "\nFull Matrix:" << endl;
        for (const auto &row : fullMatrix) {
            for (int val : row) {
                cout << setw(5) << val;
            }
            cout << endl;
        }
    }

    // Function to display the sparse matrix representation
    void displaySparseMatrix() {
        cout << "\nSparse Matrix Representation:" << endl;
        cout << "Row\tColumn\tValue\n";
        for (const NonZeroElement& e : elements) {
            cout << setw(4) << e.row << '\t' 
                 << setw(6) << e.column << '\t' 
                 << setw(5) << e.value << endl;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Create a SparseMatrix object
    SparseMatrix sparse(rows, cols);

    // Read matrix from user input
    sparse.readMatrix();

    // Display the original full matrix
    sparse.displayFullMatrix();

    // Display the sparse matrix representation
    sparse.displaySparseMatrix();

    return 0;
}
