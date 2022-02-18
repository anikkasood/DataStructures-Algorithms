//
//  Playlist.cpp
//  cs10c-Lab1
//
//  Created by Anika Sood on 1/11/22.
//

#include "Playlist.h"
#include <iostream>
using namespace std;

/*  _______________ CONSTRUCTORS () _______________  */
PlaylistNode::PlaylistNode(){

    //default constructor initialization
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;

}

PlaylistNode::PlaylistNode(string ID, string SN, string AN, int SL){ //parameterized constructor
    uniqueID = ID;
    songName = SN;
    artistName = AN;
    songLength = SL;
    nextNodePtr = nullptr;
}

/*  _______________ INSERT AFTER () _______________  */

void PlaylistNode::InsertAfter(PlaylistNode* toAdd){ //add to end of list
    PlaylistNode* tmpNext = nullptr;

    tmpNext = this->nextNodePtr;    // Remember next
    this->nextNodePtr = toAdd;    // this -- node -- ?
    toAdd->nextNodePtr = tmpNext; // this -- node -- next

}

/*  _______________ SET NEXT () _______________  */
void PlaylistNode::SetNext(PlaylistNode* toSet){ //insert after specified node

    nextNodePtr = toSet;

}

/*  _______________ PRINT PLAYLIST NODE () _______________  */

void PlaylistNode::PrintPlaylistNode() const{ //print the playlist node

    /*Unique ID: S123
     Song Name: Peg
     Artist Name: Steely Dan
     Song Length (in seconds): 237*/
    cout<<"Unique ID: "<<uniqueID<<"\n";
    cout<<"Song Name: "<<songName<<"\n";
    cout<<"Artist Name: "<<artistName<<"\n";
    cout<<"Song Length (in seconds): "<<songLength<<"\n\n";
}


/*  _______________ GETTERS () _______________  */

string PlaylistNode::GetID() const{//return ID
    return uniqueID;
}


string PlaylistNode::GetSongName() const{ //return song name
    return songName;
}

string PlaylistNode::GetArtistName() const{//return artist name
    return artistName;
}

int PlaylistNode::GetSongLength() const{ //return song length
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const{ //return next node pointer
    return nextNodePtr;
}




