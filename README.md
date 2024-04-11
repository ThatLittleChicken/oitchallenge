# OIT Student Programmer Code Challenge
This challenge is written in C++ and includes two files:
- `roman_to_decimal` converts roman numeral to decimal
- `decimal_to_roman` converts decimal to roman numeral

The program assumes that the input are valid roman numerals and is under what the largest roman numeral can represent 
correctly (3999).

## Usage
To use the program, simply execute it and type in a valid decimal / roman numeral and hit enter. The program will print 
the output. 

## Thought Process
### Roman Numeral to Decimal
To convert roman numeral to decimal, we have to iterate through the string of the roman numeral and convert each letter 
to the value it represents.
Doing this means that the best we can do is O(n) (albeit the longest is just a few letters).

First, we need someway to know what value each letter represents. We can create a dictionary using a 
hash table / unordered map to quickly find the value.

Then we iterate through the array of characters as a sliding window looking at two letters each time to get the 
nessasary context.
- When the front letter is larger than the back letter, it will just be normal and we add the front value to the total.
- When the back letter is larger than the front letter, it means it is a 9 or 4 and we have to subtract the front value 
from the total.

### Decimal to Roman Numeral
To convert decimal to roman numeral is less straight forward and we will need a similar dictionary to reference the 
letter. We have to first split the decimal by iterating through the length of the numbers, e.g. 234 as 200 + 30 + 4 and 
from that we separate it into two components, the number value and the multiples of ten, e.g. 200 as 2 * 100. By doing 
this we can just use a few ifs statements, `n` will represent the value and `10^m` will represent the multiples of ten. 
- When `n` is 9 or 4, we concat the letter that represents it's `10^m` and concat a second letter 
which will be subtracted from and is either 10 * `10^m` or 5 * `10^m`.
- When `n` is equal or more than 5, we concat the letter that represents 5 * `10^m` and use a loop to concat the 
remaining letters that represent it's `10^m`.
- When `n` is less than 4 and more than 0, we also use a loop to concat the letters that represent it's `10^m` to add 
value.

As we also have to iterate through the length of the decimal input the best is O(n) (albeit max length of 4). The loop 
for adding values will be a max of three and is basically constant.