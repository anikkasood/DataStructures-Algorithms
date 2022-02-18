////
////  main.cpp
////  cs10c-Lab1
////
////  Created by Anika Sood on 1/11/22.
////
//
//#include <iostream>
//#include "Playlist.hpp"
//
//using namespace std;
//
///*  _______________ DECLARATIONS: PLIST & FUNCTIONS _______________  */
//class MyPlaylist{
//public:
//    //constructors
//    MyPlaylist():listName("none"), head(nullptr), tail(nullptr){};
//    MyPlaylist(string name):listName(name), head(nullptr), tail(nullptr){};
//    
//    /*  _______________ OUTPUT FULL LIST () _______________  */
//    void outputFullList(pList myPlaylist){
//        //traverse through whole list & display each node
//        if(myPlaylist.head != nullptr){
//            
//            //if it isn't an empty list
//            PlaylistNode *curr = myPlaylist.head;
//            int num = 1;
//            while(curr != nullptr){
//                cout<<num<<".\n";
//                curr->PrintPlaylistNode();
//                curr = curr->GetNext();
//            }
//        }
//        else{
//            cout<<"Playlist is empty\n";
//        }
//    }
//
//    /*  _______________ ADD SONG () _______________  */
//    void addSong(pList myPlaylist){
//        //get unique id, song name, artist name, song length
//        string ID, SN, AN;
//        int SL;
//        cin.ignore();
//        cout<<"Enter song's unique ID:";
//        getline(cin, ID);
//        cout<<"\nEnter song's name:";
//        getline(cin, SN);
//        cout<<"\nEnter artist's name:";
//        getline(cin, AN);
//        cout<<"\nEnter song's length (in seconds):";
//        cin>>SL;
//        
//        //create new node
//        PlaylistNode* node = new PlaylistNode(ID, SN, AN, SL);
//        myPlaylist.tail->InsertAfter(node);
//        myPlaylist.tail = node;
//        
//        
//        if(myPlaylist.head == nullptr){
//            myPlaylist.head = node;
//        }
//    }
//
//    /*  _______________ REMOVE SONG () _______________  */
//    void removeSong(pList myplaylist){
//        //get song ID from user
//        //find the node w/ that ID
//        //remove the node
//    }
//
//    /*  _______________ CHANGE POSITION OF SONG () _______________  */
//    void changeSongPosition(pList myplaylist){
//        //get current and desired position from user
//        //if not valid adjust desired position
//        //if head node move certain way
//        //if tail node move certain way
//        //else move certain way
//    }
//
//    /*  _______________ OUTPUT ARTIST SONGS () _______________  */
//    void outputArtistSongs(pList myList){
//        //get the artist name
//        //output nodes
//    }
//
//    /*  _______________ OUTPUT TOTAL TIME () _______________  */
//    void outputTotalTime(pList myList){
//        //time var to track total time
//        //traverse list and increment time var
//        //output total time
//    }
//
//private:
//    //track head and tail
//    string listName;
//    PlaylistNode *head;
//    PlaylistNode *tail;
//    
//};
//
////user interactions functions
//void PrintMenu(pList myPlaylist);
//void ExecuteChoice(char choice, pList myPlaylist);
//
////playlist management functions
//void outputFullList(pList myPlaylist);
//void removeSong(pList myPlaylist);
//void addSong(pList myPlaylist);
//void changeSongPosition(pList myplaylist);
//void outputArtistSongs(pList myPlaylist);
//void outputTotalTime(pList myPlaylist);
//
///*  _______________ MAIN () _______________  */
//int main(){
//    
//    string title;
//    
//    //get playlist title from user
//    cout<<"Enter playlist's title:\n\n";
//    getline(cin, title);
//    
//    pList myPlaylist(title); //create struct instance
//    
//    //call the menu
//    PrintMenu(myPlaylist);
//    
//    return 0;
//}
//
///*  _______________ PRINT MENU () _______________  */
//
//void PrintMenu(pList myPlaylist){
//    
//    //store user menu choice
//    char choice;
//    
//    do{
//        cout<<myPlaylist.listName<<" PLAYLIST MENU\n";
//        cout<<"a - Add song\nd - Remove song\nc - Change position of song\ns - Output songs by specific artist\nt - Output total time of playlist (in seconds)\no - Output full playlist\nq - Quit\n\n";
//        cout<<"Choose an option:";
//        cin>>choice;
//        cout<<"\n";
//        
//        //perform desired choice
//        ExecuteChoice(choice, myPlaylist); //perform function desired
//    }
//    while(choice != 'q'); //repeat until user quits
//    
//    
//}
//
///*  _______________ EXECUTE CHOICE () _______________  */
//void ExecuteChoice(char choice, pList myPlaylist){
//    switch(choice){
//        case 'a': //add song
//            addSong(myPlaylist);
//            break;
//        case 'd': //remove song
//            removeSong(myPlaylist);
//            break;
//        case 'c': //change position
//            changeSongPosition(myPlaylist);
//            break;
//        case 's': //output by artist
//            outputArtistSongs(myPlaylist);
//            break;
//        case 't': //output total time
//            outputTotalTime(myPlaylist);
//            break;
//        case 'o': //output full playlist
//            outputFullList(myPlaylist);
//            break;
//        case 'q': //quit
//            break;
//        default:
//            cout<<"Invalid input. Enter the character corresponding to your choice. \n\n";
//    }
//}
