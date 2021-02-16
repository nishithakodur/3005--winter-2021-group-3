// zip eclipse-workspace where the Game of life code exists through terminal
tar -czvf eclipse-workspace.tar.gz eclipse-workspace

//using "sftp" transfer the code to beaglebone

> sftp debian@192.168.7.2
debian@192.168.7.2's password: 
Connected to 192.168.7.2.
sftp> put eclipse-workspace.tar.gz
Uploading eclipse-workspace.tar.gz to /home/debian/eclipse-workspace.tar.gz
eclipse-workspace.tar.gz                      100% 1325KB   3.0MB/s   00:00    
sftp> exit

//Login to debian 
> ssh debian@192.168.7.2

//Listing the files in home
debian@beaglebone:~$ ls
bin	 eclipse-workspace	   lab		test_service	udev.tar.gz
Desktop  eclipse-workspace.tar.gz  testservice	test_service.c

//Changing directory to eclipse-workspace
debian@beaglebone:~$ cd eclipse-workspace

//Lisiting the files in eclipse-workspace
debian@beaglebone:~/eclipse-workspace$ ls
ADLX345  Game of Life  pthread	Thread

//Changing directory to Game of life and listing the files under it
debian@beaglebone:~/eclipse-workspace$ cd Game\ of\ Life
debian@beaglebone:~/eclipse-workspace/Game of Life$ ls
cells.c  cells.h  Debug  display.c  display.h  gol.c  gol_config.h

//Compiling and executing the code
debian@beaglebone:~/eclipse-workspace/Game of Life$ gcc gol.c cells.c display.c -pthread -lcurses
debian@beaglebone:~/eclipse-workspace/Game of Life$ ls
a.out  cells.c	cells.h  Debug	display.c  display.h  gol.c  gol_config.h
debian@beaglebone:~/eclipse-workspace/Game of Life$ ./a.out 



