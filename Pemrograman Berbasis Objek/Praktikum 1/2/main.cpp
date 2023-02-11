#include "Paper.hpp"
int main() {
    Paper a('A');
    Paper b('B');
    Paper c('C');
    Paper x(c);
    a.fold();
    b.fold();
    c.fold();
    c.glue();
    c.setName('X');
    x.fold();
    x.glue();
    return 0;
}
