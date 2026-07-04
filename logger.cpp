#include <iostream>
using namespace std;

#include "logger.h"// Logger Levels

// Improvements:
// Remove cout and add gpio usage.

class Logger{
    private:
        static bool logon;
    protected:
    // No one can create this object except itself
        Logger(){};
    public:
        static Logger& get_instance(){
            // 
            static Logger _instance;
            return _instance;
        }
        void enablelog(bool enable){
            // Static to have in memory the value of logon
            if (enable) {
                logon = true;
            }else{
                logon = false;
            }
        }
        void logmessage(LoggerLevel level,const char* message){
            if (logon){
                if (level == LoggerLevel::Info){
                    cout<<"Info:"<<message<<endl;
                }
                if (level == LoggerLevel::Error){
                    cout<<"Error:"<<message<<endl;
                }
                if (level == LoggerLevel::Debug){
                    cout<<"Debug:"<<message<<endl;
                }
            }else{
                return;
            }
        }

};

bool Logger::logon = false;

// Sample Usage
int main() {
    Logger& log = Logger::get_instance();
    log.enablelog(true);
    log.logmessage(LoggerLevel::Debug, "Debugging Already?");
    log.enablelog(false);
    log.logmessage(LoggerLevel::Info, "Wheew close one!");
    log.enablelog(true);
    log.logmessage(LoggerLevel::Error, "Oopsie");

    return 0;
}