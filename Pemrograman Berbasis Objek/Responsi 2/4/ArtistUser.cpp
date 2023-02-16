#include "ArtistUser.h"

int num_of_artist = 0;

//ctor, parameter: nama pengguna
ArtistUser::ArtistUser(char* name) : User(name) {
    strcpy(this->name,name);
    this->num_of_favourite_music = 0;
    num_of_artist++;
}

// cctor
ArtistUser::ArtistUser(const ArtistUser& ) {
    num_of_artist++;
}

// dtor
// selain implementasi, print juga "Artist user <nama user> deleted"
// Contoh:
// Artist user A deleted
ArtistUser::~ArtistUser() {

}

// Asumsi: musik unik, parameter: judul musik
void ArtistUser::uploadMusic(char*) {
    this->num_of_music_uploaded++;
}

void ArtistUser::deleteUploadedMusic(char*) {

}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music uploaded<endl>"
void ArtistUser::viewUploadedMusicList() const {

}

int ArtistUser::getNumOfMusicUploaded() const {
    return this->num_of_music_uploaded;
}

static int ArtistUser::getNumOfArtist() {
    return num_of_artist;
}