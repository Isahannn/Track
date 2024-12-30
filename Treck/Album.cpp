#include "pch.h"
#include "Album.h"
#include <iostream>
#include <stdexcept>

Album::Album(const std::string& name) : name(name) {}

void Album::addTrack(const Track& track) {
    if (track.getDuration() < 0) {
        throw std::invalid_argument("Duration cannot be negative");
    }
    tracks.push_back(track);
}

double Album::totalDuration() const {
    double total = 0;
    for (const auto& track : tracks) {
        total += track.getDuration();
    }
    return total;
}

void Album::displayTracks() const {
    for (const auto& track : tracks) {
        std::cout << track.getTitle() << " by " << track.getArtist() << " (" << track.getDuration() << " min)\n";
    }
}

std::vector<Track> Album::findTracksInRange(double min, double max) const {
    if (min < 0 || max < 0) {
        throw std::invalid_argument("Duration range cannot be negative");
    }

    std::vector<Track> result;
    for (const auto& track : tracks) {
        if (track.getDuration() >= min && track.getDuration() <= max) {
            result.push_back(track);
        }
    }
    return result;
}