
#include<DNA.hpp>


uint8_t DNA::cast_to(char c)
{
  return to2_int[c];
}

char DNA::cast_from(uint8_t i)
{
  return to2_char[i];
}

uint8_t DNA::hash(const std::string & s)
{
  uint8_t returnvalue = to2_int[s[0]];

  for (uint8_t i = 1; i<s.size(); ++i)
  {
    returnvalue <<= 2;
    returnvalue |= to2_int[s[i]];
  }

  return returnvalue;

}


// std::string DNA::hash_r(uint8_t i)
// {
//   std::string returnvalue = "";

//   while ( i >= 0 )
//   {
//     returnvalue.push_back(to2_char[i%4]);
//     i /= 4;
//   }
//   return returnvalue;
// }

