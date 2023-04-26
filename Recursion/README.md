Consider the problem of a frog jumping out of a well. Initially, the frog is n feet below the top of the well.
When the frog jumps up, it elevates u feet. 

If a jump gets the frog to the top of the well or past it, the frog escapes the well. 
If not, unfortunately, the frog slips down by d feet before clinging to the side of the well. (Note that d < u.)

Write a recursive function that takes in positive integers, n, u, and d, and 
returns the number of times the frog must jump to get out of the well. 

For example, if n = 10, u = 5 and d = 3, the function should return 4. 
On the first jump, the frog goes from 10 feet below the top to 8 feet below (5-3 is the progress).
On the second jump, the frog goes from 8 feet below the top to 6 feet below the top.
On the third jump, the frog goes from 6 feet below the top to 4 feet below the top.
On the last jump, since 5 feet is enough to clear the top of the well, the frog does not slip down and gets out. 

In this case, had n = 11, the frog would have also gotten out in 4 jumps. 

Note: Although one can do some math to arrive at an O(1) solution without recursion, please use recursion to simulate the jumping process described as this is what is being tested - the ability to take a process and express it in code, recursively. Also, though this is a toy problem, it's surprisingly similar to the real life process of paying off a loan, though in the latter process, the amount you "slip down" slowly decreases, month after month.
