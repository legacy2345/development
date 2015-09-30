/**
 * @file test/test_config.cpp
 * @brief Unit tests for liblegacy2345 runtime config module.
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
#include <gtest/gtest.h>
#include "legacy/config.h"

#include <stdlib.h>

#ifndef TOP_SRCDIR
# define TOP_SRCDIR "."
#endif


/**
 * Verify defaults.
 */
TEST(Config, Defaults)
{
  Legacy::Config config(0, nullptr);
}


/**
 * Verify a help message is provided and it exits without further processing.
 */
TEST(Config, Help)
{
  char const* argv[] = { "test", "--help", nullptr };
  ASSERT_THROW(Legacy::Config config(sizeof(argv)/sizeof(char const*) - 1, argv),
               Legacy::ExitAfterStartup);
}


/**
 * Verify a version message is provided and it exits without further processing.
 */
TEST(Config, Version)
{
  char const* argv[] = { "test", "--version", nullptr };
  ASSERT_THROW(Legacy::Config config(sizeof(argv)/sizeof(char const*) - 1, argv),
               Legacy::ExitAfterStartup);
}


/**
 * Verify finding a data file using command-line options.
 */
TEST(Config, FindDataFileByOptions)
{
  char const* argv[] = { "test", "--datapath=" TOP_DATADIR, nullptr };
  Legacy::Config config(sizeof(argv)/sizeof(char const*) - 1, argv);

  ASSERT_EQ(config.find_data_file("names/dist.all.last"),
            std::string(TOP_DATADIR "/names/dist.all.last"));
}


/**
 * Verify finding a data file using environment variable.
 */
TEST(Config, FindDataFileByEnvironment)
{
  putenv("LEGACY_DATAPATH=" TOP_DATADIR);
  Legacy::Config config(0, nullptr);

  ASSERT_EQ(config.find_data_file("names/dist.all.last"),
            std::string(TOP_DATADIR "/names/dist.all.last"));
}

