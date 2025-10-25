#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {
   setlocale(LC_ALL, "ru_RU.utf8");
   while (true) { 
       auto now = system_clock::now();
       time_t t = system_clock::to_time_t(now);
       tm localTime{};
#ifdef _WIN32
       localtime_s(&localTime, &t); // для Windows
#else
       localtime_r(&t, &localTime); // для Linux/macOS
#endif

       cout << "\rТекущее время: "
           << setw(2) << setfill('0') << localTime.tm_hour << ":"
           << setw(2) << setfill('0') << localTime.tm_min << ":"
           << setw(2) << setfill('0') << localTime.tm_sec << flush;

       this_thread::sleep_for(1s);
   }
}
