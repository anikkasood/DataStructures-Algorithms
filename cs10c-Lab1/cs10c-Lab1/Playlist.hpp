//
//  Playlist.hpp
//  cs10c-Lab1
//
//  Created by Anika Sood on 1/11/22.
//
#ifndef Playlist_hpp
#define Playlist_hpp

#include <string>
using namespace std;

class PlaylistNode{
public:
    PlaylistNode(); //default constructor
    PlaylistNode(string ID, string SN, string AN, int SL); //parameterized constructor
    void InsertAfter(PlaylistNode*); //add after given node
    void SetNext(PlaylistNode*); //set next
    string GetID() const; //return ID
    string GetSongName() const; //return song name
    string GetArtistName() const; //return artist name
    int GetSongLength() const; //return song length
    PlaylistNode* GetNext() const; //return next node pointer
    void PrintPlaylistNode() const; //print the playlist node
private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};
#endif
