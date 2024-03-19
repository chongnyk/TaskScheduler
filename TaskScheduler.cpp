class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counters(26);
        int intervals = 0;

        for(char task : tasks){
            counters[task - 'A']++;
        }
        counters.erase(remove(counters.begin(), counters.end(), 0), counters.end());

        sort(counters.begin(), counters.end(), greater<>());

        while(!counters.empty()){
            if(counters.size() >= n + 1){
                for(int i = 0; i < n + 1; i++){
                    counters[i]--;
                    intervals++;
                }
                counters.erase(remove(counters.begin(), counters.end(), 0), counters.end());
            }
            else {
                int limit = counters.size();
                for(int i = 0; i < limit; i++){
                    counters[i]--;
                    intervals++;
                }
                counters.erase(remove(counters.begin(), counters.end(), 0), counters.end());
                if(counters.empty()){
                    break;
                }
                else {
                    intervals += (n + 1) - limit;
                }
            }
            sort(counters.begin(), counters.end(), greater<>());
        }

        
        return intervals;
    }
};
