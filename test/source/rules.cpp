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

  switch(line_vec[0])
  {
    case (".dna"):
      r_LookUp.emplace_back(r);
      break;
    
    case (".poly"):
      p_LookUp.emplace_back(r);
      break;

    case (".sample"):
      s_LookUp.emplace_back(d);
      break;

    default:
      //some error
  }

  return;
}
  

  void Rules::build_regions(Seq_Map& m)
  {
    for(auto& r : r_LookUp)
    {
      Region container;
      container.name = r.first;
      container.load_MarkovChain(0.25,0.25,0.25,0.25);
      int i = 1;
      for(auto& v : r.second)
      {
        std::vector<std::string> arg_val = clean_string(v.r_arg, char ' ');

        switch(arg_val[0])
        {
          case ("e"):
            container.size = std::atoi(arg_val[1]);
            break;
          case ("c"):
            container.build_pre(arg_val);
            break;
          case ("m"):
            container.is_mutation = true;
            container.build_pre(arg_val, false);
          case ("n"):
            i = std::atoi(arg_val[1]);
            
            break;
          // case ("~"):
          //   container.fixed = true;
          //   container.preference.emplace_back("fixed");
          //   break;
          // case ("f"):
          //   container.preference.emplace_back("fractions");
          //   container.build_pre(arg_val, true);
          case ("p"):
            container.load_MarkovChain(std::atod(arg_val[1]),std::atod(arg_val[2]),std::atod(arg_val[3]),std::atod(arg_val[4]));
            break;
          default:
            break;
        }
      }
      container.load(m.container_vec);
      for(int j = 0; j<i; ++j)
      {
        m.load_region(container);
        m.size += container.r_size;
      }
    }
  }
    // case (".elem"):
    //   element_LookUp.emplace_back(r);
    //   break;

    // case (".trans"):
    //   trans_LookUp.emplace_back(d);
    //   break;

    // case (".poly"):
    //   poly_LookUp.emplace_back(d);
    //   break;



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


// void Rules::sort_rules()
// {
//   for (auto& i : map_LookUp)
//   {

//   }

//   for (auto& i : poly_LookUp)
//   {
    
//   }

//   // for (auto& i : sample_LookUp)
//   // {
    
//   // }

//   return;
// }


// void Rules::prepare(std::vector<Seq_Map> & m_vec)
// {
//   for (auto& r_dna : map_LookUp)
//   {
//     Seq_Map m;
//     m.name = r_dna.r_name;
//     for (auto& r_con : container_LookUp[r_dna.r_name])
//     {
//       m.load_regions(r_con);
//     }
//     for (auto& r_)

//   }

//   for (auto& i : poly_LookUp)
//   {
    
//   }

//   // for (auto& i : sample_LookUp)
//   // {
    
//   // }

//   return;
// }


//   // if (line_vec[0] == ".dna")
//   // {
//   //   list_of_type.emplace_back(rule_spec::DNA);
//   //   list_of_instructions.emplace_back(line_vec)
//   //   // Map container;
//   //   // container.name = line_vec[1];

//   //   // std::stringstream sstream(line_vec[2]);
//   //   // sstream >> container.size;

//   //   // container.instructions = line_vec[3];

//   //   // map_vec.push_back(container);

//   // }
//   // if (line_vec[0] == ".poly")
//   // {
//   //   Region haploid;
//   //   haploid.name = line_vec[1];
//   //   haploid.instructions = line_vec[2];

//   //   region_vec.push_back(haploid);
//   // }
//   // if (line_vec[0] == ".sample")
//   // {
//   //   Sequence_Builder sample;
//   //   sample.name = line_vec[1];
//   //   sample.instructions = line_vec[2];

//   //   seq_vec.push_back(sample);
//   // }


//   // for (auto& elem : map_vec)
//   // {
//   //   elem.load_values();
//   //   elem.run();
//   // }

//   // for (auto& elem : region_vec)
//   // {

//   // }


//   // for (auto& elem : seq_vec)
//   // {

//   // }

//   // // for (auto& elem : testsequence)
//   // // {
//   // //   std::cout << line_vec[0] << '\t' << line_vec[1] << '\t' << line_vec[3] << '\t' << line_vec[4] << '\n';
//   // // }

  

//   // std::stringstream sstream1(line_vec[1]);
//   // sstream1 >> BED_field.chromStart;
//   // std::stringstream sstream2(line_vec[2]);
//   // sstream2 >> BED_field.chromEnd;
  
//   // BED_field.score = stod(line_vec[5]);
//   // BED_field.strand = line_vec[4][0];

// //   // BED_table.push_back(BED_field);
// // }


// // for(auto & v : specs)
// //   {
// //     switch (v[0])
// //     {
// //       case 's':
// //         trim(v,is_from_range('a','z'));
// //         std::stringstream sstream(v);
// //         sstream >> size;
// //         break;
// //       case 'n':
// //         trim_if(v,is_from_range('a','z'));
// //         trim(v);
// //         number_of_repeatition = std::stoi(v);
// //         break;
// //       case 'file':
// //         trim_left_if(v,is_any_of('c'));
// //         trim(v);
// //         ref_from_other.emplace_back(v);
// //         break;
// //       // case 'e':
// //       //   trim_if(v,is_from_range('a','z'));
// //       //   trim(v);
// //       //   ref_from_other.emplace_back(v);
// //       //   break;
// //       // case 'm':

// //       //   trim(v);
// //       //   break;
// //       // case 'o':
// //       //   /* code */
// //       //   break;
// //       // case 'p':
// //       //   /* code */
// //       //   break;
// //       // case '~':
// //       //   /* code */
// //       //   break;
// //       // case '!':
// //       //   /* code */
// //       //   break;
// //       // case 'f':
// //       //   /* code */
// //       //   break;
// //       // case 'r':
// //       //   /* code */
// //       //   break;