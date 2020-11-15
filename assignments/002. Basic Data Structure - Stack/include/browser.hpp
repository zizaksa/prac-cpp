#ifndef _BROWSER_HPP_
#define _BROWSER_HPP_

#include <string>

void GoPage(std::string page);

void GoBack();

std::string GetCurrentPage();

int GetNumPages();

void Clear();

#endif