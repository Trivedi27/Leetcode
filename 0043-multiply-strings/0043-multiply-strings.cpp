class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string result = "";
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result += (sum % 10) + '0';
            carry = sum / 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        vector<string> partialProducts;

        for (int i = n - 1; i >= 0; i--) {
            string temp = "";
            int carry = 0, digit1 = num1[i] - '0';

            for (int j = m - 1; j >= 0; j--) {
                int digit2 = num2[j] - '0';
                int product = digit1 * digit2 + carry;
                temp += (product % 10) + '0';
                carry = product / 10;
            }

            if (carry) temp += (carry + '0');

            reverse(temp.begin(), temp.end());

            temp.append(n - 1 - i, '0');
            
            partialProducts.push_back(temp);
        }

        string result = "0";
        for (string& s : partialProducts) {
            result = addStrings(result, s);
        }

        return result;
    }
};

auto init =[](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();