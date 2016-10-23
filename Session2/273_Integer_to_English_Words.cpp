class Solution {
public:
    string helper(int n) {
        string twenties[20] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> Tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        if(n < 20)
            return twenties[n];
        if(n < 100) {
            if(n % 10 == 0)
                return Tens[n / 10];
            return Tens[n / 10] + " " + helper(n % 10);
        }
        if(n % 100 == 0)
            return twenties[n / 100] + " " + "Hundred";
        return twenties[n / 100] + " " + "Hundred" + " " + helper(n % 100);
    }
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        string thousands[4] = {"", "Thousand", "Million", "Billion"};
        string res = "";
        int pos = 0;
        while(num != 0) {
            int cur = num % 1000;
            if(cur != 0) {
                if(pos == 0)
                    res = helper(cur);
                else if(res == "")
                    res = helper(cur) + " " + thousands[pos];
                else
                    res = helper(cur) + " " + thousands[pos] + " " + res;
            }
            num = num / 1000;
            pos ++;
        }
        // res.erase(res.length() - 1);
        return res;
    }
};
