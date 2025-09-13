// Normal one
class Solution {
public:
    bool isVovel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        } else {
            return false;
        }
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> mpp;

        int vovel_freq = 0;

        int con_freq = 0;

        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }
        for (auto i = mpp.begin(); i != mpp.end(); i++) {

            if (isVovel(i->first) && (i->second) > vovel_freq) {
                vovel_freq = i->second;
            } else if (isVovel(i->first) == false && (i->second) > con_freq) {
                con_freq = i->second;
            }
        }

        return con_freq + vovel_freq;
    }
};

//  Optimized code 
class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26], maxVowel = 0, maxConso = 0;
        for (char c : s) {
            int i = c - 'a';
            freq[i]++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                maxVowel = max(maxVowel, freq[i]);
            } else {
                maxConso = max(maxConso, freq[i]);
            }
        }
        return maxVowel + maxConso;
    }
};


/*

Approach :-

1 . Maintain an integer array freq[26] to store the frequency of each lowercase English letter.

2.  Traverse the string character by character. For each character, increase its count in the freq array.

3. If the character is a vowel (a, e, i, o, u), update maxVowel with the maximum frequency seen so far among vowels. Otherwise, update maxConso with the maximum frequency among consonants.

4. Return the sum of the highest-frequency vowel (maxVowel) and the highest-frequency consonant (maxConso).



Complexity :-

TC ; O(n) where n = length of the string

We traverse the string once.

Frequency updates and max checks are O(1) each.

Space Complexity : O(1)

The freq[26] array is of fixed size (26 letters).
No extra space depends on input length.

*/