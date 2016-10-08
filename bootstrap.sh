#! /bin/bash

sudo apt-get install -y cmake git g++ libgmp-dev
mkdir -p /vagrant/build
cd /vagrant/build
cmake ..
make gtest
make clean all test
