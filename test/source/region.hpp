// #include<string>
#pragma once
#include "DNA.hpp"
// #include "sequence.hpp"
#include "../Util/markov_chain.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>
// #include "rules.hpp"


class Region
{
  public:
    std::string name;
    std::string reference;
    double r_size = 0;
    bool fixed = false;
    bool is_mutation = false;
    unsigned priority = 42;

    void generate_sequence(){};

    void build_pre(std::vector<std::string>& argv){};
    void build_pre(std::vector<std::string>& argv, bool b){};


    std::map<uint8_t, std::map<char, double> > markovchain;
    std::vector<std::string> preferences;
    std::vector<double> mutations;


    std::vector<char> testsequence = {'A', 'C', 'G', 'T'};

    void load_MarkovChain(double a, double c, double g, double t){};
    void load_MarkovChain(std::string & s){};
    void generate_sequence(std::string & s){};
    void generate_sequence(int length, int kmer){};
    void generate_sequence(int length){};
    void load(std::vector<Region> & reg_vec);
    void mutation(double m){};
    void insert(double m){};
    void deletion(double m, int min_d, int max_d){};
    void copy(double m, int min_x, int max_x){};

};

