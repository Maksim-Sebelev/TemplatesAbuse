# Templates Abuse

!["Мысли вне шаблонов, детка!"](./assets/thoughts_beyound_templates.jpeg)

In this repo i have played with c++ templates.

## Install

```shell
git clone https://github.com/Maksim-Sebelev/TemplatesAbuse.git && 
cd TemplatesAbuse &&
cmake -S . -B build &&
cd build &&
cmake --build .
```

*cmake will generate release version by default*

## N-PRIME

The first joke, is calculating n-th prime number on c++ templates.

**Usage:**

```shell
./print-n-prime <number of prime number>
```

This is the bash script, which generates C++ program, compiles it and executes.

If number is too big, probably compilation will failed with recursive "template instantiation exceeded maximum depth of 1024".
So this program can`t calculate prime number with number greater then 166.

## Tests

```shell
ctest
```
