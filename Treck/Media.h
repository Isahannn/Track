#ifndef MEDIA_H
#define MEDIA_H

#include <string>

class Media {
protected:
    std::string title;
    std::string artist;

public:
    Media(const std::string& title, const std::string& artist);
    virtual ~Media() = default;

    std::string getTitle() const;
    std::string getArtist() const;
};

#endif // MEDIA_H