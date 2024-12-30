#include "pch.h"
#include "Track.h"

TEST(TrackTest, GettersTest) {
    Track track("Song Title", "Artist Name", 3.5);
    EXPECT_EQ(track.getTitle(), "Song Title");
    EXPECT_EQ(track.getArtist(), "Artist Name");
    EXPECT_EQ(track.getDuration(), 3.5);
}

TEST(TrackTest, DurationPositive) {
    Track track("Track A", "Artist A", 4.0);
    EXPECT_GT(track.getDuration(), 0);
}

TEST(TrackTest, TitleNonEmpty) {
    Track track("Track B", "Artist B", 2.5);
    EXPECT_FALSE(track.getTitle().empty());
}

TEST(TrackTest, ArtistNonEmpty) {
    Track track("Track C", "Artist C", 3.0);
    EXPECT_FALSE(track.getArtist().empty());
}

TEST(TrackTest, DurationZero) {
    Track track("Track D", "Artist D", 0.0);
    EXPECT_EQ(track.getDuration(), 0.0);
}

TEST(TrackTest, NegativeDuration) {
    Track track("Track E", "Artist E", -1.0);
    EXPECT_LT(track.getDuration(), 0);  // ѕровер€ем, что продолжительность меньше нул€
}