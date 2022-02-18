#include <iostream>
#include "Playlist.h"

using namespace std;

class MyPlaylist{
public:
    //constructors
    MyPlaylist():name("none"), head(nullptr), tail(nullptr){};
    MyPlaylist(string nm):name(nm), head(nullptr), tail(nullptr){};
    
    string getName() const{
        return name;
    }
    
    //check if list empty
    bool empty() const{
        if(head == nullptr)
            return true;
        else
            return false;
    }
    
    
    //output the whole playlist
    void outputFullPlaylist() const{
        cout<<name<<" - OUTPUT FULL PLAYLIST\n";
        if(!empty()){
            PlaylistNode* curr = head;
            int num = 1;
            while(curr != nullptr){
                cout<<num<<".\n";
                num++;
                curr->PrintPlaylistNode();
                curr = curr->GetNext();
            }
        }
        else{
            cout<<"Playlist is empty\n\n";
        }
    }
    
   //output based on artist
    void outputArtist(string artist) const{
        if(!empty()){
            PlaylistNode* curr = head;
            int num = 1;
            while(curr != nullptr){
                if(artist == curr->GetArtistName()){
                    cout<<num<<".\n";
                    
                    curr->PrintPlaylistNode();
                }
                num++;
                curr = curr->GetNext();
            }
        }
        else{
            cout<<"Playlist is empty\n";
        }
    }
    
    //output total time
    void outputTime() const{
        if(!empty()){
            PlaylistNode* curr = head;
            int time = 0;
            while(curr != nullptr){
                time +=  curr->GetSongLength();
                curr = curr->GetNext();
            }
            
            cout<<"OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n";
            cout<<"Total time: "<<time<<" seconds\n\n";
        }
        else{
            cout<<"Playlist is empty\n";
        }
    }
    
    //add song
    void addSong(string ID, string SN, string AN, int SL){
        PlaylistNode* toAdd = new PlaylistNode(ID, SN, AN, SL);
        if(empty()){
            head = toAdd;
            tail = toAdd;
        }
        else{
            //find where to add in the list
            PlaylistNode* addAfter = head;
        
            //finding last position in list
            while(addAfter->GetNext() != nullptr){
                addAfter = addAfter->GetNext();
            }
            addAfter->InsertAfter(toAdd); //inserting element at the end of the list
        }
        
    }
    
    //remove song
    void removeSong(string ID){
        PlaylistNode* prev = head;
        string songName;
        if(prev->GetID() != ID){
            //traverse through & find node w id
            while(prev->GetNext()->GetID()!=ID && prev->GetNext() != nullptr){
                prev = prev -> GetNext();
            }
            if(prev->GetNext() == nullptr && prev->GetNext()->GetID()!= ID){ //ID not found
                cout<<"ID not found.\n";
                return;
            }
            else if(prev->GetNext() == nullptr && prev->GetNext()->GetID()== ID){ //remove last element
                songName = prev->GetNext()->GetSongName();
                delete tail;
                tail = prev;
                prev->SetNext(nullptr);
            }
            else{ //remove middle element
                songName = prev->GetNext()->GetSongName();
                PlaylistNode * temp = prev->GetNext()->GetNext();
                delete prev->GetNext();
                prev->SetNext(temp);
                
            }
        }
        else{ //remove first element
            songName = head->GetSongName();
            PlaylistNode* temp = head->GetNext();
            delete head;
            head = temp;
            
            if(empty()){
                tail = nullptr;
            }
        }
        cout<<"\""<<songName<<"\" removed.\n\n";
    }
    
    //change position
    void changePos(int currPos, int newPos){
        //find total nodes
        PlaylistNode* temp = head;
        int total = 1;
        while(temp)
        {
            temp = temp->GetNext();
            total ++;
        }
        
        //make sure newPos is valid
        if(newPos<1)
            newPos =1;
        if(newPos>total)
            newPos = total;
        
        //find nodes for the positions passed
        PlaylistNode* pos1Node = head;
        PlaylistNode* pos2Node = head;
        
        for(int i = 1; i<currPos; i++){
            pos1Node = pos1Node->GetNext();
        }
        for(int i = 1; i<newPos; i++){
            pos2Node = pos2Node->GetNext();
        }
        
        //check if we're moving up or down the list
        if(currPos < newPos){ //moving up the list
            if(pos1Node == head && pos2Node == tail){ //head moves after tail
                head = pos1Node->GetNext(); //set new head
                pos2Node->SetNext(pos1Node);//add pos1node to the end of list
                pos1Node->SetNext(nullptr); //set pos1node next to null
                tail = pos1Node; //set new tail
            }
            else if(pos1Node == head){//head moves after position in middle of list
                head = pos1Node->GetNext(); //set new head
                
                //add pos1node after pos2node
                pos1Node->SetNext(pos2Node->GetNext());
                pos2Node->SetNext(pos1Node);
            }
            else{ //moving pos1 after pos2 in middle of list
                //find element before pos1Node
                PlaylistNode* prev = head;
                while(prev->GetNext()!=pos1Node){
                    prev = prev->GetNext();
                }
                
                //add pos1Node after pos2Node
                prev->SetNext(pos1Node->GetNext());
                pos1Node->SetNext(pos2Node->GetNext());
                pos2Node->SetNext(pos1Node);
            }
        }
        else{ //moving down the list
            if(pos1Node == tail && pos2Node == head){ //tail moves after head
                //find element before pos1Node
                PlaylistNode* prev = head;
                while(prev->GetNext()!=pos1Node){
                    prev = prev->GetNext();
                }
                
                //adjust tail
                prev->SetNext(nullptr);
                tail = prev;
                
                //add pos1Node after head
                pos1Node->SetNext(pos2Node->GetNext());
                pos2Node->SetNext(pos1Node);
            }
            else if(pos1Node == tail){
                //find element before pos1Node
                PlaylistNode* prev = head;
                while(prev->GetNext()!=pos1Node){
                    prev = prev->GetNext();
                }
                
                //adjust tail
                prev->SetNext(nullptr);
                tail = prev;
                
                prev = head;
                while(prev->GetNext()!=pos2Node){
                    prev = prev->GetNext();
                }
                
                //add pos1 before pos2
                pos1Node->SetNext(pos2Node);
                prev->SetNext(pos1Node);
            }
            else{
                //find element before pos1Node
                PlaylistNode* prev = head;
                while(prev->GetNext()!=pos1Node){
                    prev = prev->GetNext();
                }
                
                PlaylistNode* prev2 = head;
                while(prev2->GetNext()!=pos2Node){
                    prev2 = prev2->GetNext();
                }
                //add pos1 before pos2
                prev->SetNext(pos1Node->GetNext());
                pos1Node->SetNext(pos2Node);
                prev2->SetNext(pos1Node);
            }
        }
        
        cout<<"\""<<pos1Node->GetSongName()<<"\" moved to position "<<newPos<<"\n\n";
    }
private:
    string name;
    PlaylistNode* head;
    PlaylistNode* tail;
    
    
};

/*------- EXECUTE CHOICE() -------*/
void ExecuteChoice(char choice, MyPlaylist &plist){
    switch(choice){
        case 'a': //add song{
            //get unique id, song name, artist name, song length
        {
            string ID, SN, AN;
            int SL;
            cin.ignore();
            cout<<"ADD SONG\n";
            cout<<"Enter song's unique ID:";
            getline(cin, ID);
            cout<<"\nEnter song's name:";
            getline(cin, SN);
            cout<<"\nEnter artist's name:";
            getline(cin, AN);
            cout<<"\nEnter song's length (in seconds):";
            cin>>SL;
            cout<<"\n\n";
            plist.addSong(ID, SN, AN, SL);
            break;
        }
        case 'd': //remove song
        {
            cin.ignore();
            string ID;
            cout<<"REMOVE SONG\nEnter song's unique ID:\n";
            getline(cin, ID);
            
            plist.removeSong(ID);
            break;
        }
        case 's': //output by artist
        {
            string AN;
            cin.ignore();
            cout<<"\nEnter artist's name:";
            getline(cin, AN);
            cout<<"\n\n";
            plist.outputArtist(AN);
            break;
        }
        case 't': //output total time
        {
            plist.outputTime();
            break;
        }
        case 'c'://change position
        {
            int pos1, pos2;
            cout<<"CHANGE POSITION OF SONG\nEnter song's current position:\n";
            cin>>pos1;
            cout<<"Enter new position for song:\n";
            cin>>pos2;
            plist.changePos(pos1, pos2);
            break;
        }
        case 'o': //output full playlist
        {
            plist.outputFullPlaylist();
            break;
        }
        case 'q': //quit
            break;
        default:
            cout<<"Invalid input. Enter the character corresponding to your choice. \n\n";
    }
}
/*------- PRINT MENU() -------*/
void PrintMenu(MyPlaylist &plist){

    //store user menu choice
    string choice;

    while(choice != "q"){
        cout<<plist.getName()<<" PLAYLIST MENU\n";
        cout<<"a - Add song\nd - Remove song\nc - Change position of song\ns - Output songs by specific artist\nt - Output total time of playlist (in seconds)\no - Output full playlist\nq - Quit\n\n";
        cout<<"Choose an option:";
        cin>>choice;
        cout<<"\n";

        //perform desired choice
        ExecuteChoice(choice.at(0), plist); //perform function desired
    }
    //while(choice != "q"); //repeat until user quits


}




/*------- MAIN() -------*/
int main(){

    string title;

    //get playlist title from user
    cout<<"Enter playlist's title:\n\n";
    getline(cin, title);

    MyPlaylist plist(title); //create struct instance

    //call the menu
    PrintMenu(plist);

    return 0;
}
