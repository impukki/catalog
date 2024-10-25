#include <iostream>
#include <vector>
#include <string>

long long convertToDecimal(const std::string& value, int base) {
    long long result = 0;
    for (char digit : value) {
        result *= base;
        if (isdigit(digit)) {
            result += digit - '0'; 
        } else {
            result += digit - 'a' + 10; 
        }
    }
    return result;
}

long long calculateConstantTerm(const std::vector<int>& x_values, const std::vector<long long>& y_values, int k) {
    long long c = 0;

    for (int i = 0; i < k; ++i) {
        long long term = y_values[i];
        for (int j = 0; j < k; ++j) {
            if (i != j) {
                term *= x_values[j];
                term /= (x_values[i] - x_values[j]);
            }
        }
        c += term;
    }

    return c;
}

void processTestCase(int n, int k, const std::vector<std::string>& bases, const std::vector<std::string>& values) {
   
    std::vector<int> x_values(n);
    for (int i = 0; i < n; ++i) {
        x_values[i] = i + 1; 
    }

   
    std::vector<long long> y_values;
    for (int i = 0; i < n; ++i) {
        int base = std::stoi(bases[i]); 
        long long y_value = convertToDecimal(values[i], base); 
        y_values.push_back(y_value);
    }

    long long secret_c = calculateConstantTerm(x_values, y_values, k);

  
    std::cout << "For test case with n = " << n << ", k = " << k << ", the secret constant term c is: " << secret_c << std::endl;
}

int main() {
   
    int n1 = 4; 
    int k1 = 3;
    std::vector<std::string> bases1 = {"10", "2", "10", "4"};
    std::vector<std::string> values1 = {"4", "111", "12", "213"};

    processTestCase(n1, k1, bases1, values1);

   
    int n2 = 10; 
    int k2 = 7;
    std::vector<std::string> bases2 = {"6", "15", "15", "16", "8", "3", "3", "6", "12", "7"};
    std::vector<std::string> values2 = {
        "13444211440455345511", 
        "aed7015a346d63", 
        "6aeeb69631c227c",
        "e1b5e05623d881f", 
        "316034514573652620673",
        "2122212201122002221120200210011020220200",
        "20120221122211000100210021102001201112121",
        "20220554335330240002224253", 
        "45153788322a1255483",
        "1101613130313526312514143"
    };

    processTestCase(n2, k2, bases2, values2);

    return 0;
}