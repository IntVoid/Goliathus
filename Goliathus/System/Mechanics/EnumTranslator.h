#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

// TODO: Remove EnumTranslator as it was replaced with the override
// of the cout operation.

/* This is a translator design pattern. It is designed to use
templates to help output enumerations as strings. This enables
me to use Enumerators as labels and be able to easily and more
readily expedite outputting values to the user */

// This is the type that will hold all the strings.
// Each enumerate type will declare its own specialization.
// Any enum that does not have a specialization will generate
// a compiler error indication that there is no definition of
// this variable ( as there should be no definition of a generic
// version ).
template<typename T>

struct enumStrings {
	static char const* data[];
};

// This is a utility type.
// Created automatically, this should not be used directly.
template<typename T>
struct enumRefHolder {
	T& enumValue;
	enumRefHolder(T& enumValue) : enumValue(enumValue) {}
};

template<typename T>
struct enumConstRefHolder {
	T const& enumValue;
	enumConstRefHolder(T const& enumValue) : enumValue(enumValue){}
};


// The next two functions do the actual work of reading/writing
// the enumerator as a string.
template<typename T>
ostream& operator<<(ostream& str, enumConstRefHolder<T> const& data) {
	return str << enumStrings<T>::data[data.enumValue];
}

template<typename T>
istream& operator>>(istream& str, enumRefHolder<T> const& data) {
	string value;
	str >> value;

	static auto begin = begin(enumStrings<T>::data);
	static auto end = end(enumStrings<T>::data);

	auto find = find(begin, end, value);
	if (find != end) {
		data.enumValue = static_cast<T>(distance(begin, find));
	}
	return str;
}

// This will be the public interface.
template<typename T>
enumConstRefHolder<T> enumToString(T const& e) {
	return enumConstRefHolder<T>(e);
}

template<typename T>
enumRefHolder<T> enumFromString(T& e) {
	return enumRefHolder<T>(e);
}