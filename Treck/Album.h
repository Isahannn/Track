#ifndef ALBUM_H
#define ALBUM_H

#include <vector>
#include "Track.h"

class Album {
private:
    std::string name;
    std::vector<Track> tracks;

public:
    Album(const std::string& name);
    void addTrack(const Track& track);
    double totalDuration() const;
    void displayTracks() const;
    std::vector<Track> findTracksInRange(double min, double max) const;
};

#endif // ALBUM_H