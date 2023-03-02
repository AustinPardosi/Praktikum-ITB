#include "ExplodableBarrel.hpp"

// Damageable
// private:
//   int health;

// Explodable
// private:
//   int baseDamage;

// protected:
//   const int multiplier = 5;

// Default Constructor
// health dari ExplodableBarrel selalu 1 dan
// default radiusnya adalah 5
ExplodableBarrel::ExplodableBarrel() {
    Damageable(1);
    this->radius = 5;
}

// Masukan: radius (integer positif) dan baseDamage (integer positif)
// health dari ExplodableBarrel selalu 1
ExplodableBarrel::ExplodableBarrel(int _radius, int _baseDamage) {
    this->radius = _radius;
    Explodable(_baseDamage);
    Damageable(1);
}

// Masukan: damage (integer positif) dan element (string)
// Berikut adalah urutan aksi yang dilakukan:
// Apabila barrel telah hancur, maka tidak akan terjadi apa-apa.
// Barrel menerima damage dan tidak menghiraukan element.
// Apabila barrel hancur setelah menerima damage, maka barrel akan meledak sebesar radius yang telah ditentukan.
void ExplodableBarrel::takeDamage(int _damage, string _element) {
    if (!Damageable::isDestroyed()) {
        Damageable::takeDamage(_damage);
        if(Damageable::isDestroyed()) {
            ExplodableBarrel();
        }
    }
}