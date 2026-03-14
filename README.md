_This project has been created as part of the 42 curriculum by lheteau._  
_We are the 08 March 2025._

# Push_swap
![Previsualisation of the output (simple input)](https://github.com/user-attachments/assets/89cd4950-32d5-4e9a-90e8-d3b3ed159a04)
### Table of contents
***
1. _Description_
2. _Instructions_
3. _Ressources_
4. _Tips_

***
## **Description**
***
• Push_swap is a sorting utility developed in C. The goal is to tackle algorithm complexity (O(n)) and data structure manipulation through the optimization of sorting operations.

It validates a list of integers before converting them into linked list of nodes.

It utilizes two stacks and a specific set of operations (swaps, pushes, and rotations) to sort data efficiently, selecting hardcoded optimal moves for small sets or a Binary Radix Sort for larger datasets.
***
• The Radix Sort processes numbers bit by bit from the least to the most significant bit based on their relative indices. 

During each pass, the algorithm inspects a specific bit of the top element in stack_a: if the bit is 1, the element is rotated to the bottom (ra); if it is 0, it is pushed to stack_b (pb). 

After checking every element for that bit, all values are pushed back to stack_a (pa), progressively organizing the stack until it is fully sorted.X
***
• To see the result of the stack, we can implement the following part at the end of the main function:
```
t_stack	*ptr;

ptr = stack_a;
	ft_printf("\n\n VALUE A --F\n");
	while (ptr)
	{
		ft_printf("value a %d\n", (int)ptr->value);
		ptr = ptr->next;
	}
```

## **Instructions**
***
• To use it in your own project, include the header:  
```#include "push_swap.h"```.

To compile the project :  
```make```  

• And to execute it :  
```./push_swap <argv>```

You can also generate a list of random numbers of a specific size by running the following command:
```
ARG=$(shuf -i <between int min>-<and int max> -n <size list>); ./push_swap $ARG
```
***
• The engine performs the following strict validations before launch:
- Checks if the arguments are numbers
- Ensure there is no duplicates
- Confirms there are at least 2 numbers to be sorted
- At the same time checks for void parameter
- Ensure that the numbers are between int_max and int_min
- Finaly, test if the sequenc eis already sorted

## **Ressources**
***
• [Explanation of Radix sort (article): ](https://www.geeksforgeeks.org/dsa/radix-sort/) A fundamental resource for understanding how the algorithm works.

[CS Dojo's introduction to Radix (video):](https://www.youtube.com/watch?v=XiuSW_mEn7g) As before, it explains the Radix Sort algorithm in a similar fashion.  

***
• Artificial Intelligence tools were used in the writing and structuring of this README.
***
• To push the project to its highest standard, the following push_swap testers were instrumental in identifying edge cases and validating the robustness of the parsing engine: 

[gemartin99's Push_swap-Tester: ](https://github.com/gemartin99/Push-Swap-Tester#)

And finally to calculate my final score, [SimonCROS's push_swap_tester](https://github.com/SimonCROS/push_swap_tester) was useful.

## **Tips**
***
![Previsualisation of the consum test](https://github.com/user-attachments/assets/bedc96b8-181d-48cc-867c-d913cfcf84bb)
• To monitor my program's memory consumption, insert the following section into the main function:
```
#include <stdint.h>
while (1) 
    {
        sleep(1); // Infinite loop: the program will never stop on its own.
    }
```

Then run this command:
```
htop -p $(pgrep ./push_swap)
```

Finally, calculate RES - SHR to determine the private memory usage.

<a href="https://www.linkedin.com/in/laura-heteau/" target="_blank"><img align="center" alt="LinkedIn" height="60" src="https://user-images.githubusercontent.com/81205527/157161849-01a9df02-bf32-45be-add4-122bc40b48cf.png"></a>
<a href = "mailto:laura.heteauu@gmail.com"> <img align="center" alt="Gmail - laura.heteauu@gmail.com" height="60" src="https://user-images.githubusercontent.com/81205527/157161831-eb9dffee-404b-4ffe-b0af-34671219f7fb.png"></a>
