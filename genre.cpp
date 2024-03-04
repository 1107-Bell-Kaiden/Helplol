#include "genre.h"

Genre::Genre(){
    //default constructor
    //set all values in header to a specific value here
    nameOfGenre = "unknown";
    numMoviesInGenre = 0;

    //you do not need to set any value for the arrays
}

Genre::Genre(string name, Movie* movies, int num){
    //parameterized constructor
    //set the properties equal to the passed in parameters provided above
    nameOfGenre = name;
    numMoviesInGenre = num;
    //the values in the array need to be set using a for loop
    for (int i = 0; i < numMoviesInGenre; i++) {
        moviesOfGenre[i] = movies[i];
    }
}

Genre::Genre(const Genre &rhs){
    //copy constructor
    //to access the properties of the original copy use the dot operator.  For example rhs.nameOfGenre
    nameOfGenre = rhs.nameOfGenre;
    numMoviesInGenre = rhs.numMoviesInGenre;
    //the values in the array need to be set using a for loop
    for (int i = 0; i < numMoviesInGenre; i++) {
        moviesOfGenre[i] = rhs.moviesOfGenre[i];
    }

}

//implement getters
string Genre::getNameOfGenre(){
    return nameOfGenre;
}
Movie* Genre::getMoviesOfGenre(){
    return moviesOfGenre;

}
int Genre::getNumMoviesInGenre(){
    return numMoviesInGenre;
}
//implement setter

void Genre::setNameOfGenre(string name){
    nameOfGenre = name;

}

//replaces setter for arrays. adds a movie object to the last position in the movie array
void Genre::addMovieOfGenre(Movie movie){
    int i = numMoviesInGenre;
    if (numMoviesInGenre < 500) {
         moviesOfGenre[numMoviesInGenre] = movie;
    } else {
        cout << "Movie List is Full! " << endl;
    }
}

        //function to swap the position of two movies. should be used in the bubblesort helper function
void Genre::swapMovies(int mov1, int mov2){
    Movie temp(moviesOfGenre[mov1]);
    moviesOfGenre[mov1] = moviesOfGenre[mov2];
    moviesOfGenre[mov2] = temp;
}

//display a list of all movies in the genre
void Genre::displayMovies(){
    for(int i = 0; i < numMoviesInGenre; i++){
        cout << i+1 << ". " << moviesOfGenre[i].getTitle() << endl;
    }
}