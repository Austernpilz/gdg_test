#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "region.hpp"
#include "seq_map.hpp"
// #include "values.hpp"
#include "../Util/DNA.hpp"
// #include "sequence.hpp"


class Rules
{
  public:
    Rules();

    ~Rules();

    void load_rule(std::string& s){};

    void build_region(Seq_Map & m, Rules & r){};

    std::vector<std::string> string_to_arglist(std::string & s, char seperator){};


   

    // void prepare(std::vector<Seq_Map> & m_vec){};

    struct Rule
    {
      std::string r_name;
      std::vector<std::string> r_arg;
      
      void load_args(std::string & name, std::string & specs){};
    };

    std::map<std::string, std::vector<Rules::Rule>> r_LookUp;
    std::map<std::string, std::vector<Rules::Rule>> p_LookUp;
    std::map<std::string, std::vector<Rules::Rule>> s_LookUp;
    // void sort_rules(){};
  // protected:

      
  // private:
    
    
    // std::vector<rule> map_LookUp;
    // std::vector<rule> region_LookUp;


    // std::vector<rule> element_LookUp;
    // std::vector<rule> poly_LookUp;
    // std::vector<rule> sample_LookUp;

//reads müssen nochmal definiert werden
    // struct sample_rule{
    //   std::string name;

    //   std::string file_path;

    //   std::vector<std::string> reference_names;
    //   std::vector<double> reference_shares;
    // };


};






      // std::vector<std::string> transitions;

      

      // unsigned number_of_repetition;
      // unsigned length_of_repetition;
      // double prob_of_repetition;


      // //relevant for .poly
      // unsigned length_of_inserts_min;
      // unsigned length_of_inserts_max;
      // double prob_of_inserts;

      // unsigned length_of_deletions_min;
      // unsigned length_of_deletions_max;
      // double prob_of_deletions;

      // unsigned length_of_copies_min;
      // unsigned length_of_copies_max;
      // double prob_of_copies;


      // bool reference;
      // bool reference_for_copy;
      // bool is_reference_file;

      // bool fixed;
      // bool orientation;