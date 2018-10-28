//song.h
//
//Song Header program
//Reid Lindemann & Ricky Guzman 10/18/2018
//EE 312

/* Student information for project:
 *
 * On my honor, Reid Lindemann and Ricky Guzman, this programming project is our own work
 * and I have not provided this code to any other student.
 *
 * Name: Reid Lindemann
 * email address: lindemannreid@yahoo.com
 * UTEID: rhl542
 * Section 5 digit ID: 16200
 *
 */

#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;

//USong class declaration
class Song {
      
  private:
    string title;
    string artist;
    int size;
 
  public:
    //Default constructor
    Song();

    //Constructor with title, artist, size parameters
    // The user of the class will pass in a title, artist, and size
    // If the variables passed in are valid, the variables will be initialized accordingly
    // If the variables are not valid, there will no initializations and an error message
    Song(string _title, string _artist, int _size);

    //GETTERS
    string getTitle() const;
    string getArtist() const;
    int getSize() const;

    //SETTERS
    void setTitle(string _title);
    void setArtist(string _artist);
    void setSize(int _size);

    //OPERATORS

    //Equality Operator
    // returns true if all variables (title, artist, size) are equal
    // returns false otherwise
    bool operator ==(Song const &rhs);

    //Less Than Operator
    // returns true if the variables of this song are less than the variables
    //  of the rhs song in the order of artist, then title, then size
    // returns false otherwise
    bool operator <(Song const &rhs);

    //Greater Than Operator
    // returns true if the variables of this song are greater than the variables
    //  of the rhs song in the order of artist, then title, then size
    // returns false otherwise
    bool operator >(Song const &rhs);
};

#endif
