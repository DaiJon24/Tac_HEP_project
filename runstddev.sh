g++ -c std_deviator.cpp -o std_deviator.o
g++ -c sliding_window.cpp -o sliding_window.o
g++ std_deviator.o sliding_window.o project.cpp -o project
./project
