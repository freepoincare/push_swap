# push_swap


## :writing_hand: Usage

Download files:
```bash
git clone git@github.com:angelin257/push_swap.git <folder_name>
```
Compile the program with:
```bash
make
```

Run the program with the following instructions:

1. Download checker_linux and put it in the root of your program. And allow it to be executable with `chmod u+x checker_linux` or just `chmod +x checker_linux`. 

2. Mandatory part: run your program with one of the following commands:
```bash
./push_swap <list of numbers>
./push_swap "<list of numbers>"
ARG="<list of numbers>" ; ./push_swap $ARG | wc -l                 # check the nr of operations
ARG="<list of numbers>" ; ./push_swap $ARG | ./checker_linux $ARG  # check if your push_swap program is sorting
```
- ARG will not work in fish; so use a normal terminal
- Do the input error management (duplicate, MAX_INT, MIN_INT, malloc error, etc.).

3. Bonus part (make our own checker program). Run the following command. And type the instructions/operations. To stop reading the instruction list, press `Ctrl+D`. It should do error management, false tests, and right tests, and display Error or KO or OK, respectively.
```bash
./checker_linux "<list of numbers>"
```
