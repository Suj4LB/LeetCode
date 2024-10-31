/*
Q. - A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.
*/

Solution - Used a priority queue

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        if(a){
            pq.push({a,'a'});
        }
        if(b){
            pq.push({b,'b'});
        }
        if(c){
            pq.push({c,'c'});
        }
        string ans="";
        char last='e';
        while(!pq.empty()){
            int maxi=pq.top().first;
            char c=pq.top().second;
            pq.pop();
            if(last!=c){
                last=c;
                int x=min(2,maxi);
                maxi-=x;
                while(x--){
                    ans.push_back(c);
                }
                if(maxi){
                    pq.push({maxi,c});
                }
            }
            else{
                if(pq.empty()){
                    return ans;
                }
                int newMaxi=pq.top().first;
                char newC=pq.top().second;
                pq.pop();
                last=newC;
                int x=min(1,newMaxi);
                newMaxi-=x;
                while(x--){
                    ans.push_back(newC);
                }
                if(newMaxi){
                    pq.push({newMaxi,newC});
                }
                if(maxi){
                    pq.push({maxi,c});
                }
            }
        }
        return ans;
    }
};
