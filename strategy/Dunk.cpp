//
// Created by liuwangbo on 2021/7/12.
//

#include "Dunk.h"

/*
 * 实现具体的"算法"
 */
void FlyWithWings::fly() {}

void FlyNoWay::fly() {}

void Quack::quack() {}

void Squeak::quack() {}

void MuteQuack::quack() {}

/*
 * 公共方法
 */
void Dunk::display() {}

void Dunk::swim() {}

/*
 * where magic happen
 */
void Dunk::performQuack() {
    quackBehavior->quack();
}

void Dunk::performFly() {
    flyBehavior->fly();
}

void Dunk::setFlyBehavior(FlyBehavior *flyBehavior) {
    this->flyBehavior = flyBehavior;
}

void Dunk::setQuackBehavior(QuackBehavior *quackBehavior) {
    this->quackBehavior = quackBehavior;
}

