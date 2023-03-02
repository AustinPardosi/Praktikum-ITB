#include "ArtistUser.h"
#include <cstdio>

int num_of_artist = 0;

        // int num_of_music_uploaded; // jumlah musik dalam uploaded_music_list
        // char** uploaded_music_list;
        // static int num_of_artist;

//ctor, parameter: nama pengguna
ArtistUser::ArtistUser(char* name) : User(name) {
    strcpy(this->name,name);
    this->num_of_music_uploaded = 0;
    num_of_artist++;
}

// cctor
ArtistUser::ArtistUser(const ArtistUser& t) : User(t.name) {
    strcpy(this->name, t.name);
    this->num_of_music_uploaded = t.num_of_music_uploaded;
    num_of_artist++;
}

// dtor
// selain implementasi, print juga "Artist user <nama user> deleted"
// Contoh:
// Artist user A deleted
ArtistUser::~ArtistUser() {
    delete [] this->uploaded_music_list;
    printf("Artist user ");
    for(int i=0; i<strlen(this->name); i++) {
        printf("%c", this->name);
    }
    printf(" deleted\n");
    for(int i=0; i<strlen(this->name); i++) {
        delete [] uploaded_music_list[i];
    }
    delete [] uploaded_music_list;
    delete [] name;
    num_of_artist--;
}

// Asumsi: musik unik, parameter: judul musik
void ArtistUser::uploadMusic(char* musicName) {
    this->num_of_music_uploaded++;
    char* *temp = this->uploaded_music_list;
    for(int i=0; i<this->num_of_music_uploaded-1; i++) {
        this->uploaded_music_list[i] = new char [strlen(temp[i])];
        strcpy(this->uploaded_music_list[i], temp[i]);
    }
    this->uploaded_music_list[this->num_of_music_uploaded-1] = new char[strlen(musicName)];
    strcpy(this->uploaded_music_list[this->num_of_music_uploaded-1], musicName);
    this->num_of_music_uploaded++;
}

void ArtistUser::deleteUploadedMusic(char* musicName) {
    char* *temp;
    for(int i=0; i<this->num_of_music_uploaded; i++) {
        if (strcmp(musicName, this->uploaded_music_list[i])) {
            *temp = this->uploaded_music_list[i];
            this->num_of_music_uploaded--;
            for(int j=i; j<this->num_of_music_uploaded; j++) {
                this->uploaded_music_list[j] = this->uploaded_music_list[j+1];
            }
            delete [] temp;
        }
    }
    this->num_of_music_uploaded--;
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

int ArtistUser::getNumOfArtist() {
    return num_of_artist;
}