# Level07


When this level we find a `32 bit executable` owned by the user `flag07` and has setuid bit set

![](/level07/resources/images/type.png)


**objective**
exploit the executable to run commands as `flag07`

**analysis**

executing the binary it outputs the name of the level

![](/level07/resources/images/execute.png)

let's try to analyze more the binary and use `ltrace` to display the library calls made by the program

![](/level07/resources/images/ltrace.png)

well the binary made multiple functions calls : 

1. `getegid()` 
2. `geteuid()`
3. `setresgid()`
4. `setresuid()`
5. `getenv()`
6. `system()`

first idea try to exploit the LOGNAME  variable env inject some code in the variable and it expandes inside the system parameter it gets excuted

some interesting stuff about the function `getenv` when reading the manpage [manpage](https://man7.org/linux/man-pages/man3/getenv.3.html)


it says that The GNU-specific secure_getenv() function is just like getenv() except that it returns NULL in cases where "secure execution" is required.

which means that does not return NULL where "secure execution" is not required

but what is "secure execution" ?




found a function called `asprintf` don't know what its doing let's to find after exploring the first approach

