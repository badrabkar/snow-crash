# Level09

## Analysis

![](/level09/resources/images/Screenshot%20from%202025-08-15%2009-46-29.png)


![](/level09/resources/images/Screenshot%20from%202025-08-15%2009-48-27.png)

![](/level09/resources/images/Screenshot%20from%202025-08-15%2009-49-31.png)

maybe this level is about cryptography


![](/level09/resources/images/Screenshot%20from%202025-08-15%2009-51-37.png)



if we try with a different file we will not get the same output
but nothing got change in the ltrace output the same library calls are made


![](/level09/resources/images/Screenshot%20from%202025-08-15%2009-53-40.png)

and there is always a `puts` function with the argmuent `you should not reverse this` but its not printed in the console


we changed the content of the file but the output is the same
![](/level09/resources/images/Screenshot%20from%202025-08-15%2009-59-37.png)

let's try to change the name of the file and see if there is any change

![](/level09/resources/images/Screenshot%20from%202025-08-15%2010-02-50.png)

the output is different .


which means the program is kind of similar to the previous one it check the name of the file and does some operation on the name (cipher or hash) and give the output


let's try to create 3 file from a to c and see if there is some type of cipher



![](/level09/resources/images/Screenshot%20from%202025-08-15%2010-08-27.png)

well there is a pattern this `/wcu3hxh{q9` gets repeated and and shift of `11` is applied to name of the file `a` - > `l` ==> `97 -> 108`


which means if we did `ab` we should get `/wcu3hxh{q9lm`

![](/level09/resources/images/Screenshot%20from%202025-08-15%2011-15-31.png)


but we did get `/wcu3hxh{q9lp`


which means if we did `abc` we should get `/wcu3hxh{q9lmn`

![](/level09/resources/images/Screenshot%20from%202025-08-15%2011-19-07.png)


but we did get `/wcu3hxh{q9lnp` the only different part is `lmn` and `lnp`


let's put a visulize the way this using a pen and a paper 
![](/level09/resources/images/Screenshot%20from%202025-08-15%2015-08-03.png)


from the breakdown we can understand why `lnp` when grouping characters together

the program shift by `11` if there is one character
the program dosn't shift by always by `11` it add 1 in each iteration



following this logic let's createa file named token and see if we can get the same output `tpmhr`.




![](/level09/resources/images/Screenshot%20from%202025-08-15%2012-15-26.png) 



