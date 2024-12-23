#include "rules.hpp"


std::vector<std::string> Rules::clean_string(std::string & s, char seperator)
{
  std::vector<string> line_vec;
  std::istringstream iss(s);
  std::string field;

  while(std::getline(iss, field, seperator))
  {
    trim(field);
    line_vec.push_back(field);
  }

  return line_vec;
}

void Rules::load_rule(std::string& s)
{
  std::vector<std::string> line_vec = clean_string(s, '\t');

  std::vector<std::string> arg_vec = clean_string(line_vec[2], ',');

  Rule r;
  r.load_args(line_vec[1],arg_vec);

  

    if (line_vec[0] ==".dna"):
      r_LookUp.emplace_back(r);

    
    if (line_vec[0] ==".poly"):
      p_LookUp.emplace_back(r);


    if (line_vec[0] ==".sample"):
      s_LookUp.emplace_back(d);

  return;
}
  

void Rules::build_regions()
{
  Seq_Map m;
  for(auto& r : r_LookUp)
  {
    Region container;
    container.name = r.first;
    container.load_MarkovChain(0.25,0.25,0.25,0.25);
    int i = 1;
    for(auto& v : r.second)
    {
      std::vector<std::string> arg_val = clean_string(v.r_arg, char ' ');

      if(arg_val[0] == "e")
      {
          container.size = std::atoi(arg_val[1]);
      }
      if(arg_val[0] == "c"):
      {
          container.build_pre(arg_val);
      }
      if(arg_val[0] == "m"):
      {
          container.is_mutation = true;
          container.build_pre(arg_val, false);
      }
      if(arg_val[0] == "n"):
      {
          i = std::atoi(arg_val[1]);
          
      }
        // case ("~"):
        //   container.fixed = true;
        //   container.preference.emplace_back("fixed");
        //   break;
        // case ("f"):
        //   container.preference.emplace_back("fractions");
        //   container.build_pre(arg_val, true);
        if(arg_val[0] == "p"):
        {
          container.load_MarkovChain(std::atod(arg_val[1]),std::atod(arg_val[2]),std::atod(arg_val[3]),std::atod(arg_val[4]));
        }
      }
    }
    container.load(m.container_vec);
    for(int j = 0; j<i; ++j)
    {
      m.load_region(container);
      m.size += container.r_size;
    }
    return m;
}

  


void Rules::rule::load_args(std::string & name, std::vector<std::string> & specs)
{
  r_name = name;
  for (auto& v: specs)
  {
    if (v[0] == 'r')
    {
      r_reference = true;
      --r_order;
    }
    r_arg.emplace_back(v);
  }
  
  return;
}
