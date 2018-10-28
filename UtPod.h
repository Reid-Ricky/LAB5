//UtPod.h
//
//UtPod Header program
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


#ifndef UTPOD_H
#define UTPOD_H

#include "song.h"

using namespace std;

//UtPod class declaration
class UtPod {
   private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;
      
      struct SongNode {
         Song s;
         SongNode *next;
      };
      SongNode *songs;  //the head pointer
      int memSize; //memory size

      //FUNCTION - numSongs
      // counts the number of songs in the UtPod
      // returns the sum
      // input parms - NONE
      // output parms - Total songs
      int numSongs();

   public:
      //Default constructor
      // set the memory size to MAX_MEMORY
      UtPod();

      //Constructor with size parameter
      // The user of the class will pass in a size.
      // If the size is greater than MAX_MEMORY or less than or equal to 0,
      // set the memory size to MAX_MEMORY.
      UtPod(int size);

      //FUNCTION - addSong
      // attempts to add a new song to the UtPod
      // returns 0 if successful
      // returns -1 if not enough memory to add the song
      // precondition: s is a valid Song
      // input parms - Song to be added
      // output parms - Error Code (0 or -1)
      int addSong(Song const &s);

      //FUNCTION - removeSong
      // attempts to remove a song from the UtPod
      // removes the first instance of a song that is in the the UtPod multiple times
      // returns 0 if successful
      // returns -2 if not found
      // input parms - Song to be removed
      // output parms -  Error Code (0 or -2)
      int removeSong(Song const &s);

      //FUNCTION - shuffle
      // shuffles the songs into random order
      // will do nothing if there are less than two songs in the current list
      // input parms - NONE
      // output parms - NONE
      void shuffle();

      //FUNCTION - showSongList
      // prints the current list of songs in order from first to last to standard output
      // format - Title, Artist, size in MB (one song per line)
      // input parms - NONE
      // output parms - NONE
      void showSongList();

      //FUNCTION - sortSongList
      // sorts the songs in ascending order
      // will do nothing if there are less than two songs in the current list
      // input parms - NONE
      // output parms - NONE
      void sortSongList();

      //FUNCTION - clearMemory
      // clears all the songs from memory
      // input parms - NONE
      // output parms - NONE
      void clearMemory();

      //FUNCTION - getTotalMemory
      // returns the total amount of memory in the UtPod
      // will do nothing if there are less than two songs in the current list
      // input parms - NONE
      // output parms - Total memory
      int getTotalMemory();

      //FUNCTION - getRemainingMemory
      // returns the amount of memory available for adding new songs
      // input parms - NONE
      // output parms - Available memory
      int getRemainingMemory();

      //Destructor
      // clear memory and set the memory size to NO_MEMORY
      ~UtPod();
};


#endif