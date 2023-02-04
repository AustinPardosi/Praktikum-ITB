#include "SpacingGuildShip.hpp"
#include <cstdio>
#include <cmath>

float SpacingGuildShip::totalGuildTravel = 0.0;
int SpacingGuildShip::producedShips = 0;

/* Ctor default: jumlah penumpang adalah 0, jumlah Guild Navigator adalah 3, Kapasitas pesawat adalah 50 orang, dan stok spice 50*/
SpacingGuildShip::SpacingGuildShip() : guildNavigatorCount(3), maxPassengerCap(50), serialNum(producedShips+1) {
    this->passengerCount = 0;
    this->spiceStock = 50;
    this->operatingGuildNavigator = this->guildNavigatorCount;
    SpacingGuildShip::producedShips++;
}

/* Ctor jika diketahui jumlah Guild Navigator, kapasitas maksimal pesawat, dan stok spice. Jumlah penumpang 0 */
SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : guildNavigatorCount(guildNavigatorCount), maxPassengerCap(maxPassengerCap), serialNum(producedShips+1){
    this->spiceStock = spiceStock;
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    SpacingGuildShip::producedShips++;
}

/* Cctor SpacingGuildShip */
SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip &x) : guildNavigatorCount(x.guildNavigatorCount), maxPassengerCap(x.maxPassengerCap), serialNum(producedShips+1) {
    this->passengerCount = x.passengerCount;
    this->spiceStock = x.spiceStock;
    this->operatingGuildNavigator = x.operatingGuildNavigator;
    SpacingGuildShip::producedShips++;
}

/* Dtor SpacingGuildShip */
SpacingGuildShip::~SpacingGuildShip() {}

/* Mengembalikan serial number dari pesawat */
int SpacingGuildShip::getShipSerialNum() const {
    return this->serialNum;
}

/* Mengembalikan jumlah penumpang pesawat */
int SpacingGuildShip::getPassengerCount() const {
    return this->passengerCount;
}

/* Pesawat bergerak sebesar distance, sehingga totalGuildTravel bertambah sebesar: distance / (E^2 * operatingGuildNavigator). Catatan: 
   1. Apabila tidak ada Guild Navigator yang operasional, maka totalGuildTravel tidak bertambah;
   2. Apabila ada Guild Navigator yang operasional, maka jumlah Guild Navigator operasional berkurang 1 */
void SpacingGuildShip::travel(float distance){
    if (this->operatingGuildNavigator!=0) {
        totalGuildTravel += distance/ (pow(E,2) * this->operatingGuildNavigator);
        this->operatingGuildNavigator--;
    }
}

/* Penumpang naik ke pesawat sebesar addedPassenger. Jika pesawat tidak muat, penumpang pesawat menjadi penuh */
void SpacingGuildShip::boarding(int addedPassengers){
    this->passengerCount += addedPassengers;
    if (this->passengerCount > this->maxPassengerCap) {
        this->passengerCount = this->maxPassengerCap;
    }
}

/* Penumpang turun dari pesawat sebesar droppedPassenger. Jika jumlah penumpang kurang, kosongkan pesawat */
void SpacingGuildShip::dropOff(int droppedPassengers){
    if ((this->passengerCount - droppedPassengers) > 0) {
        this->passengerCount -= droppedPassengers;
    } else {
        this->passengerCount = 0;
    }
}

/* Menambah n Guild Navigator operasional yang menghabiskan n * GUILD_NAVIGATOR_SPICE_DOSE spice dari stok. Catatan:
	1. Maksimum merefresh seluruh Guild Navigator yang ada di pesawat 
	2. Apabila stok kurang, maka merefresh n maksimum yang dapat di refresh dari stok spice yang ada */
void SpacingGuildShip::refreshNavigator(int n){
    int i;
    if (n > this->guildNavigatorCount) {
        n = this->guildNavigatorCount;
    }

    for (i = 0; i < n; i++) {
        if (n * GUILD_NAVIGATOR_SPICE_DOSE > this->spiceStock) {
            i--;
            break;
        }
    }
    this->spiceStock -= i * GUILD_NAVIGATOR_SPICE_DOSE;
    this->operatingGuildNavigator += i;
}

/* Menambah stok spice sebesar addedSpice */
void SpacingGuildShip::transitToArrakis(int addedSpice){
    this->spiceStock += addedSpice;
}