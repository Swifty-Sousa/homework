// this was a collaboration between Jackson Robberts, Sandeep Kaushisk and myslf
#include <fstream>
#include <iostream>
#include <sstream>
 
//#include "MovieTree.cpp"
#include "MovieTree.hpp"
 
using namespace std;
int main(int argc, char *argv[]) {
    MovieTree HBOGo;
 
    string filename = argv[1];
    ifstream datafile;
    datafile.open(filename);
    // checks if file is open
    if (datafile.fail()) {
        cout << "error" << endl;
    }
    string movie;
    while (getline(datafile, movie, '\n')) {
        stringstream ss;
        //cout << movie << endl;
        ss << movie;
        int ranking, year, quantity, count = 1;
        string title;
        
        while (getline(ss, movie, ',')) {
            if (count == 1) {
                ranking = stoi(movie);
            }
            else if (count == 2) {
                title = movie;
            }
            else if (count == 3) {
                year = stoi(movie);
            }
            else if (count == 4) {
                quantity = stoi(movie);
            }
            count++;
        }
        HBOGo.addMovieNode(ranking, title, year, quantity);
    }
    datafile.close();
menu:
 
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Rent a movie" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Delete a movie" << endl;
    cout << "5. Count the movies" << endl;
    cout << "6. Quit" << endl;
 
    int selection;
    string movieTitle;
 
    cin >> selection;
 
    if (selection == 1) {
        cout << "Enter title:" << endl;
        getchar();
        getline(cin, movieTitle);
        HBOGo.findMovie(movieTitle);
        goto menu;
    } else if (selection == 2) {
        cout << "Enter title:" << endl;
        getchar();
        getline(cin, movieTitle);
        HBOGo.rentMovie(movieTitle);
        goto menu;
    } else if (selection == 3) {
        HBOGo.printMovieInventory();    
        goto menu;
    } else if (selection == 4) {
        cout << "Enter title:" << endl;
        getchar();
        getline(cin, movieTitle);
        HBOGo.deleteMovieNode(movieTitle);
        goto menu;
    } else if (selection == 5) {
        cout << "Tree contains: " << HBOGo.countMovieNodes() << " movies." << endl;
        goto menu;
    } else if (selection == 6) {
        cout << "Goodbye!" << endl;
        return 0;
    }
}