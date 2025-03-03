/*
TC : O(nk)
SC : O(n)
*/
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        if (wordList.empty())
        {
            return 0;
        }

        set<string> st;

        for (int i = 0; i < wordList.size(); i++)
        {
            st.insert(wordList[i]);
        }

        if (st.find(endWord) == st.end())
        {
            return 0;
        }

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while (!q.empty())
        {
            string word = q.front().first;
            int step = q.front().second;

            q.pop();

            for (int i = 0; i < word.length(); i++)
            {
                char c = word[i];

                for (int j = 97; j < 123; j++)
                {

                    if (word[i] == char(j))
                    {
                        continue;
                    }

                    word[i] = char(j);

                    // Base Case
                    if (word == endWord)
                    {
                        return step + 1;
                    }

                    // Logic
                    if (st.find(word) != st.end())
                    {
                        q.push({word, step + 1});
                        st.erase(word);
                    }
                }

                word[i] = c;
            }
        }

        return 0;
    }
};