class Solution {
public:
    string mul(string num,char c,int zero){
        if(c == '0') return "0";
        string ans = "";
        int carry = 0;
        for(int i = num.size() - 1;i >= 0;i--){
            int prod = (num[i] - '0') * (c - '0') + carry;
            ans.push_back((prod % 10) + '0');
            carry = prod/10;
        }
        while(carry){
            ans.push_back((carry % 10) + '0');
            carry /= 10;
        }
        reverse(ans.begin(),ans.end());
        ans += string(zero,'0');
        return ans;
    }
    string add(string A,string B){
        if(A == "") return B;
        if(B == "") return A;
        int i = A.size() - 1,j = B.size() - 1,sum = 0;
        string ans = "";
        while(i >= 0 || j >= 0 || sum){
            if(i >= 0) sum += (A[i--] - '0');
            if(j >= 0) sum += (B[j--] - '0');
            ans.push_back((sum % 10) + '0');
            sum /= 10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string multiply(string num1,string num2){
        if(num1 == "0" || num2 == "0") return "0";
        string ans = "";
        int zero = 0;
        for(int j = num2.size() - 1;j >= 0;j--){
            string curr = mul(num1,num2[j],zero++);
            ans = add(ans,curr);
        }
        return ans;
    }
};
