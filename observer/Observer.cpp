//
// Created by liuwangbo on 2021/7/13.
//

#include "Observer.h"



void ConcreteSubject::removeObserver(Observer *observer) {
    for (auto _observer : this->observerList){
        if (observer == _observer){

        }
    }
}

void ConcreteSubject::notifyObserver() {

}

void ConcreteSubject::registerObserver(Observer *observer) {
    this->observerList.push_back(observer);
}

