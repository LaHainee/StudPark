#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

class Logger {
  public:
    static enum {
        VERBOSE = 'V',
        FATAL =   'F',
        INFO =    'I',
        DEBUG =   'D'
    } logTypes;
    Logger();
    ~Logger();
    static void Log(const char, const char *);
  
  private:
    static std::ofstream file;
};