## Data declaration section 
.data
# these are globals
  # array of word long ints
  myarray:    .word 23, 4, 34, 55, 87, 24, 99, 12, 233, 45, 43245, 23, 45, 68, 69
  mysize:     .word 15

.text ## Assembly language instructions go in text segment 
j main # very first, goto main.

bubblesort:
   # inputs:
   # ra must be set before calling this and contain the location to where this will return after execution
   # a0 must be the base address of the array of integers to print
   # a1 must be the size of the array to print (or the number of elements in the array to print)
   # outputs: only output is the system "display", no return values
   # saved registers: no need as this internally only uses t registers
   #
   # internal register uses
   # t0 = address of base of myarray from input $a0
   # t1 = value of mysize from input $a1
   # t2 is used to put address, once calculated of array[index]
   # t3 is used to put address, once calculated of array[index + 1]
   # t4 is used to put the value of array[index]
   # t5 is used to put the value of array[index + 1]
   # t6 bool hold comparison result between t2 and t3
   # t7 bool hasChanged. Keep track of if changes have been made in array
   # t8 is used to hold comparison result
   # t9 = index into array 
  add $t0 $0 $a0  # move a0 to t0 via an add statement
  move $t1 $a1    # move a1 to t1 via the move command
  # either of the above commands work. Before you choose, look at the 
  #   assembled version of each command
  
  #################################################################################
  #print array (unsorted)
  add $t9 $0 $0   # initialize the counter before the loop
  printunsorted:
    #do stuff
    sll $t2 $t9 2   # multiply index by 4
    add $t2 $t0 $t2 # add base address of array to 4*index
    lw $a0 0($t2) # put value of myarray[index] into a0
    
    li $v0, 1 # load instruction 1 (print an int whose value is in a0)
    syscall
    
    li $v0, 11        #load instruction 11 (print single char whose value is in a0)
    addi $a0, $0, 0x20  #load ascii char 32 = 0x20 = 'space'
    syscall
    
    addi $t9 $t9 1  # increment counter 
    slt $t8 $t9 $t1  # compare counter t9 to size t1
    bne $t8 $0 printunsorted # loop if $t9 < size
  #end printsorted
  li $v0, 11        #load instruction 11 (print single char whose value is in a0)
    addi $a0, $0, 0x0A  #load ascii char 32 = 0x0A = 'new line'
    syscall
  #################################################################################
  addi $t1 $t1 -1 #loop for (size - 1)
  outer:
    move $t7 $0   # set default value of register inside beginning of outer do-while loop     
    
    add $t9 $0 $0   # initialize the counter before the loop
    inner:
      #do stuff
      sll $t2 $t9 2   # multiply index by 4
    
      add $t2 $t0 $t2 # add base address of array to 4*index
      addi $t3 $t2 4 #place address of myarray[index + 1] in t3
    
      lw $t4 0($t2) # put value of myarray[index] into t2 ### change from    lw $a0 0($t2) # put value of myarray[index] into t2 #which is used to be able to call print syscall, which uses $a0
      lw $t5 0($t3) #put value of myarray[index + 1] into t3
    
      slt $t6 $t5 $t4 #compare myarray[index + 1] < myarray[index]
      beq $t6 $0 noswap # don't swap if in correct relative location 
      #swap
      sw $t5 0($t2) # myarray[index] = myarray[index + 1]
      sw $t4 0($t3) # myarray[index + 1] = myarray[index] (value before swap)
      addi $t7 $t7 1   # set default value of register inside beginning of outer do-while loop
      noswap:#skipped past swap operations
    
      addi $t9 $t9 1  # increment counter
      slt $t8 $t9 $t1  # compare counter t9 to size t1
      bne $t8 $0 inner # loop if $t9 < size
    #end inner
    bne $t7 $0 outer # loop if $t0 != 0 (hasChanged)
  #end outer
  #################################################################################
  addi $t1 $t1 1 #reset size of loop counter
  #print array (sorted)
  add $t9 $0 $0   # initialize the counter before the loop
  printsorted:
   #do stuff
    sll $t2 $t9 2   # multiply index by 4
    add $t2 $t0 $t2 # add base address of array to 4*index
    move $a3 $a0
    lw $a0 0($t2) # put value of myarray[index] into a0
    
    li $v0, 1 # load instruction 1 (print an int whose value is in a0)
    syscall
    
    li $v0, 11        #load instruction 11 (print single char whose value is in a0)
    addi $a0, $0, 0x20  #load ascii char 32 = 0x20 = 'space'
    syscall
    
    addi $t9 $t9 1  # increment counter  
    slt $t8 $t9 $t1  # compare counter t9 to size t1
    bne $t8 $0 printsorted # loop if $t9 < size
  #################################################################################
  jr $ra #leave function


main: ## Start of code section
  la $a0 myarray
  lw $a1 mysize
  jal bubblesort # jump to bubblesort and put current address in $ra so that it can come 
    #  back (ie return to here after function call)

leave:
  li $v0, 10         # load system instruction 10 (terminate program) into v0 register
  syscall
