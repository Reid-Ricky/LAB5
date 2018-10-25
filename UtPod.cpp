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

//TEST********IDK WHERE THIS GOES****************
int UtPod::numSongs() {
   int total = 0;
   SongNode* nodePointer = songs;
   while (nodePointer != NULL) {
      total++;
      nodePointer = nodePointer->next;
   }
   return total;
}

//TEST
UtPod::UtPod() {
   songs = NULL;
   memSize = 0;
}

//TEST
UtPod::UtPod(int size) {
   songs = NULL;
   if (size <= 0 || size > MAX_MEMORY) {
      memSize = 0;
   } else {
      memSize = size;
   }
}

//TEST
int UtPod::addSong(Song const &s) {
   if ((memSize + s.getSize()) > MAX_MEMORY) {
      return NO_MEMORY;
   } else {
      SongNode* newNode = new SongNode;
      newNode->s = s;
      newNode->next = songs;
      songs = newNode;
      memSize = memSize + s.getSize();
      return SUCCESS;
   }
}

//TEST
int UtPod::removeSong(Song const &s) {
   if (memSize == NO_MEMORY) {
      return NO_MEMORY;
   } else {
      bool found = false;
      SongNode* prevNode = songs;
      SongNode* currentNode = songs;
      while (currentNode != NULL && !found) {
         if (currentNode->s == s) {
            memSize = memSize - currentNode->s.getSize();
            SongNode* bufferNode = currentNode;
            if (currentNode != prevNode) {
               prevNode->next = currentNode->next;
               //currentNode = currentNode->next;
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

//TEST
void UtPod::shuffle() {
   unsigned int currentTime = (unsigned) time(0);
   srand(currentTime);
   SongNode *ptr1;
   SongNode *ptr2;
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
      randLength1 = (rand() % numSongs());
      randLength2 = (rand() % numSongs());
      
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

//TEST
void UtPod::showSongList() {
   if (memSize == NO_MEMORY) {
      cout << "\n";
   } else {
      SongNode* nodePointer = songs;
      while (nodePointer != NULL) {
         cout << nodePointer->s.getTitle() << " by " << nodePointer->s.getArtist() << "\n";
         nodePointer = nodePointer->next;
      }
   }
}

//INCOMPLETE
void UtPod::sortSongList() {
   //sort
}
  
//TEST
int UtPod::getRemainingMemory() {
   return (MAX_MEMORY - memSize);
}

//TEST
UtPod::~UtPod() {
   SongNode *ptr = songs;
   while (songs  != NULL) {
      ptr = songs;
      songs = songs->next;
      delete ptr;
   }
}