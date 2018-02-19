#pragma once
#include "stdafx.h"

#include <vector>
#include <iostream>
#include <future>
#include <SFML\Graphics.hpp>
#include <thread>
#include <chrono>
#include "GameContext.h"
#include <math.h>

class Animator
{
public:
	Animator();
	~Animator();


	template <class Instance, class Value>
	void AnimateValue(Instance* instance, void (Instance::*function)(Value), Value from, Value to, int milliseconds);
	template <class Instance, class Value>
	void AnimateValue(Instance* instance, void (Instance::*function)(Value, Value), Value from, Value from2, Value to, Value to2, int milliseconds, std::function<void()>&& CallBack = NULL);

};

template<class Instance, class Value>
inline void Animator::AnimateValue(Instance* instance, void(Instance::*function)(Value), Value from, Value to, int milliseconds)
{


	std::thread([instance, function, from, to, milliseconds]() {
		sf::Clock Timer;
		Value newvalue = from;
		Value valueincrease = abs(from - to) / milliseconds;
		int lastelapsed = 0;
		while (1) {
			int elapsed = Timer.getElapsedTime().asMilliseconds();
			if (elapsed > milliseconds) break;
			if (from > to) {
				newvalue -= valueincrease * (elapsed - lastelapsed);
			}
			else {
				newvalue += valueincrease * (elapsed - lastelapsed);
			}
			lastelapsed = elapsed;
			(instance->*function)(newvalue);
		}
	}).detach();
}

template<class Instance, class Value>
inline void Animator::AnimateValue(Instance * instance, void(Instance::* function)(Value, Value), Value from, Value from2, Value to, Value to2, int milliseconds, std::function<void()>&& CallBack)
{
	std::thread([instance, function, from, from2, to, to2, milliseconds, CallBack]() {
		sf::Clock Timer;
		Value newvalue = from;
		Value newvalue2 = from2;
		Value valueincrease = abs(from - to) / milliseconds;
		Value valueincrease2 = abs(from2 - to2) / milliseconds;
		int lastelapsed = 0;
		while (1) {
			int elapsed = Timer.getElapsedTime().asMilliseconds();
			if (elapsed > milliseconds) break;
			if (from > to) {
				newvalue -= valueincrease * (elapsed - lastelapsed);
			}
			else {
				newvalue += valueincrease * (elapsed - lastelapsed);
			}
			if (from2 > to2) {
				newvalue2 -= valueincrease2 * (elapsed - lastelapsed);
			}
			else {
				newvalue2 += valueincrease2 * (elapsed - lastelapsed);
			}
			lastelapsed = elapsed;
			(instance->*function)(newvalue, newvalue2);
		}
		if (CallBack != NULL) {
			CallBack();
		}
	}).detach();
}
