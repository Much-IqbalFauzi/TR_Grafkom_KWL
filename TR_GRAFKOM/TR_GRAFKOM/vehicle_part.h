#pragma once

void init_kwlBody_atas();

void init_kwlBody_depan();

void init_kwlBody_belakang();

void init_ciduk();

void latarTempat();

class Vehicle {
public:
    Vehicle();

    void movements();

    void setPistonAct(int itr);

    void setCiduk(int lengan, int sudut);

    void setInochi(bool tamashi);

    int getPistonAct();

    int getLenganCiduk();

    int getSudutCiduk();
    
    bool getKwl();
private:
    int pistonAct;
    int lenganCiduk;
    int sudutCiduk;
    bool kwl;
};



