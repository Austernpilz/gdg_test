#pragma once
#include<string>
// #include<SeqAN3>


#include <algorithm>
#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <map>
#include <random>
#include <vector>

#include <fstream>
#include <sstream>


// #include "../Util/sequence.hpp"
#include "rules.hpp"
#include "seq_map.hpp"
#include "region.hpp"


class gdg {
//look up constructor and shit

  public:
    //in main()
    void set_ref_genom(std::string & s){};
    void read_config_file(std::string & s){};

    void set_size(std::string & s){};
    void run(){};

    void read_rules(std::string & path){};

    void load_output_path(std::string & s){};


    double gdg_size;
    std::string ref_genom;
    std::string config_file;
    std::string output_path;
    bool simple = "true";

};
