#include "Piano.h"

Piano::Piano() : note(""), frequency(0) {}

Piano::Piano(string n, double freq) : note(n), frequency(freq) {}

void Piano::setNote(string n) {
    note = n;
}

void Piano::setFreq(double f) {
    frequency = f;
}

string Piano::getNote() const {
    return note;
}

double Piano::getFreq() const {
    return frequency;
}

void Piano::playSound(const string& note) {
    double baseFrequency = 261.63; //base frequency
    double notes[12];
    for (int i = 0; i < 12; ++i) {
        notes[i] = baseFrequency * pow(2, i / 12.0);
    }

    int index = -1;
    for (int i = 0; i < 12; ++i) {
        if (notes[i] == frequency) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Piano sound: " << note << endl;
    }
}


//noteMap initialization
map<string, sf::SoundBuffer> Sound::noteMap = {};

//Sound Constructor
Sound::Sound() : sound(), soundBuffer() {}

//loadSound Definition
//bool Sound::loadSound(const string& filename) {
//    return soundBuffer.loadFromFile(filename);
//}

void Sound::loadNotes() {
    noteMap["C"] = sf::SoundBuffer(); //storing "C" with default value using default contructor SoundBuffer()
    noteMap["C"].loadFromFile("C.wav");

    noteMap["C#"] = sf::SoundBuffer();
    noteMap["C#"].loadFromFile("C#.wav");

    noteMap["D"] = sf::SoundBuffer();
    noteMap["D"].loadFromFile("D.wav");

    noteMap["D#"] = sf::SoundBuffer();
    noteMap["D#"].loadFromFile("D#.wav");

    noteMap["E"] = sf::SoundBuffer();
    noteMap["E"].loadFromFile("E.wav");

    noteMap["F"] = sf::SoundBuffer();
    noteMap["F"].loadFromFile("F.wav");

    noteMap["F#"] = sf::SoundBuffer();
    noteMap["F#"].loadFromFile("F#.wav");

    noteMap["G"] = sf::SoundBuffer();
    noteMap["G"].loadFromFile("G.wav");

    noteMap["G#"] = sf::SoundBuffer();
    noteMap["G#"].loadFromFile("G#.wav");

    noteMap["A"] = sf::SoundBuffer();
    noteMap["A"].loadFromFile("A.wav");

    noteMap["A#"] = sf::SoundBuffer();
    noteMap["A#"].loadFromFile("A#.wav");

    noteMap["B"] = sf::SoundBuffer();
    noteMap["B"].loadFromFile("B.wav");
}

void Sound::playSound(const string& note) {
    cout << "Piano Key: " << note << endl;
    auto Note = noteMap.find(note);
    if (Note != noteMap.end()) {
        sound.setBuffer(Note->second);
        sound.play();
    }
    else {
        try {
            throw "Note not found";
        }
        catch (const char* errorMessage) {
            cerr << errorMessage << ": " << note << endl;
        }
    }
}
