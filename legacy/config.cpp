/**
 * @file legacy/config.cpp
 * @brief Implmentation of the Legacy runtime configuration module.
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
#include "legacy/config.h"

#include <getopt.h>
#include <iostream>
#include "legacy_config.h"
#include <unistd.h>


namespace Legacy
{

Config::
Config(int argc, char const* argv[])
: data_paths_{ "./data" }
{
  char* env_data_path = getenv("LEGACY_DATAPATH");
  if (env_data_path)
    data_paths_.push_front(env_data_path);

  static option long_options[] = {
    { "datapath", required_argument,  0, 'd' },
    { "help",     no_argument,        0, 'h' },
    { "version",  no_argument,        0, 'V' },
    {  nullptr,   0,                  0,  0  }
  };

  ::optind = 1;
  while (true)
  {
    int option_index = 0;
    int c = getopt_long(argc, const_cast<char**>(argv), "d:hV", long_options, &option_index);
    if (c < 0)
      break;

    switch (c)
    {
      case 'd':
        data_paths_.push_front(::optarg);
        break;

      case 'h':
        std::cerr << "usage: " << argv[0] << " [ --datapath=DATA_PATH ]\n";
        throw ExitAfterStartup();
        break;

      case 'V':
        std::cerr << argv[0] << " version " << PACKAGE_VERSION << "\n";
        throw ExitAfterStartup();
        break;

      default:
        std::cerr << "?? getopt returned character code '" << (char)c << "'\n";
    }
  }
}


Config::
~Config()
{ }


std::string Config::
find_data_file(std::string const& basename) const
{
  for (auto const& path: data_paths_)
  {
    std::string full_name = path + "/" + basename;
    if (0 == ::access(full_name.c_str(), R_OK))
      return full_name;
  }
  return "";
}


} // namespace Legacy

