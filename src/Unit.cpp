#include "Unit.h"

void Unit::print() const{
    printf ("Unit #%zu: Belong to %d with combat %d, can move %d, rebase:%d, and landing:%d\n", id, (int)nationality, (int)combat_value, (int)movement, (int)rebase, (int)landing);
}