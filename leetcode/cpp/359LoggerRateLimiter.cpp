#include <string>
#include <unordered_map>

using namespace std;

class Logger {
    unordered_map<string, int> lastTime;
public:
    Logger() {

    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (lastTime.count(message) == 0) {
            lastTime[message] = timestamp;
            return true;
        }
        int last = lastTime[message];
        if(timestamp - last >= 10){
            lastTime[message] = timestamp;  
            return true;
        }
        return false;
    }
};

int main(){
    
}
/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */