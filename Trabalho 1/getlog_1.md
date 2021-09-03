% Running: fso-timedshell

- Minimal Information
  - Submission Language: c
  - Submission SRCFILE: Main.c
  - Run all even on critical error: yes


## LIMITS via ulimits

set: ulimit -u 1024
set: ulimit -s 204800
set: ulimit -f 256000


# Compiling code



# Running test files
 - Parallel Test not allowed in this problem
 - NPROC: 1
--------------------------------------------------------------------

## Testfile: file-001-example


### CAGE CONTROL DATA this is for Bruno to check
8<-------------------------8<------------------
#### file-001-example-stderr
1630667653 1630667654
#### file-001-example-log.cage-run
Creating output file '/tmp/tmp.r1Z7aCTwzz/file-001-example-team_output'
#### file-001-example-log.timelog
real 2.72
user 0.01
sys 0.01
#### file-001-example-log.bwraptime
real 2.73
user 0.00
sys 0.00
#### file-001-example-log.bwrapexitcode
0
8<-------------------------8<------------------
### END CAGE CONTROL DATA


### CHECKING SOLUTION THIS IS USUALLY A DIFF OUTPUT
EXECTIME file-001-example 2.72 WA
 - Execution Time: 2.72
 - Time Limit for this problem is: 4.1360
 - Veredict for this output: WA

### files dont match - see output
*** /tmp/tmp.r1Z7aCTwzz/file-001-example-team_output	2021-09-03 08:14:16.197551953 -0300
--- /home/judge/problems/moj-problems/fso-timedshell/tests/output/file-001-example	2021-08-31 11:42:57.263177966 -0300
***************
*** 1,8 ****
! > Demorou 1.0 segundos retornou 0
! > Demorou 1.0 segundos retornou 0
! > Erro: No such file or directory> Demorou 0.0 segundos retornou 0
! >> O tempo total foi de 2.0 segundos
! > Demorou 1.0 segundos retornou 0
! > Demorou 1.0 segundos retornou 0
! > Demorou 0.0 segundos retornou 0
! >> O tempo total foi de 2.0 segundos
--- 1,5 ----
! > Demorou 1.0 segundos, retornou 0
! > Demorou 1.1 segundos, retornou 0
! > Erro: No such file or directory
! > Demorou 0.0 segundos, retornou 2
! >> O tempo total foi de 2.1 segundos
Differences found

#### INPUT COURTESY [this is the raw input file]
```
/bin/sleep 1
/bin/sleep 1.1
/bin/eunaoexisto 123
```


--------------------------------------------------------------------

## Testfile: file-002-example


### CAGE CONTROL DATA this is for Bruno to check
8<-------------------------8<------------------
#### file-002-example-stderr
1630667656 1630667657
#### file-002-example-log.cage-run
Creating output file '/tmp/tmp.r1Z7aCTwzz/file-002-example-team_output'
#### file-002-example-log.timelog
real 3.33
user 0.01
sys 0.01
#### file-002-example-log.bwraptime
real 3.33
user 0.00
sys 0.00
#### file-002-example-log.bwrapexitcode
0
8<-------------------------8<------------------
### END CAGE CONTROL DATA


### CHECKING SOLUTION THIS IS USUALLY A DIFF OUTPUT
EXECTIME file-002-example 3.33 WA
 - Execution Time: 3.33
 - Time Limit for this problem is: 4.1360
 - Veredict for this output: WA

### files dont match - see output
*** /tmp/tmp.r1Z7aCTwzz/file-002-example-team_output	2021-09-03 08:14:19.561557613 -0300
--- /home/judge/problems/moj-problems/fso-timedshell/tests/output/file-002-example	2021-08-31 11:42:57.299178059 -0300
***************
*** 1,7 ****
  Linux
! > Demorou 1.0 segundos retornou 0
! > Demorou 0.0 segundos retornou 0
! > Demorou 0.0 segundos retornou 1
! > Demorou 0.0 segundos retornou 0
! > Demorou 1.0 segundos retornou 0
! >> O tempo total foi de 2.0 segundos
--- 1,7 ----
+ > Demorou 1.5 segundos, retornou 0
+ > Demorou 0.0 segundos, retornou 0
+ > Demorou 0.0 segundos, retornou 1
  Linux
! > Demorou 0.0 segundos, retornou 0
! > Demorou 1.0 segundos, retornou 0
! >> O tempo total foi de 2.5 segundos
Differences found

#### INPUT COURTESY [this is the raw input file]
```
/bin/sleep 1.5
/bin/true ign
/bin/false 222
/bin/uname -s
/bin/sleep 1
```


--------------------------------------------------------------------

## Testfile: file-003-example


### CAGE CONTROL DATA this is for Bruno to check
8<-------------------------8<------------------
#### file-003-example-stderr
1630667659 1630667660
W: Unable to read /etc/apt/apt.conf.d/ - DirectoryExists (2: No such file or directory)
#### file-003-example-log.cage-run
Creating output file '/tmp/tmp.r1Z7aCTwzz/file-003-example-team_output'
#### file-003-example-log.timelog
real 0.72
user 0.02
sys 0.00
#### file-003-example-log.bwraptime
real 0.73
user 0.00
sys 0.00
#### file-003-example-log.bwrapexitcode
0
8<-------------------------8<------------------
### END CAGE CONTROL DATA


### CHECKING SOLUTION THIS IS USUALLY A DIFF OUTPUT
EXECTIME file-003-example 0.72 WA
 - Execution Time: 0.72
 - Time Limit for this problem is: 4.1360
 - Veredict for this output: WA

 - Will NOT show DIFFS or Courtesy for MORE than 2 errors

--------------------------------------------------------------------

## Testfile: file-004-example


### CAGE CONTROL DATA this is for Bruno to check
8<-------------------------8<------------------
#### file-004-example-stderr
1630667660 1630667661
0.00user 0.00system 0:00.00elapsed 100%CPU (0avgtext+0avgdata 1112maxresident)k
0inputs+0outputs (0major+55minor)pagefaults 0swaps
#### file-004-example-log.cage-run
Creating output file '/tmp/tmp.r1Z7aCTwzz/file-004-example-team_output'
#### file-004-example-log.timelog
real 0.73
user 0.01
sys 0.01
#### file-004-example-log.bwraptime
real 0.74
user 0.00
sys 0.00
#### file-004-example-log.bwrapexitcode
0
8<-------------------------8<------------------
### END CAGE CONTROL DATA


### CHECKING SOLUTION THIS IS USUALLY A DIFF OUTPUT
EXECTIME file-004-example 0.73 WA
 - Execution Time: 0.73
 - Time Limit for this problem is: 4.1360
 - Veredict for this output: WA

 - Will NOT show DIFFS or Courtesy for MORE than 2 errors

--------------------------------------------------------------------

## Testfile: file-005-example


### CAGE CONTROL DATA this is for Bruno to check
8<-------------------------8<------------------
#### file-005-example-stderr
1630667661 1630667662
#### file-005-example-log.cage-run
Creating output file '/tmp/tmp.r1Z7aCTwzz/file-005-example-team_output'
#### file-005-example-log.timelog
real 1.13
user 0.01
sys 0.01
#### file-005-example-log.bwraptime
real 1.14
user 0.00
sys 0.00
#### file-005-example-log.bwrapexitcode
0
8<-------------------------8<------------------
### END CAGE CONTROL DATA


### CHECKING SOLUTION THIS IS USUALLY A DIFF OUTPUT
EXECTIME file-005-example 1.13 WA
 - Execution Time: 1.13
 - Time Limit for this problem is: 4.1360
 - Veredict for this output: WA

 - Will NOT show DIFFS or Courtesy for MORE than 2 errors

--------------------------------------------------------------------

## Testfile: file-006-example


### CAGE CONTROL DATA this is for Bruno to check
8<-------------------------8<------------------
#### file-006-example-stderr
1630667662 1630667663
[: missing ‘]’
sleep: missing operand
Try 'sleep --help' for more information.
Command exited with non-zero status 1
0.00user 0.00system 0:00.00elapsed 100%CPU (0avgtext+0avgdata 2024maxresident)k
0inputs+0outputs (0major+75minor)pagefaults 0swaps
Command exited with non-zero status 1
0.00user 0.00system 0:00.00elapsed 100%CPU (0avgtext+0avgdata 1028maxresident)k
0inputs+0outputs (0major+51minor)pagefaults 0swaps
Command exited with non-zero status 1
0.00user 0.00system 0:00.00elapsed ?%CPU (0avgtext+0avgdata 1056maxresident)k
0inputs+0outputs (0major+52minor)pagefaults 0swaps
#### file-006-example-log.cage-run
Creating output file '/tmp/tmp.r1Z7aCTwzz/file-006-example-team_output'
#### file-006-example-log.timelog
real 0.83
user 0.01
sys 0.01
#### file-006-example-log.bwraptime
real 0.84
user 0.00
sys 0.00
#### file-006-example-log.bwrapexitcode
0
8<-------------------------8<------------------
### END CAGE CONTROL DATA


### CHECKING SOLUTION THIS IS USUALLY A DIFF OUTPUT
EXECTIME file-006-example 0.83 WA
 - Execution Time: 0.83
 - Time Limit for this problem is: 4.1360
 - Veredict for this output: WA

 - Will NOT show DIFFS or Courtesy for MORE than 2 errors



# FINAL VEREDICT
  - Wrong Answer
  - 0 correct in 6 , 0%
