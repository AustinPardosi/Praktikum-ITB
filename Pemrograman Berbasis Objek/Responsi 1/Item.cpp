#include "Item.hpp"
#include <cstdio>

int Item::totalRevenue =  0;		
int Item::totalItems = 0;	

/* Ctor default: stok adalah 0 dan harga barang adalah 0 */
Item::Item() : serialNum(Item::totalItems + 1) {
    this->stock = 0;
    this->price = 0;
    this->sold = 0;
    Item::totalItems++;
}
	
Item::Item(int stock, int price) : serialNum(Item::totalItems + 1) {
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    Item::totalItems++;
}

// /* cctor item, mengkopi seluruh atribut item, termasuk atribut sold */
Item::Item(const Item &x) : serialNum(Item::totalItems + 1){
    this->stock = x.stock;
    this->price = x.price;
    this->sold = x.sold;
    Item::totalItems++;
}

Item::~Item(){}
	
int Item::getSerialNum() const{
    return this->serialNum;
}

int Item::getSold() const{
    return this->sold;
}

int Item::getPrice() const{
    return this->price;
}

/* Menambahkan stok item. Tidak akan bernilai negatif. */
void Item::addStock(int addedStock){
    this->stock = this->stock + addedStock;
}

/* Menjual item. Jika item tidak cukup, maka item terjual hanya sampai stok item habis */
void Item::sell(int soldStock){
    if (this->stock < soldStock) {
		Item::totalRevenue += this->stock * this->price;
		this->sold += this->stock;
		this->stock = 0;
    } else {
		Item::totalRevenue += soldStock * this->price;
        this->sold = this->sold + soldStock;
        this->stock = this->stock - soldStock; 
    }
}

void Item::setPrice(int newPrice){
    this->price = newPrice;
}
