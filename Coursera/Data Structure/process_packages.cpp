#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size):
        size_(size),
        temp_size(size),
        finish_time_()
    {}

    Response Process(const Request &request) {
        // write your code here
      struct Response r(0,0);

      for(int i=0;i<finish_time_.size();i++)  // used to increase temp_size
      {
          if(finish_time_.empty()!=1)
          {
              if(finish_time_[i]<=request.arrival_time)
              {
                  temp_size++;
                  finish_time_.erase(finish_time_.begin());
                  i--;
              }
              else{break;}
          }
          else{break;}

      }
        if(temp_size==size_)
        { temp_size--;
            r.dropped=0;
            r.start_time=request.arrival_time;
            finish_time_.push_back(r.start_time+request.process_time);
        }
        else if(request.arrival_time>=finish_time_.back())
        {

            temp_size--;
            r.start_time=request.arrival_time;
            finish_time_.push_back(r.start_time+request.process_time);

        }
        else if(request.arrival_time<finish_time_.back()&&temp_size!=0)
        {
            temp_size--;
            r.start_time=finish_time_.back();
            finish_time_.push_back(finish_time_.back()+request.process_time);

        }
        else{
            r.dropped=1;
            r.start_time=-1;
        }



        return r;
    }
private:
    int size_;
    int temp_size;
    std::vector<int> finish_time_;
};

std::vector <Request> ReadRequests() {
    std::vector <Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer) {
    std::vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void PrintResponses(const std::vector <Response> &responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main() {
    int size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}
