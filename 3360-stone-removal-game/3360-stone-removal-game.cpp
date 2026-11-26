class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = true;
        int temp = n;
        int remove = 10;
        while(temp >= 0) {
            bool isAlice = true;
            if(isAlice) {
                if(temp < remove) {
                    alice = false;
                    break;
                } 
                temp -= remove;
                remove--;
                isAlice = false;
            }

            if(!isAlice) {
                if(temp < remove) {
                    return true;
                }
                else{
                    temp -= remove;
                    remove--;
                }
            }
        }
        return alice;
    }
};