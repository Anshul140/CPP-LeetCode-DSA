/*
Moore - Voting Algo
e.g
-> 7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5
-> 7, 7, 5, 7, 5, 1 \ cnt = 0 \ 5, 7 \ cnt = 0 \ 5, 5, 7, 7 \cnt = 0\ 5, 5, 5, 5
*/

int majorityElement(vector<int>& nums) {
    int cnt = 0, curr;
    for(int el: nums){
        if(cnt == 0)
            curr = el;
        if(curr == el)
            cnt++;
        else
            cnt--;
    }
    
    return curr;
}