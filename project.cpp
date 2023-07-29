#include <iostream>
#include <string>
#include <map>
using namespace std;

class Piano{
    private:
    string note;
    double frequency;

    protected:
    map<string, double> notes;

    notes["C"] = 261.63;
    notes["C#"] = 277.18;
    notes["D"] = 293.66;
    notes["D#"] = 311.13;
    notes["E"] = 329.63;
    notes["F"] = 349.23;
    notes["F#"] = 369.99;
    notes["G"] = 392.00;
    notes["G#"] = 415.30;
    notes["A"] = 440.00;
    notes["A#"] = 466.16;
    notes["B"] = 493.88;

    public:
    Piano(){
        note = "";
        frequency = 0;
    }
    Piano(string n, double freq){
        set_note(n);
        set_freq(freq);
    }
    void set_note(string n){
        note = n;
    }
    void set_freq(double f){
        frequency = f;
    }
    string get_note(){
        return note;
    }
    double get_freq(){
        return frequency;
    }  
}
class Sound: public Piano{
    private:

    public:
    
}
class Keyboard: public Piano{

}