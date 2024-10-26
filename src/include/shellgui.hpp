#ifndef CURSES_GUI_CALCULATOR
#define CURSES_GUI_CALCULATOR

#include <map>
#include <iostream>
#include <curses.h>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cctype>

extern std::map<std::string, double> variables;

inline void calcShell() {
    initscr();
    int scrX, scrY;
    getmaxyx(stdscr, scrX, scrY);
    mvprintw(scrX / 2, scrY / 2, "Hello!");
    refresh();
}

#endif