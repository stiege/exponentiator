#include <iostream>
#include "exponentiator.h"
#include "reverse.h"
#include <exception>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const string USAGE_INFO("Usage: <integer[0-99999]>");

static bool input_is_valid(string input)
{
    bool retval = true;
    if (input.length() > 5 ||
    !all_of(input.begin(), input.end(), ::isdigit))
    {
        retval = false;
    }

    return retval;
}

static string get_input()
{
    string input = "";
    while (true) {
        cout << "Enter an integer number (0-99999): ";
        getline(cin, input);
        if (input_is_valid(input))
            break;
        cout << "Invalid, please try again" << endl;
    }

    return input;
}

int main()
{
    using exponentiator::Exponentiator;
    string input_string(get_input());

    try
    {
        unsigned long int input = stol(input_string);
        Exponentiator expo(reverse);
        cout << expo.run(input) << endl;
    }
    catch(exception& e)
    {
        cout << e.what() << endl;
        return -1;
    }

    return 0;
}
