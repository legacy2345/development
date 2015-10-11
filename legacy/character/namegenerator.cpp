/**
 * @file legacy/character/namegenerator.cpp
 * @brief Implementation of the Legacy character name generator submodule.
 */
/*
 * Copyright 2015 Stephen M. Webb <stephen.webb@bregmasoft.ca>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "legacy/character/namegenerator.h"

#include <algorithm>
#include <cerrno>
#include <cstring>
#include <fstream>
#include <iterator>
#include "legacy/config.h"
#include "legacy/random.h"
#include <random>
#include <sstream>
#include <stdexcept>
#include <type_traits>
#include <vector>


Legacy::NameGenerator::
~NameGenerator()
{ }


namespace
{

/**
 * A name generator using a statistical file.
 *
 * The statistical file must contain a list of name entries, one entry per line.
 * The first field on the line is the name, the second is the relative weight,
 * and the rest of the line is ignored.
 */
class StatisticalFileNameGenerator
: public Legacy::NameGenerator
{
private:
  using NameStrings = std::vector<std::string>;
  using NaWeights = std::vector<double>;
  using NameDistribution = std::discrete_distribution<NameStrings::size_type>;

public:
  template<class It>
    StatisticalFileNameGenerator(It const& begin, It const& end)
    {
      static_assert(std::is_base_of<std::string, typename It::value_type>::value, "invalid");

      std::vector<double> weights;
      std::string line;
      std::for_each(begin, end, [&](std::string const& s)
      {
        std::istringstream istr(s);
        std::string        name;
        double             weight;

        istr >> name >> weight;

        names_.push_back(name);
        weights.push_back(weight);
      });

      NameDistribution dist(weights.begin(), weights.end());
      name_distribution_.param(dist.param());
    }

  std::string
  pick_name(Legacy::RandomNumberGenerator& rng)
  {
    return names_[name_distribution_(rng)];
  }

private:
  NameStrings      names_;
  NameDistribution name_distribution_;
};


/** An helper class to enable iteration over an istream line-by-line. */
class Line : public std::string {};

std::istream& operator>>(std::istream& is, Line &l)
{
  std::getline(is, l);
  return is;
}


/** Creates a statistical generator from a file. */
Legacy::NameGenerator::Ptr
create_from_file(std::string const& file_name)
{
  using LineIterator = std::istream_iterator<Line>;
  using Ptr = Legacy::NameGenerator::Ptr;

  std::ifstream infile(file_name);
  if (!infile)
  {
    std::ostringstream ostr;
    ostr << "error " << errno << " opening '" << file_name
         << "': " << std::strerror(errno);
    throw std::runtime_error(ostr.str());
  }
  return Ptr(new StatisticalFileNameGenerator(LineIterator(infile), LineIterator()));
}

} // anonymous namespace


Legacy::NameGenerator::Ptr Legacy::NameGenerator::
create(Legacy::Config const&           config,
       Legacy::NameGenerator::NameType type)
{
  Ptr generator;
  switch (type)
  {
    case NameType::SURNAME:
    {
      std::string file_name = config.find_data_file("dist.all.last");
      if (file_name.length() > 0)
        generator = create_from_file(file_name);
      break;
    }

    case NameType::GIVEN:
    {
      std::string file_name = config.find_data_file("dist.male.first");
      if (file_name.length() > 0)
        generator = create_from_file(file_name);
      break;
    }

    case NameType::MIDDLE:
    {
      std::string file_name = config.find_data_file("dist.male.first");
      if (file_name.length() > 0)
        generator = create_from_file(file_name);
      break;
    }
  }
  return generator;
}

