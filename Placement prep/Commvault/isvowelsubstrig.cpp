class Solution {
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
public:
    int countVowelSubstrings(string word) {
        int ans = 0, N = word.size();
        unordered_map<char, int> count;
        for(int i=0;i<N;i++){
            count.clear();
            for (int j=i;j<N && isVowel(word[j]);j++) {
                count[word[j]]++;
                if(count.size()==5)
                    ++ans;
            }
                
        }
            return ans;
    }
};