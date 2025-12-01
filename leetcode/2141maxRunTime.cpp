#include <vector>

class Solution {
public:
    long long maxRunTime(int n, std::vector<int>& batteries) {
        /*
         n =2

        batteries =[3,3,3]


        [3,3,3]

        comp1 insert bar 0 

        

        comp2 insert bat 1 keep it 
        remvoe bat 1 from comp 2 when 1 min left insert bat 2, last bat  

        simultaneouslyCount = 2; 

        third minute comp 1 runs out, simultaneouslyCount becomes  = 3 now,

        comp 1 run out so isnert battery 1 that has 1 min left,

        comp 2 still has new bnattery so it;s thsi si 4th minute cause comp1 ha 1 min comp2 has 2 mni left, 

        simultaneouslyCount becomes  = 4 now,

        */


        long left = 0;

        long sumPower = 0;
        
        for(int power : batteries){
            sumPower += power;
        }

        int right = sumPower / n;


        while(left < right){
            int midValueTarget  = right - (right - left) / 2;
            long extra = 0;
            for (int power : batteries)
                extra += std::min(power, midValueTarget);
            if(extra >= n * midValueTarget){
                left = midValueTarget;
            }else{
                right = midValueTarget -1;
            }
        }
        return left;

    }
};