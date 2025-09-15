//Approach - simple iteration
//T.C : O(m+n), m = length of text, n = length of brokenLetters
//S.C : O(1)

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool m[26];// by def value is false
        int count = 0;
        bool canType = true;

        // pre populating the map by traversing brokenLetters
        for (char ch : brokenLetters) {
            m[ch - 'a'] = true;
        }
        for (char ch : text) {
            int index = ch - 'a';

            
            if (ch == ' ') {
                if (canType) {
                    count++;
                }

                canType = true;

            } else if (m[ch - 'a'] == true) {
                canType = false;
            }
        }
        // to check for last word
        if (canType) {
            count++;
        }
        return count;
    }
};

/*

Take Aways : 
1. Instead of taking the map and iterating on subString again & again made use of array as an map to decrease the traversing for each substr which reduces the TC

2. Reduced the code size by checking for the Spaces conditions first then for non spaces character to avoid the index out of bound for ' ' in map aray 

3. Make use of aray as a map or set to reduce TC when there is fixed size characters like digits from 0-9 and alphabets from a-z in this case the range is limited


*/

