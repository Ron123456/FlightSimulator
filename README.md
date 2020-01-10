# FlightSimulator

Flight Simulator is a C++ program that interpeters a file with commands to [FlightGear](https://www.flightgear.org/) program and executing them.  
This Our project for the second year.  
Creaters : Amit Nir & Ron Sherman
## Installation

Clone the files from the project using the webpage or  by typing:     
```bash  
 git clone http://https://github.com/Ron123456/FlightSimulator
```  
compile the files with g++ and execute the file with the path to the text file to be parsed as an argument:     
```bash
./a.out fly.txt
```

## Usage
There are many commands you can type in the text file:
For example, to open a client that updates variables on port 5402 on localhost type in the text file:  
```connectControlClient("127.0.0.1",5402)```  
Other commands are Sleep,Print,fucntions,defining variables and etc.
