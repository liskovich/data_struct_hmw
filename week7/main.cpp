#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// exception classes inherit from invalid_argument
// https://en.cppreference.com/w/cpp/error/invalid_argument
// (as these represent the cases of provided invalid argument)

class InvalidDayException : public invalid_argument
{
public:
  InvalidDayException(int day) : invalid_argument("The entered day " + to_string(day) + " is invalid") {}
  InvalidDayException() : invalid_argument("The date must have a numeric format") {}
};

class InvalidMonthException : public invalid_argument
{
public:
  InvalidMonthException(int month) : invalid_argument("The entered month " + to_string(month) + " is invalid") {}
  InvalidMonthException() : invalid_argument("The month must have a numeric format") {}
};

class InvalidYearException : public invalid_argument
{
public:
  InvalidYearException() : invalid_argument("The year must have a numeric format") {}
};

// convert month number to name
string get_month_name(int month)
{
  string monthNames[12] = {
      "January",
      "February",
      "March",
      "April",
      "May",
      "June",
      "July",
      "August",
      "September",
      "October",
      "November",
      "December"};
  if (month < 1 || month > 12)
  {
    throw InvalidMonthException(month);
  }
  return monthNames[month - 1];
}

// get appendix for date printing
string get_date_appendix(int day)
{
  if (day == 1)
  {
    return "st";
  }
  else if (day == 2)
  {
    return "nd";
  }
  else if (day == 3)
  {
    return "rd";
  }
  else
  {
    return "th";
  }
}

// check leap year
bool is_leap_year(int year)
{
  // algorithm to check leap year
  // link: https://stackoverflow.com/a/725111
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
  {
    return true;
  }
  return false;
}

void parse_date(string &dob)
{
  // try extracting date components
  string day_str = "", month_str = "", year_str = "";
  int dash_pos = 0;
  for (int i = 0; i < dob.size(); i++)
  {
    if (dob[i] == '-')
    {
      dash_pos++;
    }
    else
    {
      // write accordingly to day_str, month_str or year_str
      if (dash_pos == 0)
      {
        day_str += dob[i];
      }
      else if (dash_pos == 1)
      {
        month_str += dob[i];
      }
      else if (dash_pos == 2)
      {
        year_str += dob[i];
      }
      else
      {
        break;
      }
    }
  }

  // try converting str to int representations
  int day, month, year;
  try
  {
    day = stoi(day_str);
  }
  catch (const invalid_argument &e)
  {
    throw InvalidDayException();
  }
  try
  {
    month = stoi(month_str);
  }
  catch (const invalid_argument &e)
  {
    throw InvalidMonthException();
  }
  try
  {
    year = stoi(year_str);
  }
  catch (const invalid_argument &e)
  {
    throw InvalidYearException();
  }

  // handle date processing
  if (day < 1 || day > 31)
  {
    throw InvalidDayException(day);
  }

  // handling february case
  if (month == 2)
  {
    // check leap year
    if ((day > 29 && !is_leap_year(year)) || day > 28)
    {
      throw InvalidDayException(day);
    }
  }

  if (month < 1 || month > 12)
  {
    throw InvalidMonthException(month);
  }

  cout << get_month_name(month) << ", " << day << get_date_appendix(day) << ", " << year << endl;
}

int main()
{
  string dob;
  cout << "Enter your DOB" << endl;
  cin >> dob;

  // handle in a try catch
  try
  {
    parse_date(dob);
  }
  catch (const exception &e)
  {
    cerr << e.what() << endl;
  }

  return 0;
}