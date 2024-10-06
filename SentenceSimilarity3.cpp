class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque<string>d1=split(sentence1);
        deque<string>d2=split(sentence2);
        while(!d1.empty()&&!d2.empty()&&d1.front()==d2.front()){
            d1.pop_front();
            d2.pop_front();
        }
        while(!d1.empty()&&!d2.empty()&&d1.back()==d2.back()){
            d1.pop_back();
            d2.pop_back();
        }
        return d1.empty()||d2.empty();
    }
   deque<string>split(const string& sentence) {
        deque<string>dq;
        stringstream ss(sentence);
        string word;
        while (ss>>word) {
            dq.push_back(word);
        }
        return dq;
    }
};