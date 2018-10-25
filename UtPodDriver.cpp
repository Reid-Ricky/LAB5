//UtPodDriver.cpp
//
//UtPod Driver program
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

#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    cout << "HELLOOOOO\n\n";

    Song s1("Hey Jude1", "Beatles", 4);
    cout << s1.getTitle() << "\n";
    cout << s1.getArtist() << "\n";
    cout << s1.getSize() << "\n";
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << "memory = " << t.getRemainingMemory() << endl;

    cout << "\n---------------------\n\n";

    Song s2("Hey Jude2", "Beatles", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << "memory = " << t.getRemainingMemory() << endl;

    cout << "\n---------------------\n\n";

    Song s3("Hey Jude3", "Beatles", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    cout << "memory = " << t.getRemainingMemory() << endl;
       
    Song s4("Hey Jude4", "Beatles", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    cout << "memory = " << t.getRemainingMemory() << endl;
       
    Song s5("Hey Jude5", "Beatles", 241);
    result = t.addSong(s5);
    cout << "result = " << result << endl;
    
    t.showSongList();
    cout << "\n---------------------\n\n";

    cout << "memory = " << t.getRemainingMemory() << endl;

    t.shuffle();
    t.showSongList();
    cout << "\n---------------------\n\n";
    t.shuffle();
    t.showSongList();

    cout << "\n---------------------\n\n";

    Song s6("Hey Jude6", "Beatles", 400);
    result = t.addSong(s6);
    cout << "result = " << result << endl;

    cout << "memory = " << t.getRemainingMemory() << endl;

    cout << "\n---------------------\n\n";

    t.showSongList();
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
    t.showSongList();

    cout << "\n---------------------\n\n";

    t.showSongList();
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
    t.showSongList();

    cout << "\n---------------------\n\n";

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
    t.showSongList();

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    t.showSongList();
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

}