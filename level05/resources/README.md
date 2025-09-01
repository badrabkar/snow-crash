# Level05

Entering this level we get a message `you have new mail`

![](image.png)

```
Linux typically stores local system emails in files within the /var/spool/mail/ or /var/mail/ directories, with the file name matching the user's username
```

Checking the 2 directories we find `/var/spool/mail` is a symlink to `/var/mail` which contains a file with the level's name

Printing the content of the file we see a cron job line: 

`*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05`

This schedule would run the script **/usr/sbin/openarenaserver** every 2 minutes

![alt text](image-1.png)

The script is owned by `flag05` it does the follwoing instructions:
- loop over every file inside `/opt/openarenaserver/`
- `ulimit -t 5` This ensures that any script can only run for 5 seconds, and with tracing enabled (-x), its execution will be visible then execute the script
- remove the script / file

![alt text](image-2.png)


The vulnerability appears in execution of files inside `/opt/openarenaserver` directory we can create our own script containing the `getflag` command
the script `/usr/sbin/openarenaserver` is owned by **flag05** which will result in executing the `getflag` command and getting the password


## Cracking Process

we will create a script that redirects the output of `getflag` to `/tmp/pass`

```bash
echo "getflag > /tmp/pass" > script.sh
```

waiting 2 minutes `/tmp/pass` gets created

![alt text](image-3.png)

and we get the password for the next level : **viuaaale9huek52boumoomioc**