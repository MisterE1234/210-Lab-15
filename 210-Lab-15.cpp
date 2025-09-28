//COMSC-210|Lab-15|Ethan Aylard
//IDE used: Visual Studio Code
//Program description: This program demonstrates the use of classes and input files together. I will show a movie class with data provided from Prof. Dietrich.

#include <iostream>
#include <fstream>
#include <array>
using namespace std;

//Movie class definition: 
class Movie {
private:
//private member variables:
//3 variables to hold the writer, title, and year of the movie:
    string writer;
    string title;
    int year;

public:

    //standard setters:
    
    //This function sets the writer of the movie:
        //requires: a string representing the writer's name
        //outputs: none
    void setWriter(string w) {
        writer = w;
    }

    //This function sets the title of the movie:
        //requires: a string representing the movie title
        //outputs: none
    void setTitle(string t) {
        title = t;
    }

    //This function sets the year the movie was released:
        //requires: an integer representing the year
        //outputs: none
    void setYear(int y) {
        year = y;
    }

    //standard getters:

    //This function gets the writer of the movie:
        //requires: none
        //outputs: a string representing the writer's name
    string getWriter() const {
        return writer;
    }

    //This function gets the title of the movie:
        //requires: none
        //outputs: a string representing the movie title
    string getTitle() const {
        return title;
    }

    //This function gets the year the movie was released:
        //requires: none
        //outputs: an integer representing the year
    int getYear() const {
        return year;
    }

};

int main() {
    const int SIZE = 4; //number of movies
    array<Movie, SIZE> movies; //array of Movie objects

    ifstream inputFile("movies.txt"); //open the input file
    if (!inputFile) { //check if the file opened successfully
        cerr << "Error opening file." << endl;
        return 1;
    }

    //read data from the file and populate the Movie objects
    for (int i = 0; i < SIZE; ++i) {
        //temporary variables to hold the data read from the file
        string writer, title;
        int year;
        getline(inputFile, title);

        inputFile >> year;
        inputFile.ignore(); //ignore the newline character after the year

        getline(inputFile, writer);
        
        
       //set the data in the Movie object for the current index
        movies[i].setWriter(writer);
        movies[i].setTitle(title);
        movies[i].setYear(year);
    }

    inputFile.close(); //close the input file

    //display the movie information
    cout << "Movie Information:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Movie: " << movies[i].getTitle() << endl;
        cout << "   Year released: " << movies[i].getYear() << endl;
        cout << "   Screenwriter: " << movies[i].getWriter() << endl;
        cout << endl;
    }
    return 0;
}