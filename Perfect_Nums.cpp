#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

std::string punctuation(unsigned long long val) {
  int dgts = std::snprintf(nullptr, 0, "%llu", val);
  if (dgts >= 4) {
      std::vector<char> pnum(dgts+1);
      std::snprintf(pnum.data(), pnum.size(), "%llu", val);

      int amnt = pnum.size();
      int i = 4;
      while (i < pnum.size()) {
          pnum.insert(pnum.end()-i, '.');
          i += 4;
      }
  
      std::string num(pnum.begin(), pnum.end());
      return num;
  }
  else {
      std::string num = std::to_string(val);
      return num;
  }
}

int main() {
    std::cout << "          Perfect Numbers          " << std::endl;

    std::cout << "Types: Range or Specific Numbers" << std::endl;
    std::cout << "Choose: ";
    std::string type;
    std::cin >> type;

    if (type == "Range" || type == "range") {
        
        // Inputs
        int n1;
        int n2;
        std::cout << "From: ";
        std::cin >> n1; // First Input
        std::cout << "To: ";
        std::cin >> n2; // Second Input

        // Work
        if (n1 <= n2) {
            std::cout << "1. Number per number." << std::endl;
            std::cout << "2. Use the Euclides's formula (2^(p-1)*2^p-1)." << std::endl;
            std::cout << "Choose 1 or 2: ";
            int tf;
            std::cin >> tf; // Type of formula input.
            int n3 = n2+1; // Time Variable
            bool np = false; // Loops Picks

            if (tf == 1) {
                for (int n=n1; n < n3; ++n) { // Range Loop
                    int d = 1; // Loop counter.
                    int s = 0; // Loop step.
                    while (d <= n) {
                        if (n % d == 0) {
                            s += d; // It save.
                        }
                        d += 1; // Sum for the loop.
                        if (d == n and s == n and s != 1) {
                            std::cout << n << std::endl; // n is the perfect number.
                            np = true; // Allow
                        }
                    }
                }
                if (!np) {
                    std::cout << "There are no perfect numbers in this range of numbers." << std::endl;
                }
            }
            else if (tf == 2) {
                for (int n=n1; n < n3; ++n) { // Range Loop
                    bool first = true; // Pick loop Eiclide's formula.
                    if (n != 1) {
                        int p = std::pow(2, n)-1;
                        if (p <= 1) {
                            first = false; // Not continue because in range there is no number perfects.
                        }
                        else {
                            for (int pr=2; pr < (int)p/2+1; ++pr) {
                                if (p % pr == 0) { // Test Prime Number.
                                    first = false;
                                    break; // Stop and continue if not is number perfect.
                                }
                            }
                            if (first) {
                                unsigned long long r = (std::pow(2, n-1)) * (std::pow(2, n)-1); // Euclide's formula 2^(p-1)*2^p-1.
                                np = true;
                                //std::cout << r << std::endl;
                                std::cout << punctuation(r) << std::endl;
                            }
                        }
                    }
                }
                if (!np) {
                    std::cout << "There are no perfect numbers in this range of numbers." << std::endl;
                }
            }
            else {
                std::cout << "Choose only 1 or 2." << std::endl;
            }
        }
            
        else {
            std::cout << "It's not from least to greatest." << std::endl;
        }
    }
    
    else if (type == "Number" || type == "number") {
        int n;
        std::cout << "Number: ";
        std::cin >> n; // Input
        if (n != 0 || n != 1) {
            int a = 1; // Variable Counter.
            int b = 0; // Save variable.
            while (a <= (int)n/2) {
                if (n % a == 0) {
                    b += a; // And save.
                    if (b == n && a == (int)n/2) {
                        std::cout << n << " it's a perfect number." << std::endl;
                    }
                }
                else if (a == (int)n/2) {
                    std::cout << n << " it not is a perfect number." << std::endl;
                }
                a += 1; // Sum for next.
            }
        }
        else {
            std::cout << n << " it not is a perfect number." << std::endl;
        }
    }
    else {
        std::cout << "Choose Range or Number." << std::endl;
    }
    return 0;
}
