#include <iostream>
#include <string>
#include <map>
#include <portaudio.h>


using namespace std;

class Piano {
private:
    string note;
    double frequency;

public:
    struct NoteFrequency {
        std::string note;
        double frequency;
    };

    NoteFrequency notes[12] = {
        {"C", 261.63},
        {"C#", 277.18},
        {"D", 293.66},
        {"D#", 311.13},
        {"E", 329.63},
        {"F", 349.23},
        {"F#", 369.99},
        {"G", 392.00},
        {"G#", 415.30},
        {"A", 440.00},
        {"A#", 466.16},
        {"B", 493.88}
    };

public:


    Piano() {
        note = "";
        frequency = 0;
    }
    Piano(string n, double freq) {
        set_note(n);
        set_freq(freq);
    }
    void set_note(string n) {
        note = n;
    }
    void set_freq(double f) {
        frequency = f;
    }
    string get_note() {
        return note;
    }
    double get_freq() {
        return frequency;
    }
};


class Sound : public Piano {
private:

public:

};
class Keyboard : public Piano {

};
