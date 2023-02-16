#include "User.h"
#include <cstring>
#include <cstdio>

int n_user = 0;

// ctor, parameter: nama pengguna
User::User(char* nama) {
    this->name = new char[strlen(name)];
    strcpy(this->name, nama);
    this->num_of_favourite_music = 0;
    music_list = new char* [this->num_of_favourite_music];
    n_user++;
}

// cctor
User::User(const User& t) {
    this->name = new char[strlen(t.name)];
    strcpy(this->name, t.name);
    this->num_of_favourite_music = t.num_of_favourite_music;
    music_list = new char* [this->num_of_favourite_music];
    for(int i=0; i < this->num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(t.music_list[i])];
        strcpy(this->music_list[i], t.music_list[i]);
    }
    n_user++;
}

// dtor
// selain implementasi, print juga "User <nama user> deleted<endl>"
// Contoh:
// User A deleted
//
User::~User() {
    delete [] this->music_list;
    printf("User ");
    for(int i=0; i<strlen(this->name); i++) {
        printf("%c", this->name);
    }
    printf(" deleted\n");
    for(int i=0; i<strlen(this->name); i++) {
        delete [] music_list[i];
    }
    delete [] music_list;
    delete [] name;
    n_user--;
}

// Asumsi: musik unik, parameter: judul musik
void User::addFavouriteMusic(char* title) {
    this->num_of_favourite_music++;
    char* *temp = this->music_list;
    for(int i=0; i<this->num_of_favourite_music-1; i++) {
        this->music_list[i] = new char [strlen(temp[i])];
        strcpy(this->music_list[i], temp[i]);
    }
    this->music_list[this->num_of_favourite_music-1] = new char[strlen(title)];
    strcpy(this->music_list[this->num_of_favourite_music-1], title);
}

// cek ulang
void User::deleteFavouriteMusic(char* title) {
    char* *temp;
    for(int i=0; i<this->num_of_favourite_music; i++) {
        if (strcmp(title, this->music_list[i])) {
            *temp = this->music_list[i];
            this->num_of_favourite_music--;
            for(int j=i; j<this->num_of_favourite_music; j++) {
                this->music_list[j] = this->music_list[j+1];
            }
            delete [] temp;
        }
    }
}

void User::setName(char* nama) {
    delete [] name;
    this->name = new char[strlen(nama)];
    strcpy(this->name, nama);
}

char* User::getName() const {
    return this->name;
}

int User::getNumOfFavouriteMusic() const {
    return this->num_of_favourite_music;
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music in your favourite list<endl>"
void User::viewMusicList() const {
    if (this->num_of_favourite_music == 0) {
        printf("No music in your favourite list\n");
    } else {
        for(int i=0; i< this->num_of_favourite_music; i++) {
            printf("%d", i+1);
            printf(". ");
            printf("%s\n", this->music_list[i]);
        }
    }
}

int User::getNumOfUser() {
    return n_user;
}