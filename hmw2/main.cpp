// Liskovskis_Ricards_221RDB484

#include <iostream>
#include <chrono>

using namespace std;

int main() {
  string userName;
  int userAge;
  int currentYear;
  int yearTurnsHundred;

  // getting current year
  const auto now = std::chrono::system_clock::now();
  time_t currentTime = std::chrono::system_clock::to_time_t(now);
  std::tm* localTime = std::localtime(&currentTime);
  currentYear = localTime->tm_year + 1900;

  cin >> userName;
  cout << "Hello, " << userName << "! What is your age?" << endl;
  cin >> userAge;
  
  // calculate the year when user turns hundred
  yearTurnsHundred = currentYear - userAge + 100;
  cout << "Nice, " << userName << "! You will be 100 y.o. in " << yearTurnsHundred << endl;
  return 0;
}