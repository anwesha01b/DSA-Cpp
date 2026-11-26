class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 10;
        while (n >= turn) {
            n -= turn;
            turn--;
            if (n < turn) {
                return true;
            }
            n -= turn;
            turn--;
        }
        return false;
    }
};