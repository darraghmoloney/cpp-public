/* This program uses deques and iterators
 * to implement a music-player style class
 * which displays the current song, can move
 * backwards and forwards in the playlist,
 * add new songs, etc.
 * 
 * This is a challenge from the Udemy Beginning
 * C++ course.
 * */


#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
#include <limits>

//for nicer printing
const int tabSize {25};

class Song {
    std::string artist;
    std::string name;
    int rating;
    
    //output overloaded operator
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    
public:
		//must provide default values to constructor, as
		//deque might contain uninitialized objects,
		//which could cause problems
    Song() : artist {"Unknown Artist"}, name {"Unknown"},
        rating {3}
        {};
        
    //parameters constructor
    Song(std::string artist, std::string name, int rating) 
        : artist {artist}, name {name}, rating {rating}
        {};

		//overloaded not equals operator
    bool operator!=(const Song &rhs) {
        return (artist != rhs.artist) || (name != rhs.name);
    }
  
};

//print the object nicely using setw for tabs
std::ostream &operator<<(std::ostream &os, const Song &s) {
    os  << std::left    << std::setw(tabSize) 
        << s.artist     << std::setw(tabSize)
        << s.name       << std::setw(tabSize)
        << s.rating;
    return os;
}

//generic list print function - works with any
//object or variable
template <typename T>
void displayList(const std::list<T> &list) {
    std::cout << "\n..............Playlist.................\n";
    for (const auto &item : list) {
        std::cout << item << "\n";
    }
    std::cout << std::endl;
}

//pass the playlist as a list of Song objects
//and get the first song in it
bool playFirst(std::list<Song> &playlist) {
    //check if the playlist is not empty first!!
    if (playlist.size() > 0) {
        std::cout << "Playing first song\n";
        std::cout << "\n.........Currently Playing.........\n";
        
        //simply use .front() method
        std::cout << playlist.front() << std::endl;
        return true;
    }
    return false;
}

//passing in the iterator and the playlist to the function
bool playNext(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    //dereference the iterator location to
    //get the current object, and see if
    //it's not the last one in the list
    if (*it != playlist.back()) {
				//use std::advance to move the iterator
				//forward safely
        std::advance(it, +1);
        std::cout << "\n.........Currently Playing.........\n";
        //dereference iterator object
        std::cout << *it << std::endl;
        return true;
    }
    return false;
}

bool playPrevious(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    if (it != playlist.begin()) {
				//even though we are going back, the
				//method is still called advance!!
        std::advance(it, -1);
        std::cout << "\n.........Currently Playing.........\n";
        std::cout << *it << std::endl;
        return true;
    }
    
    return false;
}

//get the iterator to add the song at the current location
bool addSong(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    
    
    std::string artistName {};
    std::cout << "Enter the artist: ";
    std::getline(std::cin, artistName);
    
    std::string songName {};
    std::cout << "Enter the song title: ";
    std::getline(std::cin, songName);
    
    int songRating {};
    std::cout << "Enter the rating (1-5): ";
    std::cin >> songRating;
    while (songRating > 5 || songRating < 0) {
        std::cout << "Please enter a valid rating: ";
        std::cin >> songRating;
    }
    //calling constructor to make new Song object
    Song newSong(artistName, songName, songRating);
    
    //put the new song in at the current location
    playlist.insert(it, newSong);
    
    //move one location back because new song
    //has taken the current space
    std::advance(it, -1);
    
    std::cout << "\n...........Currently Playing.........\n";
    std::cout << *it << std::endl;
    return true;
}

//get user input and run the program in a nice
//self-contained method
void displayMenu(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    bool exitMenu {false};
    do {
        std::cout   << "\n"
                    << "F - Play First Song\n"
                    << "N - Play Next Song\n"
                    << "P - Play Previous Song\n"
                    << "A - Add and Play a Song\n"
                    << "L - List the Current Playlist\n"
                    << "X - Exit\n"
                    << "==============================\n"
                    << "Enter a selection: ";
        char choice {};
        std::cin >> choice;
        //ignore any other input after the first char
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
        //convert to upper for easier processing
        choice = std::toupper(choice);
                
        switch (choice) {
            case 'F':
                playFirst(playlist);
                break;
            case 'N':
                playNext(playlist, it);
                break;
            case 'P':
                playPrevious(playlist, it);
                break;
            case 'A':
                addSong(playlist, it);
                break;
            case 'L':
                displayList(playlist);
                std::cout << "Current song: \n";
                std::cout << *it << std::endl;
                break;
            case 'X':
                exitMenu = true;
                break;
        }
        
    } while (!exitMenu);
}

int main() {
    
    //testing default & general constructors
    Song song1;
    Song song2 {"LZ", "Kshmr", 5}; //params are artist, name & rating
    
    //create a list of Song objects to be
    //the playlist
    std::list<Song> playList1 {song1, song2};

		//using auto for convenience - regular
		//syntax is very long!
		//creating the iterator to traverse our
		//playlist from the start position
    auto it = playList1.begin();

    displayList(playList1);

    displayMenu(playList1, it);
    
	return 0;
}
