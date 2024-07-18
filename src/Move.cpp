#include "Move.h"
#include "Animal.h"
#include "Bomber.h"
#include "Ballom.h"
#include "Oneal.h"

void Move::checkRun(Animal *a){
    if (dynamic_cast<Bomber*>(a) != nullptr){
        if (a->getCount() > 0){
            setDirection(a->getDirection(), a, 32);
            a->setCount(a->getCount() - 1);
        }
    }
    if (dynamic_cast<Oneal*>(a) != nullptr || dynamic_cast<Ballom*>(a) != nullptr){
        if (a->getCount() > 0){
            setDirection(a->getDirection(), a, 32);
            a->setCount(a->getCount() - 1);
        }
    }
}

//DOWN
void Move::setDirection(std::string direction, Animal *b, int step){
    if (direction == "down"){
        downAndSwap(b);
        b->setPoy(b->getPoy()+step);
    } else if (direction == "up"){
        upAndSwap(b);
        b->setPoy(b->getPoy()-step);
    } else if (direction == "right"){
        rightAndSwap(b);
        b->setPox(b->getPox()+step);
    } else if (direction == "left"){
        leftAndSwap(b);
        b->setPox(b->getPox()-step);
    }
}


void Move::down(Animal *a){
    if (a->getPox()%4 == 0 && a->getPoy()%4 == 0){
        if (dynamic_cast<Bomber*>(a) != nullptr && Blocked::blockDown(a)){
            a->setDirection("down");
            a->setCount(4);
            checkRun(a);
        }
        if ((dynamic_cast<Oneal*>(a) != nullptr || dynamic_cast<Ballom*>(a) != nullptr) && Blocked::blockDown(a)){
            a->setDirection("down");
            a->setCount(8);
            checkRun(a);
        }
    }
}


void Move::downAndSwap(Animal *a){
    if (dynamic_cast<Bomber*>(a) != nullptr) {
        if(a->getSwap() == 1){
            a->setPx(2);
            a->setPy(0);
            a->setSwap(2);
        } else if (a->getSwap() == 2){
            a->setPx(2);
            a->setPy(1);
            a->setSwap(3);
        } else if (a->getSwap() == 3){
            a->setPx(2);
            a->setPy(0);
            a->setSwap(4);
        } else {
            a->setPx(2);
            a->setPy(2);
            a->setSwap(1);
        }
    }

    if (dynamic_cast<Ballom*>(a) != nullptr){
        if(a->getSwap() == 1){
            a->setPx(10);
            a->setPy(0);
            a->setSwap(2);
        } else if (a->getSwap() == 2){
            a->setPx(10);
            a->setPy(1);
            a->setSwap(3);
        } else if (a->getSwap() == 3){
            a->setPx(10);
            a->setPy(2);
            a->setSwap(4);
        } else {
            a->setPx(10);
            a->setPy(1);
            a->setSwap(1);
        }
    }

    if (dynamic_cast<Oneal*>(a) != nullptr){
        if(a->getSwap() == 1){
            a->setPx(12);
            a->setPy(0);
            a->setSwap(2);
        } else if (a->getSwap() == 2){
            a->setPx(12);
            a->setPy(1);
            a->setSwap(3);
        } else if (a->getSwap() == 3){
            a->setPx(12);
            a->setPy(2);
            a->setSwap(4);
        } else {
            a->setPx(12);
            a->setPy(1);
            a->setSwap(1);
        }
    }
}

//UP
void Move::up(Animal *a){
    if (a->getPox()%4 == 0 && a->getPoy()%4 == 0){
        // Lack Blocked
        if (dynamic_cast<Bomber*>(a) != nullptr && Blocked::blockUp(a)){
            a->setDirection("up");
            a->setCount(4);
            checkRun(a);
        }
        if ((dynamic_cast<Oneal*>(a) != nullptr || dynamic_cast<Ballom*>(a) != nullptr) && Blocked::blockUp(a)){
            a->setDirection("up");
            a->setCount(8);
            checkRun(a);
        }
    }
}

void Move::upAndSwap(Animal *a){
    if (dynamic_cast<Bomber*>(a) != nullptr) {
        if(a->getSwap() == 1){
            a->setPx(0);
            a->setPy(0);
            a->setSwap(2);
        } else if (a->getSwap() == 2){
            a->setPx(0);
            a->setPy(1);
            a->setSwap(3);
        } else if (a->getSwap() == 3){
            a->setPx(0);
            a->setPy(0);
            a->setSwap(4);
        } else {
            a->setPx(0);
            a->setPy(2);
            a->setSwap(1);
        }
    }

    if (dynamic_cast<Ballom*>(a) != nullptr){
        if(a->getSwap() == 1){
            a->setPx(9);
            a->setPy(0);
            a->setSwap(2);
        } else if (a->getSwap() == 2){
            a->setPx(9);
            a->setPy(1);
            a->setSwap(3);
        } else if (a->getSwap() == 3){
            a->setPx(9);
            a->setPy(2);
            a->setSwap(4);
        } else {
            a->setPx(9);
            a->setPy(1);
            a->setSwap(1);
        }
    }

    if (dynamic_cast<Oneal*>(a) != nullptr){
        if(a->getSwap() == 1){
            a->setPx(11);
            a->setPy(0);
            a->setSwap(2);
        } else if (a->getSwap() == 2){
            a->setPx(11);
            a->setPy(1);
            a->setSwap(3);
        } else if (a->getSwap() == 3){
            a->setPx(11);
            a->setPy(2);
            a->setSwap(4);
        } else {
            a->setPx(11);
            a->setPy(1);
            a->setSwap(1);
        }
    }
}

//LEFT
void Move::left(Animal *a){
    if (a->getPox()%4 == 0 && a->getPoy()%4 == 0){
        // Lack Blocked
        if (dynamic_cast<Bomber*>(a) != nullptr && Blocked::blockLeft(a)){
            a->setDirection("left");
            a->setCount(4);
            checkRun(a);
        }
        if ((dynamic_cast<Oneal*>(a) != nullptr || dynamic_cast<Ballom*>(a) != nullptr) && Blocked::blockLeft(a)){
            a->setDirection("left");
            a->setCount(8);
            checkRun(a);
        }
    }
}

void Move::leftAndSwap(Animal *a){
    if (dynamic_cast<Bomber*>(a) != nullptr) {
        if(a->getSwap() == 1){
            a->setPx(3);
            a->setPy(0);
            a->setSwap(2);
        } else if (a->getSwap() == 2){
            a->setPx(3);
            a->setPy(1);
            a->setSwap(3);
        } else if (a->getSwap() == 3){
            a->setPx(3);
            a->setPy(0);
            a->setSwap(4);
        } else {
            a->setPx(3);
            a->setPy(2);
            a->setSwap(1);
        }
    }
    
    if (dynamic_cast<Ballom*>(a) != nullptr){
        if(a->getSwap() == 1){
            a->setPx(9);
            a->setPy(0);
            a->setSwap(2);
        } else if (a->getSwap() == 2){
            a->setPx(9);
            a->setPy(1);
            a->setSwap(3);
        } else if (a->getSwap() == 3){
            a->setPx(9);
            a->setPy(2);
            a->setSwap(4);
        } else {
            a->setPx(10);
            a->setPy(1);
            a->setSwap(1);
        }
    }

    if (dynamic_cast<Oneal*>(a) != nullptr){
        if(a->getSwap() == 1){
            a->setPx(11);
            a->setPy(0);
            a->setSwap(2);
        } else if (a->getSwap() == 2){
            a->setPx(11);
            a->setPy(1);
            a->setSwap(3);
        } else if (a->getSwap() == 3){
            a->setPx(11);
            a->setPy(2);
            a->setSwap(4);
        } else {
            a->setPx(11);
            a->setPy(1);
            a->setSwap(1);
        }
    }
}

//RIGHT

void Move::right(Animal *a){
    if (a->getPox()%4 == 0 && a->getPoy()%4 == 0){
        if (dynamic_cast<Bomber*>(a) != nullptr && Blocked::blockRight(a)){
            a->setDirection("right");
            a->setCount(4);
            checkRun(a);
        }
        
        if ((dynamic_cast<Oneal*>(a) != nullptr || dynamic_cast<Ballom*>(a) != nullptr) && Blocked::blockRight(a)){
            a->setDirection("right");
            a->setCount(8);
            checkRun(a);
        }
    }
}

void Move::rightAndSwap(Animal*a){
    if (dynamic_cast<Bomber*>(a) != nullptr) {
        if(a->getSwap() == 1){
            a->setPx(1);
            a->setPy(0);
            a->setSwap(2);
        } else if (a->getSwap() == 2){
            a->setPx(1);
            a->setPy(1);
            a->setSwap(3);
        } else if (a->getSwap() == 3){
            a->setPx(1);
            a->setPy(0);
            a->setSwap(4);
        } else {
            a->setPx(1);
            a->setPy(2);
            a->setSwap(1);
        }
    }

    if (dynamic_cast<Ballom*>(a) != nullptr){
        if(a->getSwap() == 1){
            a->setPx(10);
            a->setPy(0);
            a->setSwap(2);
        } else if (a->getSwap() == 2){
            a->setPx(10);
            a->setPy(1);
            a->setSwap(3);
        } else if (a->getSwap() == 3){
            a->setPx(10);
            a->setPy(2);
            a->setSwap(4);
        } else {
            a->setPx(10);
            a->setPy(1);
            a->setSwap(1);
        }
    }

    if (dynamic_cast<Oneal*>(a) != nullptr){
        if(a->getSwap() == 1){
            a->setPx(12);
            a->setPy(0);
            a->setSwap(2);
        } else if (a->getSwap() == 2){
            a->setPx(12);
            a->setPy(1);
            a->setSwap(3);
        } else if (a->getSwap() == 3){
            a->setPx(12);
            a->setPy(2);
            a->setSwap(4);
        } else {
            a->setPx(12);
            a->setPy(1);
            a->setSwap(1);
        }
    }
}
