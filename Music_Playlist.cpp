#include <iostream>
#include <string>

using namespace std;

// Node class modified to represent a song
class Node {
public:
    string songTitle;
    string artistName;
    Node* prev; // prev pointer to navigate to the previous song
    Node* next; // next pointer to navigate to the next song

    Node(string title, string artist) {
        songTitle = title;
        artistName = artist;
        prev = nullptr;
        next = nullptr;
    }
};

class MusicPlaylistManager {
private:
    Node* head;    // head points to the first node (first song) in the playlist
    Node* current; // current points to the currently selected/playing song

public:
    MusicPlaylistManager() {
        head = nullptr;
        current = nullptr;
    }

    // 1. Add Song
    void addSong(string title, string artist) {
        Node* p = new Node(title, artist); // p is used to point to a newly allocated node
        
        if (head == nullptr) {
            head = p;
            current = head; 
        } else {
            Node* q = head; // q is used as the navigation/traversal pointer
            while (q->next != nullptr) {
                q = q->next;
            }
            q->next = p;
            p->prev = q;
        }
        cout << "Added: " << title << " by " << artist << "\n";
    }

    // 2. Delete Song
    void deleteSong(string title) {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* q = head; // q is used as the navigation pointer
        
        // Deleting the first song
        if (q->songTitle == title) {
            Node* p = head; // p is used for the node to be deleted
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            if (current == p) {
                current = head; // Reassign current if it was pointing to the deleted song
            }
            delete p;
            cout << "Deleted: " << title << "\n";
            return;
        }

        // Deleting from middle or end
        while (q->next != nullptr) {
            if (q->next->songTitle == title) {
                Node* p = q->next; // p points to the node to be deleted
                q->next = p->next;
                if (p->next != nullptr) {
                    p->next->prev = q;
                }
                if (current == p) {
                    current = q; // Reassign current if deleted
                }
                delete p;
                cout << "Deleted: " << title << "\n";
                return;
            }
            q = q->next;
        }
        cout << "Song '" << title << "' not found in the playlist.\n";
    }

    // 3. Display Playlist
    void displayPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* q = head;
        cout << "Playlist (Forward):\n";
        while (q != nullptr) {
            cout << " - " << q->songTitle << " by " << q->artistName;
            if (q == current) cout << " [CURRENT]";
            cout << "\n";
            q = q->next;
        }
    }

    // 4. Display Playlist in Reverse
    void displayPlaylistReverse() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* q = head;
        // Move q to the last node
        while (q->next != nullptr) {
            q = q->next;
        }
        cout << "Playlist (Reverse):\n";
        while (q != nullptr) {
            cout << " - " << q->songTitle << " by " << q->artistName << "\n";
            q = q->prev;
        }
    }

    // 5. Play Current Song
    void playCurrentSong() {
        if (current == nullptr) {
            cout << "No song is currently selected.\n";
            return;
        }
        cout << "Playing: " << current->songTitle << " by " << current->artistName << "\n";
    }

    // 6. Play Next Song
    void playNextSong() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        if (current->next != nullptr) {
            current = current->next; // Move to Next Song
            cout << "Moved to Next. ";
            playCurrentSong();
        } else {
            cout << "You are at the end of the playlist. No next song.\n";
        }
    }

    // 7. Play Previous Song
    void playPreviousSong() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        if (current->prev != nullptr) {
            current = current->prev; // Move to Previous Song
            cout << "Moved to Previous. ";
            playCurrentSong();
        } else {
            cout << "You are at the beginning of the playlist. No previous song.\n";
        }
    }

    // 8. Play Complete Playlist
    void playCompletePlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* q = head;
        cout << "Playing complete playlist:\n";
        while (q != nullptr) {
            cout << " > " << q->songTitle << " by " << q->artistName << "\n";
            q = q->next;
        }
    }

    // 9. Repeat All
    void repeatAll(int repetitions) {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        for (int i = 1; i <= repetitions; i++) {
            cout << "--- Repetition " << i << " ---\n";
            playCompletePlaylist();
        }
    }

    // 10. Show Current Song
    void showCurrentSong() {
        if (current == nullptr) {
            cout << "No current song.\n";
        } else {
            cout << "Current Selection: " << current->songTitle << " by " << current->artistName << "\n";
        }
    }
};

int main() {
    MusicPlaylistManager playlist;
    int choice;
    string title, artist;
    int reps;

    do {
        cout << "\n--- Music Playlist Manager ---\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Display Playlist in Reverse\n";
        cout << "5. Play Current Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Play Complete Playlist\n";
        cout << "9. Repeat All\n";
        cout << "10. Show Current Song\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter Song Title: ";
                getline(cin, title);
                cout << "Enter Artist Name: ";
                getline(cin, artist);
                playlist.addSong(title, artist);
                break;
            case 2:
                cout << "Enter Song Title to Delete: ";
                getline(cin, title);
                playlist.deleteSong(title);
                break;
            case 3:
                playlist.displayPlaylist();
                break;
            case 4:
                playlist.displayPlaylistReverse();
                break;
            case 5:
                playlist.playCurrentSong();
                break;
            case 6:
                playlist.playNextSong();
                break;
            case 7:
                playlist.playPreviousSong();
                break;
            case 8:
                playlist.playCompletePlaylist();
                break;
            case 9:
                cout << "Enter number of repetitions: ";
                cin >> reps;
                playlist.repeatAll(reps);
                break;
            case 10:
                playlist.showCurrentSong();
                break;
            case 11:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 11);

    return 0;
}
//output
PS C:\Users\DELL\Downloads\Narendra 228> g++ Music_Playlist.cpp -o Music_playlist.exe
PS C:\Users\DELL\Downloads\Narendra 228> ./Music_playlist.exe

--- Music Playlist Manager ---
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 1
Enter Song Title: tu hi to yaar mera 
Enter Artist Name: arijit singh
Added: tu hi to yaar mera  by arijit singh

--- Music Playlist Manager ---
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 2
Enter Song Title to Delete: tu hi to yaar mera
Song 'tu hi to yaar mera' not found in the playlist.

--- Music Playlist Manager ---
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
