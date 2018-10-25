//song.cpp
//
//Song program
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


#include "song.h"
#include <cstdlib>
#include <iostream>

using namespace std;

//TEST
Song::Song() {
   title = "";
   artist = "";
   size = 0;
}

//TEST
Song::Song(string _title, string _artist, int _size) {
   if (_title != "" && _artist != "" && _size > 0) {
      title = _title;
      artist = _artist;
      size = _size;
   } else {
      cout << "error in constructor";
   }
}

//TEST
string Song::getTitle() const {
   return title;
}

//TEST
string Song::getArtist() const {
   return artist;
}

//TEST
int Song::getSize() const {
   return size;
}

bool Song::operator ==(Song const &rhs) {
   return (title == rhs.title && artist == rhs.artist && size == rhs.size);
}


