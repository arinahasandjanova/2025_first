#include <iostream>
#include <vector>

int main() {
    int energy, n; 
    std::cin >> energy >> n;

    std::vector<int> field(n);
    for (int i = 0; i < n; i++) {
        std::cin >> field[i]; 
    }

    int pos = -1;
    bool success = false;


    while (true) {
        if (pos >= n - 1) { 
            success = true;
            break;
        }
        if (energy <= 0) break; 

        bool found = false;

        for (int i = pos + 1; i <= pos + energy && i < n; i++) {
            if (field[i] > 0) {
                energy -= (i - pos); 
                pos = i;
                energy += field[i];  
                found = true;
                break; 
            }
        }

        if (!found) { 
            if (pos + energy >= n - 1) {
                energy -= (n - 1 - pos); 
                pos = n - 1;
                success = true;
            }
            break; 
        }
        
    }

    if (success) {
        std::cout << energy - 1 << std::endl;
    } else {
        std::cout << "-1\n";
    }

    return 0;
}