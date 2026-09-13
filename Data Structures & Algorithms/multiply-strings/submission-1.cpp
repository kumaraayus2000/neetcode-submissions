class Solution {
public:
    string multiply(string num1, string num2) {
        
        long long x1 = stoi(num1);
        long long x2 = stoi(num2);
        long long x3 = x1 * x2;
        return to_string(x3);
    }
};
