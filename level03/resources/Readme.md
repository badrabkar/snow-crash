### level03

When entering this level we find a 32-bit executable named level03 owned by the user `flag03` and the setuid bit is set `-rws`, which means we can execute it with the same privilage as the user `flag03`.

![](/level03/resources/images/file_permissions.png)

![](/level03/resources/images/file_type.png)


Running the program a message gets printed "Exploit me". Challenge accepted.

![](/level03/resources/images/Screenshot%20from%202025-08-09%2016-11-44.png)

Let's see the function calls made by this program using `ltrace` 

![](/level03/resources/images/Screenshot%20from%202025-08-09%2016-16-11.png)



```c
#include <stdlib.h>

int main() {

  system("getflag"); 

  return 0;
}
````