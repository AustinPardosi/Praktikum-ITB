#include "Pickaxe.cpp"
#include "ReinforcedAxe.cpp"
#include "Tool.cpp"

int main() {
    Pickaxe p;
    p.use();
    p.enchant();
    Pickaxe p1(p);
    Pickaxe p2;
    p1 = p2;
    ReinforcedAxe r (0, 0);
    r.use();
    ReinforcedAxe r1(r);
    r.enchant();
    r1 + r;
    ReinforcedAxe r2(r1+r);
    r2.repair();
    return 0;
}