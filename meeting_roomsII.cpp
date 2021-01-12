bool compareI(const vector<int>& v1, const vector<int>& v2)
{
        return v1[0] < v2[0];
}

class Solution {
    
    priority_queue<int, vector<int>, greater<int>> q;
    
public:
    
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0)
            return 0;
        
        sort(intervals.begin(), intervals.end(), compareI);
        
        q.push(intervals[0][1]);
        
        for(int i = 1; i < intervals.size(); i++)
        {
            cout << intervals[i][0] << "::" << intervals[i][1] << endl;
            
            if(intervals[i][0] >= q.top())
                q.pop();
            
            q.push(intervals[i][1]);
        }
        
        return q.size();
        
        
    }
};