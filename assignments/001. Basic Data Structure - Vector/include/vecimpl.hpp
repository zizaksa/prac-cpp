#ifndef _VECIMPL_HPP_
#define _VECIMPL_HPP_

#include <vector>

void PushBack(int value);

void PopBack();

int Size();

int GetValue(int idx);

void Clear();

void Sort();

std::vector<int>::iterator Begin();

std::vector<int>::iterator End();

#endif