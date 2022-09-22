#!/bin/bash

set -xe

g++ -Wall -std=c++17 depthfirst.cpp node.cpp -o depthfirst.bin
