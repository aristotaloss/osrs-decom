# osrs-decom
Old-School RuneScape script DECOMpiler

# Example output of dasm functionality
```
$osrs_decom --fs /home/bart/sources/osrs-server/data/filestore --dasm 111
// num_instructions: 38
// num_int_params: 0
// num_string_params: 0
// num_int_locals: 0
// num_string_locals: 0

#0 = 42 (0x2a), 11
#1 = 0 (0x0), 1
#2 = 8 (0x8), 1
#3 = 6 (0x6), 1
#4 = 3103 (0xc1f), 0
#5 = 40 (0x28), 677
#6 = 3 (0x3), 0, 'Enter the player name whose channel you wish to join:'
#7 = 0 (0x0), 35913851
#8 = 2112 (0x840), 0
#9 = 0 (0x0), 10
#10 = 43 (0x2b), 5
#11 = 40 (0x28), 222
#12 = 0 (0x0), 112
#13 = 0 (0x0), -2147483640
#14 = 0 (0x0), -2147483639
#15 = 3 (0x3), 0, 'iz'
#16 = 0 (0x0), 35913852
#17 = 2419 (0x973), 0
#18 = 40 (0x28), 680
#19 = 47 (0x2f), 129
#20 = 4117 (0x1015), 0
#21 = 0 (0x0), 0
#22 = 10 (0xa), 1
#23 = 6 (0x6), 13
#24 = 40 (0x28), 678
#25 = 3 (0x3), 0, '<col=000000>'
#26 = 3 (0x3), 0, 'Last name:'
#27 = 3 (0x3), 0, '</col>'
#28 = 3 (0x3), 0, ' '
#29 = 47 (0x2f), 129
#30 = 37 (0x25), 5
#31 = 1112 (0x458), 0
#32 = 0 (0x0), 682
#33 = 0 (0x0), 10
#34 = 47 (0x2f), 129
#35 = 3 (0x3), 0, 'is'
#36 = 1400 (0x578), 0
#37 = 21 (0x15), 0
```
