/**
 * @file legacy/config.h
 * @brief Public interface of the Legacy runtime configuration module.
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
#ifndef LEGACY_CONFIG_H_
#define LEGACY_CONFIG_H_

#include "legacy/liblegacy2345.h"

#include <exception>
#include <string>
#include <deque>


namespace Legacy
{

/**
 * A class of exceptions thrown during command-line parsing to indicate
 * processing should not continue (eg. --version passed).
 */
class ExitAfterStartup
: public std::exception
{ };


/**
 * A class for the system-wide runtime configuration values.
 */
class LIBLEGACY2345_API Config
{
public:
  using PathList = std::deque<std::string>;

public:
  Config(int argc, char const* argv[]);

  ~Config();

  /**
   * Finds a data file in the configured paths.
   *
   * @note This function is inherently racy:  don't use it if that matters.
   *
   * @returns the full pathname of the data file found or an empty string
   * if no matching files were found.
   */
  std::string
  find_data_file(std::string const& basename);

private:
  PathList data_paths_;
};

} // namespace Legacy

#endif /* LEGACY_CONFIG_H_ */
