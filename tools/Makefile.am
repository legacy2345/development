#
# @file tools/Makefile.am
# @brief automake recipe for Legacy 2345 tools
#
# Copyright 2015 Stephen M. Webb  <stephen.webb@bregmasoft.ca>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

bin_PROGRAMS = test_name_generation

test_name_generation_SOURCES = \
  test_name_generation.cpp

test_name_generation_CPPFLAGS = \
  -I$(top_srcdir) \
  -I$(top_builddir)

test_name_generation_LDADD = \
  $(top_builddir)/legacy/liblegacy2345.la

