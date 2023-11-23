#include <vector>
#include <string>

// En el archivo user.h
#ifndef USER_H
#define USER_H

struct Usuario {
  std::string u;
  std::string path;
  std::string text;
  std::string userProfile;
  std::string input;
  std::string output;
  std::vector<int> options;
  std::vector<int> v;
};

#endif // USER_H