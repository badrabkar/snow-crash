# Level 04


## Analysis
Entering this level, we find a Perl script with the setuid and setgid bits set.

![alt text](/level04/resources/images/image.png)
![](/level04/resources/images/image-2.png)

Showing the content of the file we can see this is a cgi script running on port **4747**
it uses the `param` function for retrieving values submitted through HTML forms, typically from GET or POST requests.

In our case `x(param("x"))` would retrieve the value associated with the **x** field and pass it to the `x()` function

the `x` function takes the first argument `$_[0]` and prints it using `echo`

```perl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

![alt text](/level04/resources/images/image-3.png)


The vulnerability appears in the command execution since the input is passed directly into backticks without sanitization, arbitrary shell commands can be injected. We can inject `getflag` command inside **$y** and get the password.

## Cracking process

we inject this string `test;getflag` in a URL-encoded format `test%3Bgetflag` to prevent the shell from treating the `;` as a command seprator and the web server correctly passes the `; `character to the script.

![alt text](/level04/resources/images/image-7.png)


and we get the password for the next level: **ne2searoevaevoem4ov4ar8ap**

## Conclusion
This level highlights the risks of unsanitized input in Perl CGI scripts, which can easily lead to command injection.
