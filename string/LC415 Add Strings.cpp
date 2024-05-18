class Solution{
public:
    string addStrings(string num1, string num2){
        
        int carry = 0;
        string result;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        
        while(i >= 0 && j >= 0){
            int val = num1[i] - '0' + num2[j] - '0' + carry;
            i--;
            j--;
            int digit = val % 10;
            carry = val / 10;
            result.push_back(digit + '0');
        }
        
        while(i >= 0){
            int val = num1[i--] - '0' + carry;
            int digit = val % 10;
            carry = val / 10;
            result.push_back(digit + '0');
        }
  
        while(j >= 0){
            int val = num2[j--] - '0' + carry;
            int digit = val % 10;
            carry = val / 10;
            result.push_back(digit + '0');
        }
        while(carry){
            result.push_back(carry + '0');
            carry = carry / 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};