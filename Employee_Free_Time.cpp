/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    Interval megeHelper(Interval a, Interval b)
    {
        Interval output;
        //only 2 cases possible
        if(b.start <= a.end)
            output = a;
        if(a.end < b.end)
        {
            output.start = a.start;
            output.end = b.end;
        }
        return output;
    }
    
    void mergeSchedule(vector<Interval> &s)
    {
        vector<Interval> output = {};
        
        //sort the schedules by start time
        sort(s.begin(), s.end(), [](Interval &a, Interval &b){return a.start < b.start;});
        
        //now start merging
        output.push_back(s.front());
        
        for(int i=1; i<s.size(); i++)
        {
            Interval curr = s[i];
            Interval prev = output.back();
            
            //if the intervals are disjoint, lets just push the new interval
            if(prev.end < curr.start)
            {
                output.push_back(curr);
            }
            else
            {
                //if we are here, it means that the interval is overlapping in some way
                output.pop_back();
                Interval toBePushed = megeHelper(prev, curr);
                output.push_back(toBePushed);
            }
        }
        
        s = output;
        return;
    }
    
    //approach: merge the schedule
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
      
      vector<Interval> all_schedule;  
      for(int i=0; i<schedule.size(); i++)
      {
          //get the schedule for person i
          for(int j=0; j<schedule[i].size(); j++)
          {
              all_schedule.push_back(schedule[i][j]);
          }
      }
        
      //MERGE SCHEDULE
      mergeSchedule(all_schedule);
      
      //now this is all the scheule. Get the free time from all schedules by finding subsequent gaps
      vector<Interval> output = {};
      Interval prev = all_schedule[0];
      for(int i=1; i<all_schedule.size(); i++)
      {
          Interval curr = all_schedule[i];
          Interval toBePushed(prev.end, curr.start);
          output.push_back(toBePushed);
          prev = curr;
      }
        
      return output;
    }
};
