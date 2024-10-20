#include <iostream>
#include <string>

#include "include/calc.hpp"

using namespace std;

int loopValue = 0; // used for while
string command;    // used for command shell

int main() {
    while ( loopValue == 0 ) {
        cout << "Calculator v" << version << endl;
        while ( loopValue == 0 ) {
            cout << ">>> ";
            cin >> command;
            if ( command == "version" ) {
                cout << "Calculator v" << version << endl;
            } else if ( command == "exit" ) {
                cout << "Good bye." << endl;
                return 0;
            } else if ( command == "help" ) {
                cout << "writing..." << endl;
            } else {
                cout << "Unknown command." << endl;
            }
        }
    }
}