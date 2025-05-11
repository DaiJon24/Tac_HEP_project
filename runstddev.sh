g++ -c std_deviator.cpp -o std_deviator.o
g++ -c sliding_window.cpp -o sliding_window.o
g++ std_deviator.o sliding_window.o std_deviator_test.cpp -o std_deviator
./std_deviator
