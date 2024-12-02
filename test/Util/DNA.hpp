#pragma once
#include<cstdint>
#include<cstddef>
#include<map>
#include<vector>
#include<string>

struct DNA
{
  std::map<char, uint32_t> to2_int = 
  {
    {'a', 0}, {'A', 0}, {'c', 1}, {'C', 1}, {'g', 2}, {'G', 2}, {'t', 3}, {'T', 3} 
  };

  std::vector<char> to2_char = {'a','c','g','t'};

  uint8_t cast_to(char c){};
  char cast_from(uint8_t i){};

  uint8_t hash_s(const std::string & s){};
  // std::string hash_r(uint8_t i){};
};


