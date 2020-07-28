#include "vehicle_part.h"
#include  "key_keyboard.h"

Vehicle::Vehicle() {
    init_kwlBody_atas();
    init_kwlBody_depan();
    init_kwlBody_belakang();

    latarTempat();

    setPistonAct(-10);
    setCiduk(0, 0);
    setInochi(false);
}

void Vehicle::movements() {
    ciduk_move();
}

void Vehicle::setPistonAct(int itr) {
    pistonAct = itr;
}

void Vehicle::setCiduk(int lengan, int sudut) {
    lenganCiduk = lengan;
    sudutCiduk = sudut;
}

void Vehicle::setInochi(bool tamashi) {
    kwl = tamashi;
}

int Vehicle::getPistonAct() {
    return pistonAct;
}

int Vehicle::getLenganCiduk() {
    return lenganCiduk;
}

int Vehicle::getSudutCiduk() {
    return sudutCiduk;
}

bool Vehicle::getKwl() {
    return kwl;
}
