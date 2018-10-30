//UtPod.cpp
//
//UtPod program
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

#include <iostream>
#include <ctime>
#include <cstdlib>   
#include "UtPod.h"
#include "song.h"

using namespace std;

//Default constructor
// set the memory size to MAX_MEMORY
UtPod::UtPod() {
   songs = NULL;
   memSize = MAX_MEMORY;
}

//Constructor with size parameter
// The user of the class will pass in a size.
// If the size is greater than MAX_MEMORY or less than or equal to 0,
// set the size to MAX_MEMORY.
UtPod::UtPod(int size) {
   songs = NULL;
   if (size <= 0 || size > MAX_MEMORY) {
      memSize = MAX_MEMORY;
   } else {
      memSize = size;
   }
}

//FUNCTION - numSongs
// counts the number of songs in the UtPod
// returns the sum
// input parms - NONE
// output parms - Total songs
int UtPod::numSongs() {
   int total = 0;
   SongNode* nodePointer = songs;
   while (nodePointer != NULL) {
      total++;
      nodePointer = nodePointer->next;
   }
   return total;
}

//FUNCTION - addSong
// attempts to add a new song to the UtPod
// returns 0 if successful
// returns -1 if not enough memory to add the song
// precondition: s is a valid Song
// input parms - Song to be added
// output parms - Error Code (0 or -1)
int UtPod::addSong(Song const &s) {
   if ((getRemainingMemory() - s.getSize()) <= NO_MEMORY) {
      return NO_MEMORY;
   } else {
      SongNode* newNode = new SongNode;
      newNode->s = s;
      newNode->next = songs;
      songs = newNode;
      return SUCCESS;
   }
}

//FUNCTION - removeSong
// attempts to remove a song from the UtPod
// removes the first instance of a song that is in the the UtPod multiple times
// returns 0 if successful
// returns -2 if not found
// input parms - Song to be removed
// output parms -  Error Code (0 or -2)
int UtPod::removeSong(Song const &s) {
   if (getRemainingMemory() == memSize) {
      return NOT_FOUND;
   } else {
      bool found = false;
      SongNode* prevNode = songs;
      SongNode* currentNode = songs;
      while (currentNode != NULL && !found) {
         if (currentNode->s == s) {
            SongNode* bufferNode = currentNode;
            if (currentNode != prevNode) {
               prevNode->next = currentNode->next;
            } else {
               //VERY FIRST INSTANCE
               songs = currentNode->next;
            }
            delete bufferNode;
            found = true;
         } else {
            prevNode = currentNode;
            currentNode = currentNode->next;
         }
      }
      if (!found) {
         return NOT_FOUND;
      } else {
         return SUCCESS;
      }
   }
}

//FUNCTION - shuffle
// shuffles the songs into random order
// will do nothing if there are less than two songs in the current list
// input parms - NONE
// output parms - NONE
void UtPod::shuffle() {
   if (numSongs() >= 2) {
      unsigned int currentTime = (unsigned) time(0);
      srand(currentTime);
      SongNode *ptr1 = NULL;
      SongNode *ptr2 = NULL;
      SongNode *nodePointer;
      Song temp;

      //COMMENT HEREEEEEEEEEE
      bool run1;
      bool run2;
      int randLength1 = 0;
      int randLength2 = 0;
      int index = 0;
      for (int i = 0; i < 50; i++) {
         run1 = true;
         run2 = true;
         index = 0;
         nodePointer = songs;
         randLength1 = (rand() % numSongs()); //index of swapees
         randLength2 = (rand() % numSongs()); //index of swapees

         while (run1 || run2) {
            if (index == randLength1 && run1) {
               ptr1 = nodePointer;
               run1 = false;
            }
            if (index == randLength2 && run2) {
               ptr2 = nodePointer;
               run2 = false;
            }
            index++;
            nodePointer = nodePointer->next;
         }

         temp = ptr1->s;
         ptr1->s = ptr2->s;
         ptr2->s = temp;
      }
   }
}

//FUNCTION - showSongList
// prints the current list of songs in order from first to last to standard output
// format - Title, Artist, size in MB (one song per line)
// input parms - NONE
// output parms - NONE
void UtPod::showSongList() {
   if (getRemainingMemory() == memSize) {
      cout << "\n";
   } else {
      SongNode* nodePointer = songs;
      while (nodePointer != NULL) {
         cout << '"' << nodePointer->s.getTitle() << '"' << " by " << nodePointer->s.getArtist() << "\n\n";
         nodePointer = nodePointer->next;
      }
   }
}

//FUNCTION - sortSongList
// sorts the songs in ascending order
// will do nothing if there are less than two songs in the current list
// input parms - NONE
// output parms - NONE
void UtPod::sortSongList() {
   SongNode* nodePointer;
   SongNode* nextPointer;
   Song temp;
   if (numSongs() >= 2) {
      for (int i = 0; i < numSongs(); i++) {
         nodePointer = songs;
         nextPointer = songs->next;
         for (int j = 0; (j < numSongs() - 1); j++) {
            if (nodePointer->s > nextPointer->s) {
               temp = nodePointer->s;
               nodePointer->s = nextPointer->s;
               nextPointer->s = temp;
            }
            nodePointer = nodePointer->next;
            nextPointer = nextPointer->next;
         }
      }
   }
}

//FUNCTION - clearMemory
// clears all the songs from memory
// input parms - NONE
// output parms - NONE
void UtPod::clearMemory() {
   SongNode *ptr = songs;
   while (songs  != NULL) {
      ptr = songs;
      songs = songs->next;
      delete ptr;
   }
}

//FUNCTION - getTotalMemory
// returns the total amount of memory in the UtPod
// will do nothing if there are less than two songs in the current list
// input parms - NONE
// output parms - Total memory
int UtPod::getTotalMemory() {
   return memSize;
}

//FUNCTION - getRemainingMemory
// returns the amount of memory available for adding new songs
// input parms - NONE
// output parms - Available memory
int UtPod::getRemainingMemory() {
   SongNode *ptr = songs;
   int curr_mem_used =0;
   while (ptr != NULL) {
      curr_mem_used += ptr->s.getSize();
      ptr = ptr->next;
   }
   return (memSize - curr_mem_used);
}

//Destructor
// clear memory and set the memory size to NO_MEMORY
UtPod::~UtPod() {
   clearMemory();
   memSize = NO_MEMORY;
}