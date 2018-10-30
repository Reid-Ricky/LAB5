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
    UtPod rickys(256);
    cout << "Ut Pod [rickys UtPod]  " << endl;
    cout << "memory capacity - " << rickys.getTotalMemory() << endl << endl;

    cout << "populating the UtPod with music ~~ " << endl;
    Song s1;
    s1.setTitle("Hey Jude");
    s1.setArtist("Beatles");
    s1.setSize(4);
    int result = rickys.addSong(s1);
    cout << "result of adding " << s1.getTitle() << " : " << result << endl;
    cout << "song added ~ memory left = " << rickys.getRemainingMemory() << endl << endl;
    Song s2("The Hills", "The Weeknd", 15);
    result = rickys.addSong(s2);
    cout << "result of adding " << s2.getTitle() << " : " << result << endl;
    cout << "song added ~ memory left = " << rickys.getRemainingMemory() << endl << endl;
    Song s3("Red Roses", "Beatles", 64);
    result = rickys.addSong(s3);
    cout << "result of adding " << s3.getTitle() << " : " << result << endl;
    cout << "song added ~ memory left = " << rickys.getRemainingMemory() << endl << endl;
    Song s4("RERUN", "Quavo ft. Travis Scott", 7);
    result = rickys.addSong(s4);
    cout << "result of adding " << s4.getTitle() << " : " << result << endl;
    cout << "song added ~ memory left = " << rickys.getRemainingMemory() << endl << endl;
    Song s5("Mo Bamba", "Sheck Wes", 28);
    result = rickys.addSong(s5);
    cout << "result of adding " << s5.getTitle() << " : " << result << endl;
    cout << "song added ~ memory left = " << rickys.getRemainingMemory() << endl << endl;
    Song s6("Texas Fight", "The University of Texas Longhorn Band", 138);
    result = rickys.addSong(s6);
    cout << "result of adding " << s6.getTitle() << " : " << result << endl;
    cout << "song added ~ memory left = " << rickys.getRemainingMemory() << endl << endl;
    Song sOVERFLOW("Purple Rain", "Prince", 1);
    result = rickys.addSong(sOVERFLOW);
    cout << "result of adding " << sOVERFLOW.getTitle() << " : " << result << endl;
    cout << "song was not able to be added";
    cout << "\n\n--------------------------------\n";


    cout << "Ut Pod [rickys UtPod] " << endl;
    cout << "Songs stored in UtPod :\n\n";
    rickys.showSongList();
    cout << "\n--------------------------------\n";
    cout << "Ut Pod [rickys UtPod] " << endl;
    cout << "SHUFFLING SONGS**\n" << endl;
    cout << "Shuffled songs : ";
    rickys.shuffle();
    rickys.showSongList();
    cout << "\n--------------------------------\n";
    rickys.~UtPod();

//-----------------------------------------------------------------------------------------------------------------


    UtPod reids;
    cout << "Ut Pod [reids UtPod]  " << endl;
    cout << "memory capacity - " << reids.getTotalMemory() << endl << endl;
    //
    cout << "populating the UtPod with music ~~ " << endl;
    Song s7("Never Change", "NAV", 80);
    result = reids.addSong(s7);
    //
    cout << "song added ~ memory left = " << reids.getRemainingMemory() << endl;
    Song s8("I Love It", "Kanye West & Lil Pump", 25);
    result = reids.addSong(s8);
    cout << "song added ~ memory left = " << reids.getRemainingMemory() << endl;
    //
    Song s9("Hurt Feelings", "Mac Miller", 70);
    result = reids.addSong(s9);
    cout << "song added ~ memory left = " << reids.getRemainingMemory() << endl;
    //
    Song s10("Know Yourself", "Drake", 63);
    result = reids.addSong(s10);
    cout << "song added ~ memory left = " << reids.getRemainingMemory() << endl;
    //
    Song s11("GHOST", "Jaden Smith", 14);
    result = reids.addSong(s11);
    cout << "song added ~ memory left = " << reids.getRemainingMemory() << endl;
    //
    Song s12("Cough Syrup", "Young the Giant", 80);
    result = reids.addSong(s12);
    cout << "song added ~ memory left = " << reids.getRemainingMemory() << endl;
    //
    cout << "\n--------------------------------\n";
    cout << "Ut Pod [rickys UtPod] " << endl;
    cout << "Songs stored in UtPod :\n\n";
    reids.showSongList();
    cout << "\n--------------------------------\n";
    cout << "Ut Pod [reids UtPod]  " << endl;
    cout << "Sorting Songs~~" << endl;
    reids.sortSongList();
    cout << "Sorted Songs: " << endl << endl;
    reids.showSongList();
    cout << "\n--------------------------------\n";


    cout << "Ut Pod [reids UtPod]  " << endl;
    cout << "Adding three new songs~~ " << endl<< endl;
    Song s13("Feel So Close", "Calvin Harris", 43);
    result = reids.addSong(s13);
    cout << "song added ~ memory left = " << reids.getRemainingMemory() << endl;
    Song s14("Sour Patch Kids", "Bryce Vine", 102);
    result = reids.addSong(s14);
    cout << "song added ~ memory left = " << reids.getRemainingMemory() << endl;
    /*
    Song s15("Yeah Right", "Vince Staples", 55);
    result = reids.addSong(s15);
    cout << "song added ~ memory left = " << reids.getRemainingMemory() << endl;
     */
    cout << "Songs added : " << endl << endl;
    cout << '"' << s13.getTitle() << '"' << " by " << s13.getArtist() << endl << endl;
    cout << '"' << s14.getTitle() << '"' << " by " << s14.getArtist() << endl << endl;
   // cout << '"' << s15.getTitle() << '"' << " by " << s15.getArtist() << endl;


    cout << "\n--------------------------------\n";
    cout << "Ut Pod [reids UtPod]  " << endl;
    cout << "removing " << '"' << s7.getTitle() << '"' << " by " << s7.getArtist() <<   endl;
    reids.removeSong(s7);
    cout << "new list of songs: " << endl;
    reids.showSongList();
    cout << "\n--------------------------------\n";














}