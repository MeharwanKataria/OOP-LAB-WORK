#include <iostream>
using namespace std;

class MediaFile {
protected:
    string filePath;
    double size;
public:
    MediaFile(string filepath, double size) : filePath(filepath), size(size) {}

    virtual void play() {
        cout << "File is playing: " << filePath << endl;
    }

    virtual void stop() {
        cout << "File is being stopped: " << filePath << endl;
    }

    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
protected:
    string resolution;
public:
    VisualMedia(string filepath, double size, string resol)
        : MediaFile(filepath, size), resolution(resol) {}

    void displayResolution() {
        cout << "Resolution: " << resolution << endl;
    }
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;
public:
    AudioMedia(string filepath, double size, int sr)
        : MediaFile(filepath, size), sampleRate(sr) {}

    void displaySampleRate() {
        cout << "Sample rate: " << sampleRate << " Hz" << endl;
    }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, double size, string resolution, int samplerate)
        : MediaFile(path, size),
          VisualMedia(path, size, resolution),
          AudioMedia(path, size, samplerate) {}

    void play() override {
        cout << "Playing video file: " << filePath << " at " << resolution 
             << " resolution with " << sampleRate << " Hz audio" << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string path, double size, string resolution)
        : MediaFile(path, size), VisualMedia(path, size, resolution) {}

    void play() override {
        cout << "Displaying image: " << filePath << " at " << resolution << endl;
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string path, double size, int samplerate)
        : MediaFile(path, size), AudioMedia(path, size, samplerate) {}

    void play() override {
        cout << "Playing audio file: " << filePath << " with " << sampleRate << " Hz" << endl;
    }
};

int main() {
    MediaFile* media1 = new VideoFile("video.mp4", 500, "1920x1080", 44100);
    MediaFile* media2 = new ImageFile("image.png", 5, "1024x768");
    MediaFile* media3 = new AudioFile("audio.mp3", 10, 48000);

    media1->play();
    media2->play();
    media3->play();

    delete media1;
    delete media2;
    delete media3;

    return 0;
}

