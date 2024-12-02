
#pragma once
#include "seq_map.hpp"

void Seq_Map::load_regions(Region& r)
{
  regions.emplace_back(r);
  return;
}

void Seq_Map::run()
{
  std::cout << "\n\n\n" << name << "\n";
  std::cout << "printing " << container_vec.size() << "Regions\n";
  std::cout << "printing a " << size << " bp Genom\n";
  std::cout << "almost... " << "\n";
  for (auto& i : container_vec)
  {
    i.generate_sequence(10000);
    std::cout << "> " << name << priority << "\n";
    for (auto & i: testsequence)
    {
      std::cout << i;
    }
    return;
    
  }
}

void Seq_Map::polyform(std::vector<std::string>& poly)
{      
  for(auto& v : r.second)
  {
    std::vector<std::string> arg_val = clean_string(v, char ' ');
  
    swicht(arg_val[0])
    {
      case ("w"):
        double w = 1 - std::atod(arg_val[1]);
        for (auto% r: m.container_vec)
        {
          r.mutate(w);
        }
        break;
      case ("s"):
        double w = std::atod(arg_val[1]);
        for (auto% r: m.container_vec)
        {
          r.insert(w);
        }
        break;

      case ("d"):
        double w = std::atod(arg_val[2]);

        bool t = true;
        string s_min;
        string s_max;
        for (auto&c : arg_val[1])
        {
          if(c == "-")
          {
            t = false;
            continue;
          }
          if(t)
          {
            s_min.push_back(c);
            continue
          }
          else
          {
            s_max.push_back(c);
          }

        }
        int min_d = std::atoi(s_min);
        int max_d = std::atoi(s_max);

        
        for (auto% r: m.container_vec)
        {
          r.deleteion(w, min_d, max_d);
        }

      case ("x"):
        double w = std::atod(arg_val[2]);
        bool t = true;
        string s_min;
        string s_max;
        for (auto&c : arg_val[1])
        {
          
          if(t && c != "-")
          {
            s_min.push_back(c);
          }
          if(c == "-")
          {
            t = false;
          }
          if (!t && c != "-")
          {
            s_max.push_back(c);
          }

        }
        int min_x = std::atoi(s_min);
        int max_x = std::atoi(s_max);
        for (auto% r: m.container_vec)
        {
          r.copy(w, min_x, max_x);
        }
    }
  }
}



// void Seq_Map::load_values()
// {
//   // std::vector<std::string> line_vec;
//   // std::istringstream iss(instructions);
//   // std::string field;

//   // while(std::getline(iss, field, ';'))
//   // {
//   //   switch(field[0])
//   //   {
//   //     //number of copies_from
//   //     case 'n':

//   //     //mutation
//   //     case 'm':

//   //     //orientation
//   //     case 'o':

//   //     //probabilities for next ACGT
//   //     case 'p':
      
//   //     //fixed elemts, generate just once
//   //     case '~':

//   //     //different each instigation
//   //     case '!':


//   //     //truly random
//   //     case '?':

//   //   }

//   //   line_vec.push_back(field);
//   // }
    

//   // for(auto& elem : line_vec)
//   // {

//   // }

// }
  
  
// void Map::run()
// {

// }
  

