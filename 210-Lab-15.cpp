//COMSC-210|Lab-15|Ethan Aylard
//IDE used: Visual Studio Code
//Program description: This program demonstrates the use of classes and input files together. I will show a movie class with data provided from Prof. Dietrich.

#include <iostream>
#include <fstream>
#include <array>
using namespace std;

class Movie {
private:
    string writer;
    string title;
    int year;

public:

    //standard setters:
    void setWriter(string w) {
        writer = w;
    }
    void setTitle(string t) {
        title = t;
    }
    void setYear(int y) {
        year = y;
    }

    //standard getters:
    string getWriter() const {
        return writer;
    }
    string getTitle() const {
        return title;
    }
    int getYear() const {
        return year;
    }

};

