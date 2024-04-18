#include "Unit.h"

void Unit::print() const{
    printf ("Unit #%zu: Belong to %zu with combat %d, can move %d, rebase:%d, and landing:%d\n", id, nationality, combat_value, movement, rebase, landing);
}