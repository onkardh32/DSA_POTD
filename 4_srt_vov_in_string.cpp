class Solution {
public:
    bool is_Vowel(char c) {
        if (c >= 'A' && c <= 'Z') {
            c = 'a' + (c - 'A');
        }
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string sortVowels(string s) {
        int n = s.size();
        unordered_map<char, int> cnt;
        for (char& c : s) {
            if (is_Vowel(c)) {
                cnt[c]++;
            }
        }

        string st = "AEIOUaeiou";
        string t;

        int j = 0;

        for (int i = 0; i < n; i++) {
            if (!is_Vowel(s[i])) {
                t += s[i];
            } else {
                while (cnt[st[j]] == 0) {
                    j++;
                }

                t += st[j];
                cnt[st[j]]--;
            }
        }

        return t;
    }
};
