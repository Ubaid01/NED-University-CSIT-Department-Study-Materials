/* 
Benefits of Composition over Inheritance
    
    Flexibility:
Composition allows us to change the behavior at runtime by composing different objects. For instance, we can easily switch the Playable strategy used by MediaFile.

    Reusability:
Components (like AudioPlayer and VideoPlayer) can be reused across different contexts without being tightly coupled to a specific class hierarchy.

    Maintainability:
Changes in behavior or new features can be added with minimal changes to the existing code. We can introduce new Playable types without altering the MediaFile class.

    Encapsulation:
Each component encapsulates its functionality, making the system easier to understand and modify.
    Conclusion:
By preferring composition over inheritance, we achieve a design that is more flexible, reusable, and easier to maintain. This design approach aligns with the principles of object-oriented design, promoting loose coupling and high cohesion. In the media player application, using composition allows us to manage different types of media players more effectively than a rigid inheritance-based approach.   */

#include<iostream>
using namespace std ;

class Playable {
public:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual ~Playable() {}
};

class MediaFile {
private:
    Playable* playable; // Composition
public:
    MediaFile(Playable* p) : playable(p) {}
    void play() {
        playable->play();
    }
    void pause() {
        playable->pause();
    }
    void stop() {
        playable->stop();
    }
};

class AudioPlayer : public Playable {
public:
    void play() override {
        // Play audio
    }
    void pause() override {
        // Pause audio
    }
    void stop() override {
        // Stop audio
    }
};

class VideoPlayer : public Playable {
public:
    void play() override {
        // Play video
    }
    void pause() override {
        // Pause video
    }
    void stop() override {
        // Stop video
    }
};

int main() {
    AudioPlayer audioPlayer;
    VideoPlayer videoPlayer;

    MediaFile audioFile(&audioPlayer);
    MediaFile videoFile(&videoPlayer);

    audioFile.play();  // Play audio
    videoFile.play();  // Play video

    audioFile.pause(); // Pause audio
    videoFile.stop();  // Stop video

    return 0;
}
