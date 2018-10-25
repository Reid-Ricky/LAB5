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
      
      int memSize;

      int numSongs();

   public:
      UtPod();
      UtPod(int size);
      
      int addSong(Song const &s);
      int removeSong(Song const &s);
      void shuffle();
      void showSongList();
      void sortSongList(); 
      
      int getTotalMemory() {
         return memSize;
      }
      
      int getRemainingMemory();

      ~UtPod();
 
};


#endif