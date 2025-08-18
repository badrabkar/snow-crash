# Level 10

## Analysis

Entering this level we list files in the directory we found 2 files:
- 32-bit executable owned by `flag10` with suid bit set
- a regular file containing some data named `token` with no read and write permissions for us, which likely containing the `flag`

![alt text](/level10/resources/images/image.png)

Executing the program without arguments results in message that we should provide a `file` and a `host`

Let's pass the `token` file and the **loop back address** as the `host`. Since we don't the read permission for the file

![alt text](/level10/resources/images/image-7.png)


Let's create a file with some data and retry 

![alt text](/level10/resources/images/image-8.png)

The program tries to connect to the port 6969, but there is nothing to connect to


We can listen to upcomming connection on port `6969` using `nc` netcat

![alt text](/level10/resources/images/image-11.png)
![alt text](/level10/resources/images/image-10.png)

The program connected to the port and wrote something that look like a face or a regex pattern and  the content of the file 

Let's trace the library calls made by the program to understand what it does

![alt text](/level10/resources/images/image-15.png)


Here is the major instructions done by the program : 

- Checks if we have read permission of file passed
- Creates a socket 
- Connect to a listening socket on port `6969`
- writes the regex pattern
- opens the file with readonly mode
- reads the data contained in the file and write it to the  socket

reading through the access function's [linux manpage](https://man7.org/linux/man-pages/man2/access.2.html) we find an interesting things

It says that the access function do the check of whether we have access to the file using the calling process's real UID,
**which is the reason why we couldn't access the token through the executable with suid bit set** in the opposite the open doesn't check for the calling process' real UID **which means we can create a fake file to bypass the access function then replace it with our target file `token`**


![](/level10/resources/images/image-2.png)

but how we make this swap knowing that instructions are executed instantly ?
The answer to this question is in the follwing warning found in the manapage


![](/level10/resources/images/image-1.png)

This vulnerability is called **Time-of-Check to Time-of-Use (TOCTOU)** is a class of software vulnerabilities that arise from race conditions. These vulnerabilities occur when there is a time gap between the checking of a system's state and the use of the results of that check. During this interval, an attacker can alter the state of the system, leading to unauthorized actions or security breaches.

## Cracking Process


To exploit this vulnerability we are going use threads for concurency


![image showing how code](/level10/resources/images/image-6.png)
 
![](/level10/resources/images/image-9.png)


![alt text](/level10/resources/images/image-12.png)
![alt text](/level10/resources/images/image-13.png)

We got the flag `woupa2yuojeeaaed06riuj63c` we switch to `flag10` run  getflag and we get the password for the next level `feulo4b72j7edeahuete3no7c`



## Read more

https://superuser.com/questions/1008348/netcat-keep-listening-for-connection-in-debian

https://man7.org/linux/man-pages/man2/access.2.html

https://stackoverflow.com/questions/11525164/what-is-wrong-with-access

https://stackoverflow.com/questions/14333112/access2-system-call-security-issue

