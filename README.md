### Get next line function
A function, that reads from the provided fd and returns the read lines.
If there is still something to read in the fd, it returns 1, if there is
nothing left to read, it returns 0, it returns -1 in case of error.
The read line is stored in the provided pointer area.
