#include "Region.hpp"

void Reagion::load_MarkovChain(double a, double c, double g, double t)
{
  Markov_Chain m;
  m.build_markov_chain(a,c,g,t);
}
void Reagion::load_MarkovChain(std::string & s)
{

  Markov_Chain m;
  std::string input_file_name = s;
  KMC::InputFileType input_file_type = KMC::InputFileType::MULTILINE_FASTA;
  std::string output_file_name = "4mers";
  int threads = 16;
  
  m.build_kmer_db(input_file_name, input_file_type, output_file_name, threads);

  markovchain = m.build_markov_chain(output_file_name, threads);
}

void Region::build_pre(std::vector<std::string>& argv)
{
  for (uint8_t = 1; i<argv.size(); ++i;)
  {
    preferenece.emplace_back(argv[i]);
  }
}

void Region::build_pre(std::vector<std::string>& argv, bool b)
{
  // if (b)
  // {
  //   for (uint8_t = 1; i<argv.size(); ++i;)
  //   {
  //     fractions.emplace_back(argv[i]);
  //   }
  // }
  // else
  // {
    for (uint8_t = 1; i<argv.size(); ++i;)
    {
      mutations.emplace_back(argv[i]);
    }
  // }
}
void Region::generate_sequence(std::string& s, int kmer)
{
  generate_sequence(size, kmer);
}


void Region::generate_sequence(int length)
{
  generate_sequence(length, 1);
}

void Region::generate_sequence(int length, int kmer)
{
  DNA d;
  int l = std::min(length, 10000);
  for (int i = 0; i<l; ++i)
  {   
    std::vector<double> probal;
    std::vector<char> picks;

    std::string str = std::string(testsequence.end()-kmer, testsequence.end());
    uint8_t hashval = d.hash(str);
    
    for(const auto& elem : markovchain[hashval])
    {
      picks.push_back(elem.first);
      probal.push_back(elem.second);
    }
    
    //probably slow but good
    std::mt19937 gen(std::random_device{}());
    std::discrete_distribution<std::size_t> d{probal.begin(), probal.end()};

    auto sampled_value = picks[d(gen)];
    // std::cout<< sampled_value << '\n';

    testsequence.push_back(sampled_value); 
  }
  

}


void Region::load(std::vector<Region> & reg_vec)
{
  if (fixed)
  {
    generate_sequence(size, 1);
  }

  for (int i = 0; i < preferences.size(); ++i)
  {
    for (auto& r : reg_vec)
    {
      if (preferences[i] == r.name)
      {
        markovchain = r.markov_chain;
        testsequence = r.testsequence;
        
        if (mutations)
        {
          double m = mutations[i];
          mutate(m);
        }

        if (r.testsequence.size()>4)
        {
          generate_sequence(0, 1);
        }
        generate_sequence(r.r_size, 1);
        r_size += r.r_size;
      }
    }
  }
}
  
void Region::mutate(double m)
{
  m = m*100;
  for (auto& n : test_sequence)
  {
    DNA d;
    int s = rand() % 100 +1;
    if (s < m)
    {
      std::vector<double> probal;
      std::vector<char> picks;
      uint8_t hashval = d.hash(n);
      for(const auto& elem : markovchain[hashval])
      {
        picks.push_back(elem.first);
        probal.push_back(elem.second);
      }
      std::mt19937 gen(std::random_device{}());
      std::discrete_distribution<std::size_t> d{probal.begin(), probal.end()};

      n = picks[d(gen)];
    }
  }  
}

void Region::insert(double m)
{
  m = m*100;
  for (int i=0; i< test_sequence.r_size();++i)
  {
    DNA d;
    int s = rand() % 100 +1;
    if (s < m)
    {
      std::vector<double> probal;
      std::vector<char> picks;
      uint8_t hashval = d.hash(test_sequence[i]);
      for(const auto& elem : markovchain[hashval])
      {
        picks.push_back(elem.first);
        probal.push_back(elem.second);
      }
      std::mt19937 gen(std::random_device{}());
      std::discrete_distribution<std::size_t> d{probal.begin(), probal.end()};

      auto sampled_value = picks[d(gen)];
      test_sequence.insert(i, sampled_value);
    }
  }  
}


void Region::copy(double m, int min_x, int max_x)
{
  m = m*100;
  std::vector<std::vector<char>> copy_stack;
  for (int i=0; i< test_sequence.size();++i)
  {
    int s = rand() % 100 +1;
    if (s < m && (i+max_x) < test_sequence.size())
    {
      int x = rand() % max_x + min_x;
      std::vector<char> kmer;
      kmer.insert(kmer.begin(), test_sequence.begin()+i, test_sequence.end()+x);
      copy_stack.emplace_back(kmer);
    }
  } 

  for (auto& kmer_ins : copy_stack)
  {
    int s = rand() % (test_sequence.size()-kmer_ins.size());
    if (s+kmer_ins.size() < test_sequence.size())
    {
      test_sequence.insert(test_sequence.begin()+s, kmer_ins.begin(), kmer_ins.end());
      copy_stack.emplace_back(kmer);
    }
  }  
}


void Region::deletion(double m, int min_d, int max_d)
{
  m = m*100;
  std::vector<int> pos;
  for (int i=0; i< test_sequence.size();++i)
  {
    int s = rand() % 100 +1;
    if (s < m && (i+max_d) < test_sequence.size())
    {
      int x = rand() % max_d + min_d;
      pos.emplace_back(i);
      pos.emplace_back(i+x);
      i += x;
    }
  }

  std::vector<std::vector<char>> stack;
  int pos1 = 0;
  std::vector<char> front;
  front.insert(front.begin(), test_sequence.begin(), test_sequence.begin()+pos[0]);


  for (unsigned i = 1; i < pos.size(); ++i)
  {
    std::vector<char> back;
    int pos1 = pos[i];
    int pos2 = pos[i+1];

    back.insert(back.begin(), test_sequence.begin()+pos1, test_sequence.begin()+pos2);
    stack.insert(back);
    ++i;

  }

  for (auto&v : stack)
  {
    std::move(v.begin(), v.end(), std::back_inserter(front));
  }
}

  // std::map<uint8_t, std::map<char, double> > markovchain;
  // markovchain = testchain.build_markov_chain(output_file_name, threads);


  // std::vector<char> testsequence = {'A', 'C', 'G', 'T'};
  // int length = 10000;


  // // std::cout << "Testsequence before " << '\n';
  // // for (auto& elem : testsequence)
  // // {
  // //     std::cout << elem;
  // // }

  // generate_sequence(markovchain, testsequence, length);
void Region::load_instructions(Rules::rule & d)
{
  name = d.name;

  if(d.reference)
  {
    reference = d.reference;
    if (d.reference_for_copy)
    {
      run_from_reference = true;
    }
    else
    {
      if (d.is_reference_file)
      {
        load_MarkovChain(d.reference)
      }
      else
      {
        
      }
    }
  }
  else
  {

  }
}