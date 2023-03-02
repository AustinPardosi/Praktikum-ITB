#include "BurnableBarrel.hpp"

// Default Constructor
BurnableBarrel::BurnableBarrel() {}

// Masukan: health (integer positif)
BurnableBarrel::BurnableBarrel(int _health) {
    Damageable(_health);
}

// Masukan: damage (integer positif) dan element (string)
// Berikut adalah urutan aksi yang dilakukan:
// Apabila barrel telah hancur, maka tidak akan terjadi apa-apa.
// Apabila barrel menerima damage element berupa "fire", maka akan mengaktifkan status burned. Apabila barrel
// menerima damage element berupa "water", maka status burned akan dinonaktifkan.
// Setelah update status burned, Jika barrel dalam kondisi burned, maka damagenya akan dikalikan dengan konstanta
// multiplier. Jika tidak, maka damagenya tidak berubah.
void BurnableBarrel::takeDamage(int _damage, string _element) {
    if (!Damageable::isDestroyed()) {
        if (_element == "fire") {
            Burnable::burn();
        } else if (_element == "water") {
            Burnable::watered();
        }

        if (Burnable::isBurned()) {
            _damage *= multiplier;
        }
    }
}