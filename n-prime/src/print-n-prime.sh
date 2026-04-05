#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 [number of prime number]"
    exit 1
else
    arg="$1"
    if ! [[ $arg =~ ^[0-9]+$ ]]; then
        echo "Usage: $0 [number of prime number]"
        exit 1
    fi
fi

if [ "$arg" -gt 300 ]; then
    echo "Warning: too big number of prime number. Probably compilation will failed with 'recursive template instantiation exceeded maximum depth of 1024'"
fi

my_dir="$(dirname $0)"

print_n_prime=__print_n_prime_tmp.cpp
print_n_prime_exe=__print_n_prime_tmp
compile_message=__compile_message_tmp

if [ -f "$print_n_prime" ]; then
    rm "$print_n_prime"
fi

cat $my_dir/print_n_prime.1.in >> $print_n_prime
echo -n "$arg" >> $print_n_prime
cat $my_dir/print_n_prime.2.in >> $print_n_prime

clang++ -I"$my_dir" -O3 -DNDEBUG "$print_n_prime" -o "$print_n_prime_exe" 1>$compile_message 2>&1
exit_code=$?
rm "$print_n_prime"
if [ $exit_code -ne 0 ]; then
    cat $compile_message
    rm $compile_message
    echo "Compilation failed with exit code $exit_code"
    exit $exit_code
fi
rm $compile_message

./"$print_n_prime_exe"
exit_code=$?
rm "$print_n_prime_exe"
if [ $exit_code -ne 0 ]; then
    echo "Execution failed with exit code $exit_code"
    exit $exit_code
fi
