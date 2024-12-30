#include "pch.h"
#include "Track.h"

Track::Track(const std::string& title, const std::string& artist, double duration)
    : Media(title, artist), duration(duration) {}

double Track::getDuration() const {
    return duration;
}