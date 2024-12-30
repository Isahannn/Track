#include "pch.h"
#include "Album.h"

TEST(AlbumTest, TotalDurationTest) {
    Album album("My Album");
    album.addTrack(Track("Song 1", "Artist 1", 4.0));
    album.addTrack(Track("Song 2", "Artist 2", 2.5));
    album.addTrack(Track("Song 3", "Artist 3", 3.0));

    EXPECT_DOUBLE_EQ(album.totalDuration(), 9.5);
}

TEST(AlbumTest, AddTrackTest) {
    Album album("My Album");
    album.addTrack(Track("Song 1", "Artist 1", 4.0));
    EXPECT_DOUBLE_EQ(album.totalDuration(), 4.0);
}

TEST(AlbumTest, FindTracksInRangeTest) {
    Album album("My Album");
    album.addTrack(Track("Short Song", "Artist 1", 1.0));
    album.addTrack(Track("Medium Song", "Artist 2", 3.0));
    album.addTrack(Track("Long Song", "Artist 3", 5.0));

    auto foundTracks = album.findTracksInRange(2.0, 4.0);
    EXPECT_EQ(foundTracks.size(), 1);
    EXPECT_EQ(foundTracks[0].getTitle(), "Medium Song");
}

TEST(AlbumTest, TotalDurationAfterAddingTracks) {
    Album album("Album A");
    album.addTrack(Track("Track A", "Artist A", 2.0));
    album.addTrack(Track("Track B", "Artist B", 3.0));
    EXPECT_DOUBLE_EQ(album.totalDuration(), 5.0);
}

TEST(AlbumTest, FindNoTracksInRange) {
    Album album("Album B");
    album.addTrack(Track("Track C", "Artist C", 0.0));
    album.addTrack(Track("Track D", "Artist D", 4.5));

    auto foundTracks = album.findTracksInRange(1.0, 3.0);
    EXPECT_TRUE(foundTracks.empty());
}

TEST(AlbumTest, DisplayTracksDoesNotThrow) {
    Album album("Album C");
    album.addTrack(Track("Track E", "Artist E", 3.0));
    album.addTrack(Track("Track F", "Artist F", 2.5));

    EXPECT_NO_THROW(album.displayTracks());
}

TEST(AlbumTest, AddTrackNegativeDuration) {
    Album album("My Album");
    EXPECT_THROW(album.addTrack(Track("Invalid Track", "Artist 1", -1.0)), std::invalid_argument);
}

TEST(AlbumTest, FindTracksInInvalidRange) {
    Album album("Album C");
    album.addTrack(Track("Track A", "Artist A", 3.0));
    album.addTrack(Track("Track B", "Artist B", 4.0));

    EXPECT_THROW(album.findTracksInRange(-1.0, 2.0), std::invalid_argument);
}

TEST(AlbumTest, EmptyAlbumDuration) {
    Album album("Empty Album");
    EXPECT_DOUBLE_EQ(album.totalDuration(), 0.0);
}