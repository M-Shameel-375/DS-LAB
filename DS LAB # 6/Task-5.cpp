#include <iostream>
#include <string>
using namespace std;

class SongNode
{
public:
    string songName;
    SongNode *prev;
    SongNode *next;

    SongNode(string name)
    {
        songName = name;
        prev = nullptr;
        next = nullptr;
    }
};

class Playlist
{
private:
    SongNode *head;
    SongNode *tail;

public:
    Playlist()
    {
        head = nullptr;
        tail = nullptr;
    }

    void addSongToEnd(string songName)
    {
        SongNode *newSong = new SongNode(songName);
        if (!head)
        {
            head = tail = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << "Added song: " << songName << endl;
        printPlaylist();
    }

    void traverseForward()
    {
        cout << "Playlist (Forward): ";
        SongNode *temp = head;
        while (temp)
        {
            cout << temp->songName << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void traverseBackward()
    {
        cout << "Playlist (Backward): ";
        SongNode *temp = tail;
        while (temp)
        {
            cout << temp->songName << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void deleteSong(string songName)
    {
        SongNode *temp = head;

        while (temp)
        {
            if (temp->songName == songName)
            {
                if (temp == head)
                {
                    head = temp->next; 
                    if (head)
                        head->prev = nullptr; 
                }
                else
                {
                    temp->prev->next = temp->next; 
                }

                if (temp == tail)
                {
                    tail = temp->prev; 
                    if (tail)
                        tail->next = nullptr; 
                }
                else
                {
                    if (temp->next)
                        temp->next->prev = temp->prev; 
                }

                delete temp;
                cout << "Deleted song: " << songName << endl;
                printPlaylist();
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found: " << songName << endl;
    }

    
    void printPlaylist()
    {
        cout << "Current Playlist: ";
        SongNode *temp = head;
        while (temp)
        {
            cout << temp->songName << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Playlist()
    {
        while (head)
        {
            SongNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    Playlist myPlaylist;
    string songName, del;
    char c;

    while (true)
    {
        cout << "\nEnter the song name: ";
        getline(cin, songName);
        myPlaylist.addSongToEnd(songName);

        cout << "Do you want to add another song? (y/n): ";
        cin >> c;     
        cin.ignore(); 

        if (c == 'N' || c == 'n')
        {
            break; 
        }
    }

    myPlaylist.traverseForward();
    myPlaylist.traverseBackward();

    cout << "Enter the song name do you want to delete : " << endl;
    getline(cin, del);
    myPlaylist.deleteSong(del);

    myPlaylist.traverseForward();

    return 0;
}
