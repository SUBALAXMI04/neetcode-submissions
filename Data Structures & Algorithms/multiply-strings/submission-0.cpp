class Solution {
public:
    string mul(string num,char c,int zero){
        if(c == '0') return "0";
        string res = "";
        int carry = 0;
        for(int i = num.size() - 1;i >= 0;i--){
            int prod = (num[i] - '0') * (c - '0') + carry;
            res.push_back((prod % 10) + '0');
            carry = prod / 10;
        }
        while(carry){
            res.push_back((carry % 10) + '0');
            carry /= 10;
        }
        reverse(res.begin(),res.end());
        res += string(zero,'0');
        return res;
    }
    string add(string A,string B){
        if(A == "") return B;
        if(B == "") return A;
        string res = "";
        int i = A.size() - 1,j = B.size() - 1,carry = 0;
        while(i >= 0 || j >= 0 || carry){
            if(i >= 0) carry += (A[i--] - '0');
            if(j >= 0) carry += (B[j--] - '0');
            res.push_back((carry % 10) + '0');
            carry /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string multiply(string num1,string num2){
        if(num1 == "0" || num2 == "0") return "0";
        if(num1.size() < num2.size()) return multiply(num2,num1);
        int zero = 0;
        string ans = "";
        for(int j = num2.size() - 1;j >= 0;j--){
            string curr = mul(num1,num2[j],zero);
            ans = add(ans,curr);
            zero++;
        }
        return ans;
    }
};
