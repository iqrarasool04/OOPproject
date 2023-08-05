#pragma once
#ifndef PIANO_H
#define PIANO_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

/* IMP:
       sf : the namespace used by SFML to group all its classes, functions, and resources.
       SoundBuffer : class in SFML for storing audio data in a format used by SFML audio module
       setBuffer : This associates the loaded audio data(sf::SoundBuffer) with the sound object.(sf::Sound)
       */

class Instrument {
public:
    virtual void playSound(const string& note) = 0;
    virtual ~Instrument() {}
};

class Piano : public Instrument {
private:
    string note;
    double frequency;

public:
    Piano();
    Piano(string n, double freq);

    void setNote(string n);
    void setFreq(double f);
    string getNote() const;
    double getFreq() const;

    void playSound(const string& note) override;
};

class Sound : public Instrument {
private:
    static map<string, sf::SoundBuffer> noteMap;
    sf::Sound sound;
    sf::SoundBuffer soundBuffer;

public:
    Sound();

    //bool loadSound(const string& filename);

    static void loadNotes();

    void playSound(const string& note) override;
};
#endif // PIANO_H
