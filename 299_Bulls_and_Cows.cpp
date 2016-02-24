class Solution {
public:
    string getHint(string secret, string guess) {
        int secretMap[10] = {0};
        int guessMap[10] = {0};
        int len = secret.length();
        int bull = 0;
        int cow = 0;
        for(int i = 0; i < len; i ++) {
            if(secret[i] == guess[i])
                bull ++;
            else {
                /*
                要把字母转换成数字
                */
                secretMap[secret[i] - '0'] ++;
                guessMap[guess[i] - '0'] ++;
            }
        }
        for(int i = 0; i < 10; i ++) {
            cow += min(secretMap[i], guessMap[i]);
        }
        return (to_string(bull) + "A" + to_string(cow) + "B");
    }
};
