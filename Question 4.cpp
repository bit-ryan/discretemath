#include <iostream>
#include <vector>

void findSolutions(int n, int C, std::vector<int>& solution, int index, int currentSum) {
    // Base case: if index reaches n, check if the current sum equals C
    if (index == n) {
        if (currentSum == C) {
            // Print the solution
            for (int i = 0; i < solution.size(); i++) {
                std::cout << solution[i];
                if (i < solution.size() - 1) {
                    std::cout << " + ";
                }
            }
            std::cout << " = " << C << std::endl;
        }
        return;
    }
    
    // Try all possible values for xi (0 to C - currentSum)
    for (int i = 0; i <= C - currentSum; i++) {
        // Choose xi = i
        solution[index] = i;
        // Recursively find solutions for x(i+1), x(i+2), ..., xn
        findSolutions(n, C, solution, index + 1, currentSum + i);
    }
}

int main() {
    int n, C;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    std::cout << "Enter the value of C (C <= 10): ";
    std::cin >> C;
    
    std::vector<int> solution(n);
    findSolutions(n, C, solution, 0, 0);
    
    return 0;
}
