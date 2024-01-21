#include <iostream>
#include <vector>

// Define the structure for a node in the linked list
struct Node {
    int row;
    int col;
    int value;
    Node* next;

    // Constructor to initialize the node
    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

// Function to insert a new node into the linked list for non-zero elements
Node* insert(Node* start, int row, int col, int value) {
    if (value == 0) return start; // Only insert non-zero elements

    Node* newNode = new Node(row, col, value);
    if (start == nullptr) {
        return newNode;
    }
    
    Node* current = start;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;

    return start;
}

// Function to display the matrix
void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Function to display the linked list with headings
void displayLinkedList(Node* start) {
    std::cout << "Linked List Representation (non-zero elements):\n";
    std::cout << "Row\tColumn\tValue\tNext Node Address\n";
    std::cout << "-------------------------------------------------\n";

    Node* current = start;
    while (current != nullptr) {
        std::cout << current->row << "\t" 
                  << current->col << "\t" 
                  << current->value << "\t" 
                  << static_cast<void*>(current->next) << std::endl;
        current = current->next;
    }
}

// Function to delete the linked list and free memory
void deleteList(Node* start) {
    Node* current = start;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows for the matrix: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns for the matrix: ";
    std::cin >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    std::cout << "\nEnter the elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) {
        std::cout << "Enter elements for row " << i << ":\n";
        for (int j = 0; j < cols; ++j) {
            std::cout << "[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    // Display the entered matrix
    std::cout << "\nEntered Matrix:\n";
    displayMatrix(matrix);

    // Create the linked list for the sparse matrix
    Node* start = nullptr;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            start = insert(start, i, j, matrix[i][j]);
        }
    }

    // Display the linked list
    displayLinkedList(start);

    // Clean up memory
    deleteList(start);

    return 0;
}
