#include "Piano.h"


int main() {

    //With GUI

    Sound::loadNotes();

    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 200), "Simple Piano GUI");

    /* RenderWindow is a class of SFML in which a window is created. "window" is an object of RenderWindow.
    VideoMode is also a class in SFML that sets the size of the window (in pixels). */

    // Create buttons for each note. "buttons" is a vector that is storing objects of sf::RectangleShape
    vector<sf::RectangleShape> buttons(12);
    for (int i = 0; i < 12; ++i) {
        buttons[i].setSize(sf::Vector2f(50.f, 50.f));
        buttons[i].setPosition(50.f + i * 60.f, 75.f);
        buttons[i].setFillColor(sf::Color::White);
    }
    // Create a Sound object
    Sound sound;

    //Dynamically allocating noteNames array
    string* noteNames = new string[12]{ "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };

    //Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                for (int i = 0; i < 12; ++i) {
                    if (buttons[i].getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        sound.playSound(noteNames[i]);
                        break;
                    }
                }
            }
        }

        //Clear window
        window.clear(sf::Color::Black);

        //Draw buttons
        for (int i = 0; i < 12; ++i) {
            window.draw(buttons[i]);
        }

        //Displaying window contents
        window.display();
    }


    delete[] noteNames;

   // // With Keyboard
   //// Create instances of Piano and Sound
   // Piano piano;
   // Sound sound;

   // // Load notes for the Sound class
   // sound.loadNotes();

   // cout << "Enter a note (C, C#, D, D#, E, F, F#, G, G#, A, A#, B) or 'exit' to quit: ";
   // string userNote;

   // while (cin >> userNote) {
   //     if (userNote == "exit") {
   //         break;
   //     }

   //     // Set the note in the Piano class
   //     piano.setNote(userNote);

   //     // Play the sound using both the Piano and Sound classes
   //     piano.playSound(userNote);
   //     sound.playSound(userNote);

   //     cout << "Enter a note (C, C#, D, D#, E, F, F#, G, G#, A, A#, B) or 'exit' to quit: ";
   // }


    return 0;
}
