# Fibonacci Algorithms

Western University - CS3340B Winter 2021 - Assignment 1

F(n) = the nth Fibonacci number

## Usage
* `make` - compiles the program
* `make runA` - Calculates and prints every 5th Fibonacci number up to F(50) using an inefficient recursive algorithm in exponential O(2^n) time.
* `make runB` - Calculates and prints every 20th Fibonacci number up to F(500) in O(n) time
* `make runB_flex` - Calculates and prints every 20,000th Fibonacci number up to F(100,000) in O(n) time
* `./asn1_b max printFactor` Allows for custom inputs. Max is the highest Fibonacci number to calculate, and every F(n) where n is divisible by printFactor will be printed. eg. `./asn1_b 75000 5000` This will only be accurate up to approximately F(100,000) unless digitCapacity is changed in BigInt.h lines 11 & 12.
* `make clean` - cleans up when finished
