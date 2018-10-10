// Workshop 3 Templates
// KVList.h
// 2018-06-04
// Author Louie Tse
// Student ID 027168103
// Professor Elliot Coleshill
#pragma once
#ifndef _KVLIST_H_
#define _KVLIST_H_
#include <iostream>
using namespace std;

template<typename K, typename V, int N>
class KVList {

	K k[N];
	V v[N];
	int count = 0;

public:
	KVList() { count = 0; }
	size_t size() const {
		return count;
	}
	const K& key(int i) const {
		if (i > N) {
			i = 0;
		}
		return k[i];
	}

	const V& value(int i) const {
		if (i > N) {
			i = 0;
		}
		return v[i];
	}
	KVList& add(const K& kk, const V& vv) {
		if (count < N) {
			k[count] = kk;
			v[count] = vv;
			count++;
		}
		return *this;
	}
	int find(const K& kk) const {
	
		for (int i = 0; i < N; i++) {
			if (k[i] == kk) {
				return i;
			}
		}
		return 0;

	}

	KVList& replace(int i, const K& kk, const V& vv) {
		if (i < count) {
			k[i] = kk;
			v[i] = vv;
		}
		return *this;
	}
};

#endif
