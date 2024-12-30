#include "pch.h"
#include "Media.h"

Media::Media(const std::string& title, const std::string& artist)
    : title(title), artist(artist) {}

std::string Media::getTitle() const {
    return title;
}

std::string Media::getArtist() const {
    return artist;
}