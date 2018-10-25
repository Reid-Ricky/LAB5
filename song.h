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
   Song();
   Song(string _title, string _artist, int _size);
   
   string getTitle() const;
   string getArtist() const;
   int getSize() const;
   bool operator == (Song const &rhs);
};

#endif
