
#define TRACK_H

#include "Media.h"

class Track : public Media {
private:
    double duration; // in minutes

public:
    Track(const std::string& title, const std::string& artist, double duration);
    double getDuration() const;
};

