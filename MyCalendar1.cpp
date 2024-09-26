class MyCalendar {
private:
    vector<pair<int,int>> events;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
       
        for (auto event : events) {
            int bookedStart = event.first;
            int bookedEnd = event.second;
            
          
            if (!(end <= bookedStart || start >= bookedEnd)) {
                return false;
            }
        }
        
       
        events.push_back({start,end});
        return true;
    }
};
