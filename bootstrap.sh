#! /bin/bash

sudo apt-get install -y cmake git g++ libgmp-dev
cd /vagrant/build
cmake ..
make gtest
make clean all test
