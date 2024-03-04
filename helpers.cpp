#include "helpers.h"

int readFile(ifstream& file, Movie* movies){
    int count = 0;

    string junk;
    //example get line to read in the first line of the csv file. 
    //this reads the line indicating the categories and gets rid of it as it's not needed
    getline(file, junk);

    //basic while loop to read through the file until the end of it is hit
    while(!file.eof()){
        //getline with the delimiter provided. Reads the value with the rank category and gets rid of it
        getline(file, junk, ',');
        
        //Create a series of string variables to store the needed categories to create a movie object
        string title, description, director, genre , actors;
        //Create two string arrays to hold the genres and actors.
        string genres[10], actor[10];
        //Create two integer variables to keep track of the number of actors and genres per line. for example guardians would have 3 actors and 3 genres
        int numActors, numGenres;
        float rating;
        int year, runtime, votes;
        double revenue, metascore;
        //implement getlines to read and store the appropriate info until you reach the list of genres.
        getline(file, title, ',');
        getline (file, genre, ',');
        getline(file, description, ',');
        getline(file, director, ',');
        getline(file, actors, ',');
        file >> year;
        file.ignore(1);
        file >> runtime;
        file.ignore(1);
        file >> rating;
        file.ignore(1);
        file >> votes;
        file.ignore(1);
        file >> revenue;
        file.ignore(1);
        file >> metascore;
        file.ignore(1);
        


        //use a do while to parse the list of genres
        getline(file, junk, '"');
        do {
            //inside the do  while use getline to parse the genres. each genre will be stored into the created genre array. the genre count variable should be used to keep track of which index to store the genre at
            //up the genre count variable
            getline(file, genres[numGenres], '"');
            numGenres++;
        } while (getline(file, junk, '"'));
        file.ignore(1);
        //genres[genCount-1][genres[genCount-1].length() - 1] != '"' is the termination check for how to exit the do while
        //essentially you are going to check for whether there is a " on the last genre, as that determines if we have reached the end of the list
        //genres[genCount-1].pop_back(); is an example of how to remove the " after exiting the do while loop

        //The above instructions is a suggestion for how to parse the list of genres. if something else works better for you, then you are free to use a different method

       //use getlines to continue reading from file until you hit the list of actors
        getline(file, junk, '"');
        do {
            getline(file, actor[numActors], '"');
            numActors++;
        } while (getline(file, junk, '"'));
        file.ignore(1);
        //the implementation will look nearly identical to the genres list
        
        //continue reading with getline until the end of the line
        
        //Create a temporary movie object and pass in the stored variables we read from the file using either the parameterized constructor or setters
        Movie temp(title, director, description, actor, genres, year, runtime, rating, numActors, numGenres);
        movies[count] = temp;
        count++;
    }

    return count;
}

void bubbleSortSelection(int userChoice, Genre &genreObject){
    //bubble sort is a common sorting algorithm
    //you are free to find an implementation online and converting it for use here
    bool swapped;
    int num = genreObject.getNumMoviesInGenre();
    Movie* movies = genreObject.getMoviesOfGenre();
    //a swap method has been implemented to make swapping movies in the array easier
    switch (userChoice) {
        case 1:
            for (int i = 0; i < num - 1; i++) {
                swapped = false;
                for (int j = 0; j < num - i - 1; j++) {
                    if(movies[j].getTitle().compare(movies[j+1].getTitle()) > 0) {
                        swap(movies[j], movies[j+1]);
                        swapped = true;
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < num - 1; i++) {
                swapped = false;
                for (int j = 0; j < num - i - 1; j++) {
                    if (movies[j].getYear() > movies[j+1].getYear()) {
                        swap(movies[j], movies[j+1]);
                        swapped = true;
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < num - 1; i ++) {
                swapped = false;
                for (int j = 0; j < num - i - 1; j++) {
                    if (movies[j].getRating() > movies[j+1].getRating()) {
                        swap(movies[j], movies[j+1]);
                        swapped = true;
                    }
                }
            }
        
        break;
        default:
            cout << "Invalid Choice! " << endl;
            break;
        
            
    }
    //you will need three implementations of the bubble sort
    //one will be for sorting alphabetically by title
    //one will be for sorting numerically by year (earliest year first)
    //one will be for sorting numerically by rating (highest rating first)
    //if there is a tie in the numerical sorts, break the tie using alphabetically by title

    //recommend using a switch statement here but if statements will work
}


Genre constructGenre(Movie* movies, int numMovies, string genreName){
    //This function is designed to take an option from the user and construct a genre object with all movies that have that particular genre in their list
    //for example, if the user selects action, all movies with the action genre will be added to the object

    //create a new movie array
    Movie Movies[500];
    //create a new integer counter to keep track of the number of movies in this genre
    int genreCount = 0;
    //you will use a nested for loop
    //the outside for loop will go through the entire list of movies read from the csv
    //the inside for loop will go through the list of genres per movie
    //each iteration of this inside for loop will check if the genre for that movie is equal to the genreName variable
    //if it is, add it to the newly created movie array
    //if not, skip
    //each succesfully added movie ups the count by one
    for (int i = 0; i < numMovies; i++) {
        for (int j = 0; j < movies[i].getGenreCount(); j++){
            if (movies[i].getGenres()[j] == genreName) {
                Movies[genreCount] = movies[i];
                genreCount++;
                // Temp break if we find the match
                break;
            }
        }
    }
    
    //create a new genreobject with the created array and the generated count
    //return this genreobject
    Genre genreObj(genreName, Movies, genreCount);
    return genreObj;

}