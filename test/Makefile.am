#
# @file test/Makefile.am
# @brief automake recipe for Legacy 2345 test suite
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

if BUILD_TESTS

check_LIBRARIES = libgmock.a
check_PROGRAMS = gtest_liblegacy2345
TESTS = $(check_PROGRAMS)

nodist_libgmock_a_SOURCES = \
  $(GMOCK_PREFIX)/src/gmock-all.cc \
  $(GTEST_PREFIX)/src/gtest-all.cc

libgmock_a_CPPFLAGS = \
  -Wno-missing-field-initializers \
  $(GMOCK_CPPFLAGS) \
  $(GTEST_CPPFLAGS)

gtest_liblegacy2345_SOURCES = \
  main.cpp \
  test_random.cpp \
  test_sexuality.cpp

gtest_liblegacy2345_CPPFLAGS = \
  -I$(top_srcdir) \
  -I$(top_builddir) \
  $(GMOCK_CPPFLAGS) \
  $(GTEST_CPPFLAGS)

gtest_liblegacy2345_LDADD = \
  $(top_builddir)/legacy/liblegacy2345.la \
  libgmock.a \
  -lpthread

endif
