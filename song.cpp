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

//GETTERS
string Song::getTitle() const {
   return title;
}

string Song::getArtist() const {
   return artist;
}

int Song::getSize() const {
   return size;
}

//SETTERS
void Song::setTitle(string _title) {
   title = _title;
}

void Song::setArtist(string _artist) {
   artist = _artist;
}

void Song::setSize(int _size) {
   size = _size;
}

//OPERATORS
bool Song::operator ==(Song const &rhs) {
   return (title == rhs.title &&
           artist == rhs.artist &&
           size == rhs.size);
}

bool Song::operator <(Song const &rhs){
   if (artist < rhs.getArtist()) {
      return true;
   } else if (artist == rhs.getArtist()) {
      if (title < rhs.getTitle()) {
         return true;
      } else if (title == rhs.getTitle()){
         if (size < rhs.getSize()) {
            return true;
         } else {
            return false;
         }
      } else {
         return false;
      }
   } else {
      return false;
   }
}

bool Song::operator >(Song const &rhs){
   if (artist > rhs.getArtist()) {
      return true;
   } else if (artist == rhs.getArtist()) {
      if (title > rhs.getTitle()) {
         return true;
      } else if (title == rhs.getTitle()){
         if (size > rhs.getSize()) {
            return true;
         } else {
            return false;
         }
      } else {
         return false;
      }
   } else {
      return false;
   }
}
