// fix errors

6d, ,0,6e
6e,0,>,FFFF

// begin

0, ,<,1

1,0,<,1
1,1,<,1
1,2,<,1
1,3,<,1
1,4,<,1
1,5,<,1
1,6,<,1
1,7,<,1
1, ,>,2

//состояние 3 -> copy перекопирование числа, если плюсовой знак
// 
// ==================================================================

2,0,0,30
2,1, ,31
2,2, ,32
2,3, ,33

30, ,>,6d
30,0,>,30
30,1,1,5
30,2,2,5
30,3,3,5
30,4,4,5
30,5,5,5
30,6,6,5
30,7,7,5

31, ,>,311
311,0,>,311
311,1,>,311
311,2,>,311
311,3,>,311
311,4,>,311
311,5,>,311
311,6,>,311
311,7,>,311
311, ,>,3111
3111, ,1,51

51,1,<,551
551, ,<,511
511,0,<,511
511,1,<,511
511,2,<,511
511,3,<,511
511,4,<,511
511,5,<,511
511,6,<,511
511,7,<,511
511, ,1,5111
5111,1,>,5

32, ,>,322
322,0,>,322
322,1,>,322
322,2,>,322
322,3,>,322
322,4,>,322
322,5,>,322
322,6,>,322
322,7,>,322
322, ,>,3222
3222, ,2,52

52,2,<,552
552, ,<,522
522,0,<,522
522,1,<,522
522,2,<,522
522,3,<,522
522,4,<,522
522,5,<,522
522,6,<,522
522,7,<,522
522, ,2,5222
5222,2,>,5

33, ,>,333
333,0,>,333
333,1,>,333
333,2,>,333
333,3,>,333
333,4,>,333
333,5,>,333
333,6,>,333
333,7,>,333
333, ,>,3333
3333, ,3,53

53,3,<,553
553, ,<,533
533,0,<,533
533,1,<,533
533,2,<,533
533,3,<,533
533,4,<,533
533,5,<,533
533,6,<,533
533,7,<,533
533, ,3,5333
5333,3,>,5

// состояние 5 -> copy

5,0, ,60
5,1, ,61
5,2, ,62
5,3, ,63
5,4, ,64
5,5, ,65
5,6, ,66
5,7, ,67
5, ,>,68

68,0,>,68
68,1,>,68
68,2,>,68
68,3,>,68
68,4,>,68
68,5,>,68
68,6,>,68
68,7,>,68
68, , ,FFFF
FFFF, , ,FFFF

60, ,>,660
660,0,>,660
660,1,>,660
660,2,>,660
660,3,>,660
660,4,>,660
660,5,>,660
660,6,>,660
660,7,>,660
660, ,>,70

70,0,>,70
70,1,>,70
70,2,>,70
70,3,>,70
70,4,>,70
70,5,>,70
70,6,>,70
70,7,>,70
70, ,0,770

770,0,<,770
770,1,<,770
770,2,<,770
770,3,<,770
770,4,<,770
770,5,<,770
770,6,<,770
770,7,<,770
770, ,<,80

80,0,<,80
80,1,<,80
80,2,<,80
80,3,<,80
80,4,<,80
80,5,<,80
80,6,<,80
80,7,<,80
80, ,0,880

880,0,>,5

61, ,>,661
661,0,>,661
661,1,>,661
661,2,>,661
661,3,>,661
661,4,>,661
661,5,>,661
661,6,>,661
661,7,>,661
661, ,>,71

71,0,>,71
71,1,>,71
71,2,>,71
71,3,>,71
71,4,>,71
71,5,>,71
71,6,>,71
71,7,>,71
71, ,1,771

771,0,<,771
771,1,<,771
771,2,<,771
771,3,<,771
771,4,<,771
771,5,<,771
771,6,<,771
771,7,<,771
771, ,<,81

81,0,<,81
81,1,<,81
81,2,<,81
81,3,<,81
81,4,<,81
81,5,<,81
81,6,<,81
81,7,<,81
81, ,1,881

881,1,>,5

62, ,>,662
662,0,>,662
662,1,>,662
662,2,>,662
662,3,>,662
662,4,>,662
662,5,>,662
662,6,>,662
662,7,>,662
662, ,>,72

72,0,>,72
72,1,>,72
72,2,>,72
72,3,>,72
72,4,>,72
72,5,>,72
72,6,>,72
72,7,>,72
72, ,2,772

772,0,<,772
772,1,<,772
772,2,<,772
772,3,<,772
772,4,<,772
772,5,<,772
772,6,<,772
772,7,<,772
772, ,<,82

82,0,<,82
82,1,<,82
82,2,<,82
82,3,<,82
82,4,<,82
82,5,<,82
82,6,<,82
82,7,<,82
82, ,2,882

882,2,>,5

63, ,>,663
663,0,>,663
663,1,>,663
663,2,>,663
663,3,>,663
663,4,>,663
663,5,>,663
663,6,>,663
663,7,>,663
663, ,>,73

73,0,>,73
73,1,>,73
73,2,>,73
73,3,>,73
73,4,>,73
73,5,>,73
73,6,>,73
73,7,>,73
73, ,3,773

773,0,<,773
773,1,<,773
773,2,<,773
773,3,<,773
773,4,<,773
773,5,<,773
773,6,<,773
773,7,<,773
773, ,<,83

83,0,<,83
83,1,<,83
83,2,<,83
83,3,<,83
83,4,<,83
83,5,<,83
83,6,<,83
83,7,<,83
83, ,3,883

883,3,>,5

64, ,>,664
664,0,>,664
664,1,>,664
664,2,>,664
664,3,>,664
664,4,>,664
664,5,>,664
664,6,>,664
664,7,>,664
664, ,>,74

74,0,>,74
74,1,>,74
74,2,>,74
74,3,>,74
74,4,>,74
74,5,>,74
74,6,>,74
74,7,>,74
74, ,4,774

774,0,<,774
774,1,<,774
774,2,<,774
774,3,<,774
774,4,<,774
774,5,<,774
774,6,<,774
774,7,<,774
774, ,<,84

84,0,<,84
84,1,<,84
84,2,<,84
84,3,<,84
84,4,<,84
84,5,<,84
84,6,<,84
84,7,<,84
84, ,4,884

884,4,>,5

65, ,>,665
665,0,>,665
665,1,>,665
665,2,>,665
665,3,>,665
665,4,>,665
665,5,>,665
665,6,>,665
665,7,>,665
665, ,>,75

75,0,>,75
75,1,>,75
75,2,>,75
75,3,>,75
75,4,>,75
75,5,>,75
75,6,>,75
75,7,>,75
75, ,5,775

775,0,<,775
775,1,<,775
775,2,<,775
775,3,<,775
775,4,<,775
775,5,<,775
775,6,<,775
775,7,<,775
775, ,<,85

85,0,<,85
85,1,<,85
85,2,<,85
85,3,<,85
85,4,<,85
85,5,<,85
85,6,<,85
85,7,<,85
85, ,5,885

885,5,>,5

66, ,>,666
666,0,>,666
666,1,>,666
666,2,>,666
666,3,>,666
666,4,>,666
666,5,>,666
666,6,>,666
666,7,>,666
666, ,>,76

76,0,>,76
76,1,>,76
76,2,>,76
76,3,>,76
76,4,>,76
76,5,>,76
76,6,>,76
76,7,>,76
76, ,6,776

776,0,<,776
776,1,<,776
776,2,<,776
776,3,<,776
776,4,<,776
776,5,<,776
776,6,<,776
776,7,<,776
776, ,<,86

86,0,<,86
86,1,<,86
86,2,<,86
86,3,<,86
86,4,<,86
86,5,<,86
86,6,<,86
86,7,<,86
86, ,6,886

886,6,>,5

67, ,>,667
667,0,>,667
667,1,>,667
667,2,>,667
667,3,>,667
667,4,>,667
667,5,>,667
667,6,>,667
667,7,>,667
667, ,>,77

77,0,>,77
77,1,>,77
77,2,>,77
77,3,>,77
77,4,>,77
77,5,>,77
77,6,>,77
77,7,>,77
77, ,7,777

777,0,<,777
777,1,<,777
777,2,<,777
777,3,<,777
777,4,<,777
777,5,<,777
777,6,<,777
777,7,<,777
777, ,<,87

87,0,<,87
87,1,<,87
87,2,<,87
87,3,<,87
87,4,<,87
87,5,<,87
87,6,<,87
87,7,<,87
87, ,7,887

887,7,>,5

//состояние 4 -> допкод

2,4,>,for
2,5,>,for
2,6,>,for
2,7,>,for

for,0,>,for
for,1,>,for
for,2,>,for
for,3,>,for
for,4,>,for
for,5,>,for
for,6,>,for
for,7,>,for
for, ,<,4

4,0, ,40
4,1, ,41
4,2, ,42
4,3, ,43
4,4, ,44
4,5, ,45
4,6, ,46
4,7, ,47
4, ,>,48

48,0,>,48
48,1,>,48
48,2,>,48
48,3,>,48
48,4,>,48
48,5,>,48
48,6,>,48
48,7,>,48
48, ,>,480

480,0,>,480
480, ,<,4800
4800,0, ,48000
4800, ,>,48FF
48000, ,<,4800

48FF, ,0,1FFFF
1FFFF,0,>,FFFF

40, ,>,400

400,0,>,400
400,1,>,400
400,2,>,400
400,3,>,400
400,4,>,400
400,5,>,400
400,6,>,400
400,7,>,400
400, ,>,4000

4000,0,>,4000
4000,1,>,4000
4000,2,>,4000
4000,3,>,4000
4000,4,>,4000
4000,5,>,4000
4000,6,>,4000
4000,7,>,4000
4000, ,0,40000

40000,0,<,40000
40000,1,<,40000
40000,2,<,40000
40000,3,<,40000
40000,4,<,40000
40000,5,<,40000
40000,6,<,40000
40000,7,<,40000
40000, ,<,400000

400000,0,<,400000
400000,1,<,400000
400000,2,<,400000
400000,3,<,400000
400000,4,<,400000
400000,5,<,400000
400000,6,<,400000
400000,7,<,400000
400000, ,0,4000000

4000000,0,<,4

41, ,>,4001

4001,0,>,4001
4001,1,>,4001
4001,2,>,4001
4001,3,>,4001
4001,4,>,4001
4001,5,>,4001
4001,6,>,4001
4001,7,>,4001
4001, ,>,40001

40001,0,>,40001
40001,1,>,40001
40001,2,>,40001
40001,3,>,40001
40001,4,>,40001
40001,5,>,40001
40001,6,>,40001
40001,7,>,40001
40001, ,7,400001

400001,0,<,400001
400001,1,<,400001
400001,2,<,400001
400001,3,<,400001
400001,4,<,400001
400001,5,<,400001
400001,6,<,400001
400001,7,<,400001
400001, ,<,4000001

4000001,0,<,4000001
4000001,1,<,4000001
4000001,2,<,4000001
4000001,3,<,4000001
4000001,4,<,4000001
4000001,5,<,4000001
4000001,6,<,4000001
4000001,7,<,4000001
4000001, ,1,40000001

40000001,1,<,6



42, ,>,4002

4002,0,>,4002
4002,1,>,4002
4002,2,>,4002
4002,3,>,4002
4002,4,>,4002
4002,5,>,4002
4002,6,>,4002
4002,7,>,4002
4002, ,>,40002

40002,0,>,40002
40002,1,>,40002
40002,2,>,40002
40002,3,>,40002
40002,4,>,40002
40002,5,>,40002
40002,6,>,40002
40002,7,>,40002
40002, ,6,400002

400002,0,<,400002
400002,1,<,400002
400002,2,<,400002
400002,3,<,400002
400002,4,<,400002
400002,5,<,400002
400002,6,<,400002
400002,7,<,400002
400002, ,<,4000002

4000002,0,<,4000002
4000002,1,<,4000002
4000002,2,<,4000002
4000002,3,<,4000002
4000002,4,<,4000002
4000002,5,<,4000002
4000002,6,<,4000002
4000002,7,<,4000002
4000002, ,2,40000002

40000002,2,<,6


43, ,>,4003

4003,0,>,4003
4003,1,>,4003
4003,2,>,4003
4003,3,>,4003
4003,4,>,4003
4003,5,>,4003
4003,6,>,4003
4003,7,>,4003
4003, ,>,40003

40003,0,>,40003
40003,1,>,40003
40003,2,>,40003
40003,3,>,40003
40003,4,>,40003
40003,5,>,40003
40003,6,>,40003
40003,7,>,40003
40003, ,5,400003

400003,0,<,400003
400003,1,<,400003
400003,2,<,400003
400003,3,<,400003
400003,4,<,400003
400003,5,<,400003
400003,6,<,400003
400003,7,<,400003
400003, ,<,4000003

4000003,0,<,4000003
4000003,1,<,4000003
4000003,2,<,4000003
4000003,3,<,4000003
4000003,4,<,4000003
4000003,5,<,4000003
4000003,6,<,4000003
4000003,7,<,4000003
4000003, ,3,40000003

40000003,3,<,6



44, ,>,4004

4004,0,>,4004
4004,1,>,4004
4004,2,>,4004
4004,3,>,4004
4004,4,>,4004
4004,5,>,4004
4004,6,>,4004
4004,7,>,4004
4004, ,>,40004

40004,0,>,40004
40004,1,>,40004
40004,2,>,40004
40004,3,>,40004
40004,4,>,40004
40004,5,>,40004
40004,6,>,40004
40004,7,>,40004
40004, ,4,400004

400004,0,<,400004
400004,1,<,400004
400004,2,<,400004
400004,3,<,400004
400004,4,<,400004
400004,5,<,400004
400004,6,<,400004
400004,7,<,400004
400004, ,<,4000004

4000004,0,<,4000004
4000004,1,<,4000004
4000004,2,<,4000004
4000004,3,<,4000004
4000004,4,<,4000004
4000004,5,<,4000004
4000004,6,<,4000004
4000004,7,<,4000004
4000004, ,4,40000004

40000004,4,<,6


45, ,>,4005

4005,0,>,4005
4005,1,>,4005
4005,2,>,4005
4005,3,>,4005
4005,4,>,4005
4005,5,>,4005
4005,6,>,4005
4005,7,>,4005
4005, ,>,40005

40005,0,>,40005
40005,1,>,40005
40005,2,>,40005
40005,3,>,40005
40005,4,>,40005
40005,5,>,40005
40005,6,>,40005
40005,7,>,40005
40005, ,3,400005

400005,0,<,400005
400005,1,<,400005
400005,2,<,400005
400005,3,<,400005
400005,4,<,400005
400005,5,<,400005
400005,6,<,400005
400005,7,<,400005
400005, ,<,4000005

4000005,0,<,4000005
4000005,1,<,4000005
4000005,2,<,4000005
4000005,3,<,4000005
4000005,4,<,4000005
4000005,5,<,4000005
4000005,6,<,4000005
4000005,7,<,4000005
4000005, ,5,40000005

40000005,5,<,6


46, ,>,4006

4006,0,>,4006
4006,1,>,4006
4006,2,>,4006
4006,3,>,4006
4006,4,>,4006
4006,5,>,4006
4006,6,>,4006
4006,7,>,4006
4006, ,>,40006

40006,0,>,40006
40006,1,>,40006
40006,2,>,40006
40006,3,>,40006
40006,4,>,40006
40006,5,>,40006
40006,6,>,40006
40006,7,>,40006
40006, ,2,400006

400006,0,<,400006
400006,1,<,400006
400006,2,<,400006
400006,3,<,400006
400006,4,<,400006
400006,5,<,400006
400006,6,<,400006
400006,7,<,400006
400006, ,<,4000006

4000006,0,<,4000006
4000006,1,<,4000006
4000006,2,<,4000006
4000006,3,<,4000006
4000006,4,<,4000006
4000006,5,<,4000006
4000006,6,<,4000006
4000006,7,<,4000006
4000006, ,6,40000006

40000006,6,<,6

47, ,>,4007

4007,0,>,4007
4007,1,>,4007
4007,2,>,4007
4007,3,>,4007
4007,4,>,4007
4007,5,>,4007
4007,6,>,4007
4007,7,>,4007
4007, ,>,40007

40007,0,>,40007
40007,1,>,40007
40007,2,>,40007
40007,3,>,40007
40007,4,>,40007
40007,5,>,40007
40007,6,>,40007
40007,7,>,40007
40007, ,1,400007

400007,0,<,400007
400007,1,<,400007
400007,2,<,400007
400007,3,<,400007
400007,4,<,400007
400007,5,<,400007
400007,6,<,400007
400007,7,<,400007
400007, ,<,4000007

4000007,0,<,4000007
4000007,1,<,4000007
4000007,2,<,4000007
4000007,3,<,4000007
4000007,4,<,4000007
4000007,5,<,4000007
4000007,6,<,4000007
4000007,7,<,4000007
4000007, ,7,40000007

40000007,7,<,6

// 2 этап

6,0, ,606
6,1, ,616
6,2, ,626
6,3, ,636
6,4, ,646
6,5, ,656
6,6, ,6666
6,7, ,676
6, ,>,686

686,0,>,686
686,1,>,686
686,2,>,686
686,3,>,686
686,4,>,686
686,5,>,686
686,6,>,686
686,7,>,686
686, ,>,6806

6806,0,>,6806
6806,1,>,6806
6806,2,>,6806
6806,3,>,6806
6806,4,>,6806
6806,5,>,6806
6806,6,>,6806
6806,7,>,6806
6806, ,<,68069

68069,0, ,6806
68069,1,1,9999
68069,2,2,9999
68069,3,3,9999
68069,4,4,9999
68069,5,5,9999
68069,6,6,9999
68069,7,7,9999
68069, , ,9999



606, ,>,400666

400666,0,>,400666
400666,1,>,400666
400666,2,>,400666
400666,3,>,400666
400666,4,>,400666
400666,5,>,400666
400666,6,>,400666
400666,7,>,400666
400666, ,>,4000666

4000666,0,>,4000666
4000666,1,>,4000666
4000666,2,>,4000666
4000666,3,>,4000666
4000666,4,>,4000666
4000666,5,>,4000666
4000666,6,>,4000666
4000666,7,>,4000666
4000666, ,7,40000666

40000666,0,<,40000666
40000666,1,<,40000666
40000666,2,<,40000666
40000666,3,<,40000666
40000666,4,<,40000666
40000666,5,<,40000666
40000666,6,<,40000666
40000666,7,<,40000666
40000666, ,<,400000666

400000666,0,<,400000666
400000666,1,<,400000666
400000666,2,<,400000666
400000666,3,<,400000666
400000666,4,<,400000666
400000666,5,<,400000666
400000666,6,<,400000666
400000666,7,<,400000666
400000666, ,0,4000000666

4000000666,0,<,6

616, ,>,4001666

4001666,0,>,4001666
4001666,1,>,4001666
4001666,2,>,4001666
4001666,3,>,4001666
4001666,4,>,4001666
4001666,5,>,4001666
4001666,6,>,4001666
4001666,7,>,4001666
4001666, ,>,40001666

40001666,0,>,40001666
40001666,1,>,40001666
40001666,2,>,40001666
40001666,3,>,40001666
40001666,4,>,40001666
40001666,5,>,40001666
40001666,6,>,40001666
40001666,7,>,40001666
40001666, ,6,400001666

400001666,0,<,400001666
400001666,1,<,400001666
400001666,2,<,400001666
400001666,3,<,400001666
400001666,4,<,400001666
400001666,5,<,400001666
400001666,6,<,400001666
400001666,7,<,400001666
400001666, ,<,4000001666

4000001666,0,<,4000001666
4000001666,1,<,4000001666
4000001666,2,<,4000001666
4000001666,3,<,4000001666
4000001666,4,<,4000001666
4000001666,5,<,4000001666
4000001666,6,<,4000001666
4000001666,7,<,4000001666
4000001666, ,1,40000001666

40000001666,1,<,6



626, ,>,4002666

4002666,0,>,4002666
4002666,1,>,4002666
4002666,2,>,4002666
4002666,3,>,4002666
4002666,4,>,4002666
4002666,5,>,4002666
4002666,6,>,4002666
4002666,7,>,4002666
4002666, ,>,40002666

40002666,0,>,40002666
40002666,1,>,40002666
40002666,2,>,40002666
40002666,3,>,40002666
40002666,4,>,40002666
40002666,5,>,40002666
40002666,6,>,40002666
40002666,7,>,40002666
40002666, ,5,400002666

400002666,0,<,400002666
400002666,1,<,400002666
400002666,2,<,400002666
400002666,3,<,400002666
400002666,4,<,400002666
400002666,5,<,400002666
400002666,6,<,400002666
400002666,7,<,400002666
400002666, ,<,4000002666

4000002666,0,<,4000002666
4000002666,1,<,4000002666
4000002666,2,<,4000002666
4000002666,3,<,4000002666
4000002666,4,<,4000002666
4000002666,5,<,4000002666
4000002666,6,<,4000002666
4000002666,7,<,4000002666
4000002666, ,2,40000002666

40000002666,2,<,6


636, ,>,4003666

4003666,0,>,4003666
4003666,1,>,4003666
4003666,2,>,4003666
4003666,3,>,4003666
4003666,4,>,4003666
4003666,5,>,4003666
4003666,6,>,4003666
4003666,7,>,4003666
4003666, ,>,40003666

40003666,0,>,40003666
40003666,1,>,40003666
40003666,2,>,40003666
40003666,3,>,40003666
40003666,4,>,40003666
40003666,5,>,40003666
40003666,6,>,40003666
40003666,7,>,40003666
40003666, ,4,400003666

400003666,0,<,400003666
400003666,1,<,400003666
400003666,2,<,400003666
400003666,3,<,400003666
400003666,4,<,400003666
400003666,5,<,400003666
400003666,6,<,400003666
400003666,7,<,400003666
400003666, ,<,4000003666

4000003666,0,<,4000003666
4000003666,1,<,4000003666
4000003666,2,<,4000003666
4000003666,3,<,4000003666
4000003666,4,<,4000003666
4000003666,5,<,4000003666
4000003666,6,<,4000003666
4000003666,7,<,4000003666
4000003666, ,3,40000003666

40000003666,3,<,6



646, ,>,4004666

4004666,0,>,4004666
4004666,1,>,4004666
4004666,2,>,4004666
4004666,3,>,4004666
4004666,4,>,4004666
4004666,5,>,4004666
4004666,6,>,4004666
4004666,7,>,4004666
4004666, ,>,40004666

40004666,0,>,40004666
40004666,1,>,40004666
40004666,2,>,40004666
40004666,3,>,40004666
40004666,4,>,40004666
40004666,5,>,40004666
40004666,6,>,40004666
40004666,7,>,40004666
40004666, ,3,400004666

400004666,0,<,400004666
400004666,1,<,400004666
400004666,2,<,400004666
400004666,3,<,400004666
400004666,4,<,400004666
400004666,5,<,400004666
400004666,6,<,400004666
400004666,7,<,400004666
400004666, ,<,4000004666

4000004666,0,<,4000004666
4000004666,1,<,4000004666
4000004666,2,<,4000004666
4000004666,3,<,4000004666
4000004666,4,<,4000004666
4000004666,5,<,4000004666
4000004666,6,<,4000004666
4000004666,7,<,4000004666
4000004666, ,4,40000004666

40000004666,4,<,6


656, ,>,4005666

4005666,0,>,4005666
4005666,1,>,4005666
4005666,2,>,4005666
4005666,3,>,4005666
4005666,4,>,4005666
4005666,5,>,4005666
4005666,6,>,4005666
4005666,7,>,4005666
4005666, ,>,40005666

40005666,0,>,40005666
40005666,1,>,40005666
40005666,2,>,40005666
40005666,3,>,40005666
40005666,4,>,40005666
40005666,5,>,40005666
40005666,6,>,40005666
40005666,7,>,40005666
40005666, ,2,400005666

400005666,0,<,400005666
400005666,1,<,400005666
400005666,2,<,400005666
400005666,3,<,400005666
400005666,4,<,400005666
400005666,5,<,400005666
400005666,6,<,400005666
400005666,7,<,400005666
400005666, ,<,4000005666

4000005666,0,<,4000005666
4000005666,1,<,4000005666
4000005666,2,<,4000005666
4000005666,3,<,4000005666
4000005666,4,<,4000005666
4000005666,5,<,4000005666
4000005666,6,<,4000005666
4000005666,7,<,4000005666
4000005666, ,5,40000005666

40000005666,5,<,6


6666, ,>,4006666

4006666,0,>,4006666
4006666,1,>,4006666
4006666,2,>,4006666
4006666,3,>,4006666
4006666,4,>,4006666
4006666,5,>,4006666
4006666,6,>,4006666
4006666,7,>,4006666
4006666, ,>,40006666

40006666,0,>,40006666
40006666,1,>,40006666
40006666,2,>,40006666
40006666,3,>,40006666
40006666,4,>,40006666
40006666,5,>,40006666
40006666,6,>,40006666
40006666,7,>,40006666
40006666, ,1,400006666

400006666,0,<,400006666
400006666,1,<,400006666
400006666,2,<,400006666
400006666,3,<,400006666
400006666,4,<,400006666
400006666,5,<,400006666
400006666,6,<,400006666
400006666,7,<,400006666
400006666, ,<,4000006666

4000006666,0,<,4000006666
4000006666,1,<,4000006666
4000006666,2,<,4000006666
4000006666,3,<,4000006666
4000006666,4,<,4000006666
4000006666,5,<,4000006666
4000006666,6,<,4000006666
4000006666,7,<,4000006666
4000006666, ,6,40000006666

40000006666,6,<,6

676, ,>,4007666

4007666,0,>,4007666
4007666,1,>,4007666
4007666,2,>,4007666
4007666,3,>,4007666
4007666,4,>,4007666
4007666,5,>,4007666
4007666,6,>,4007666
4007666,7,>,4007666
4007666, ,>,40007666

40007666,0,>,40007666
40007666,1,>,40007666
40007666,2,>,40007666
40007666,3,>,40007666
40007666,4,>,40007666
40007666,5,>,40007666
40007666,6,>,40007666
40007666,7,>,40007666
40007666, ,0,400007666

400007666,0,<,400007666
400007666,1,<,400007666
400007666,2,<,400007666
400007666,3,<,400007666
400007666,4,<,400007666
400007666,5,<,400007666
400007666,6,<,400007666
400007666,7,<,400007666
400007666, ,<,4000007666

4000007666,0,<,4000007666
4000007666,1,<,4000007666
4000007666,2,<,4000007666
4000007666,3,<,4000007666
4000007666,4,<,4000007666
4000007666,5,<,4000007666
4000007666,6,<,4000007666
4000007666,7,<,4000007666
4000007666, ,7,40000007666

40000007666,7,<,6

9999,0,<,1919119
9999,1,<,1919119
9999,2,<,1919119
9999,3,<,1919119
9999,4,<,1919119
9999,5,<,1919119
9999,6,<,1919119
9999,7,<,1919119
9999, ,>,191911990
191911990,1, ,FFFF1231
191911990,2, ,FFFF1232
191911990,3, ,FFFF1233
191911990,4, ,FFFF1234
191911990,5, ,FFFF1235
191911990,6, ,FFFF1236
191911990,7, ,FFFF1237

FFFF1231, ,-,FFFF12310
FFFF12310,-,>,FFFF123100
FFFF123100, ,1,FFFF1231000
FFFF1231000,1,>,FFFF

FFFF1232, ,-,FFFF12320
FFFF12320,-,>,FFFF123200
FFFF123200, ,2,FFFF1232000
FFFF1232000,2,>,FFFF

FFFF1233, ,-,FFFF12330
FFFF12330,-,>,FFFF123300
FFFF123300, ,3,FFFF1233000
FFFF1233000,3,>,FFFF

FFFF1234, ,-,FFFF12340
FFFF12340,-,>,FFFF123400
FFFF123400, ,4,FFFF1234000
FFFF1234000,4,>,FFFF

FFFF1235, ,-,FFFF12350
FFFF12350,-,>,FFFF123500
FFFF123500, ,5,FFFF1235000
FFFF1235000,5,>,FFFF

FFFF1236, ,-,FFFF12360
FFFF12360,-,>,FFFF123600
FFFF123600, ,6,FFFF1236000
FFFF1236000,6,>,FFFF

FFFF1237, ,-,FFFF12370
FFFF12370,-,>,FFFF123700
FFFF123700, ,7,FFFF1237000
FFFF1237000,7,>,FFFF

1919119,0,>,9999e
1919119,1,>,9999e
1919119,2,>,9999e
1919119,3,>,9999e
1919119,4,>,9999e
1919119,5,>,9999e
1919119,6,>,9999e
1919119,7,>,9999e
1919119, ,>,191911990

9999e,1, ,99991
9999e,2, ,99992
9999e,3, ,99993
9999e,4, ,99994
9999e,5, ,99995
9999e,6, ,99996
9999e,7, ,99997
9999e, , ,9999e

99991, ,>,999919
999919, ,1,9999199
9999199,1,<,99998

99992, ,>,999929
999929, ,2,9999299
9999299,2,<,99998

99993, ,>,999939
999939, ,3,9999399
9999399,3,<,99998

99994, ,>,999949
999949, ,4,9999499
9999499,4,<,99998

99995, ,>,999959
999959, ,5,9999599
9999599,5,<,99998

99996, ,>,999969
999969, ,6,9999699
9999699,6,<,99998

99997, ,>,999979
999979, ,7,9999799
9999799,7,<,99998

99998, ,<,99998
99998,0,<,999977
99998,1,<,999977
99998,2,<,999977
99998,3,<,999977
99998,4,<,999977
99998,5,<,999977
99998,6,<,999977
99998,7,<,999977

999977,0,>,9999777
999977,1,>,9999777
999977,2,>,9999777
999977,3,>,9999777
999977,4,>,9999777
999977,5,>,9999777
999977,6,>,9999777
999977,7,>,9999777
999977, ,>,999977788 //end

9999777,0, ,99997770
9999777,1, ,99997771
9999777,2, ,99997772
9999777,3, ,99997773
9999777,4, ,99997774
9999777,5, ,99997775
9999777,6, ,99997776
9999777,7, ,99997777

99997770, ,>,99997770
99997770,0,>,999977708
99997770,1,>,999977708
99997770,2,>,999977708
99997770,3,>,999977708
99997770,4,>,999977708
99997770,5,>,999977708
99997770,6,>,999977708
99997770,7,>,999977708

999977708,0,>,999977708
999977708,1,>,999977708
999977708,2,>,999977708
999977708,3,>,999977708
999977708,4,>,999977708
999977708,5,>,999977708
999977708,6,>,999977708
999977708,7,>,999977708
999977708, ,0,888889999

99997771, ,>,99997771
99997771,0,>,999977718
99997771,1,>,999977718
99997771,2,>,999977718
99997771,3,>,999977718
99997771,4,>,999977718
99997771,5,>,999977718
99997771,6,>,999977718
99997771,7,>,999977718

999977718,0,>,999977718
999977718,1,>,999977718
999977718,2,>,999977718
999977718,3,>,999977718
999977718,4,>,999977718
999977718,5,>,999977718
999977718,6,>,999977718
999977718,7,>,999977718
999977718, ,1,888889999

99997772, ,>,99997772
99997772,0,>,999977728
99997772,1,>,999977728
99997772,2,>,999977728
99997772,3,>,999977728
99997772,4,>,999977728
99997772,5,>,999977728
99997772,6,>,999977728
99997772,7,>,999977728

999977728,0,>,999977728
999977728,1,>,999977728
999977728,2,>,999977728
999977728,3,>,999977728
999977728,4,>,999977728
999977728,5,>,999977728
999977728,6,>,999977728
999977728,7,>,999977728
999977728, ,2,888889999

99997773, ,>,99997773
99997773,0,>,999977738
99997773,1,>,999977738
99997773,2,>,999977738
99997773,3,>,999977738
99997773,4,>,999977738
99997773,5,>,999977738
99997773,6,>,999977738
99997773,7,>,999977738

999977738,0,>,999977738
999977738,1,>,999977738
999977738,2,>,999977738
999977738,3,>,999977738
999977738,4,>,999977738
999977738,5,>,999977738
999977738,6,>,999977738
999977738,7,>,999977738
999977738, ,3,888889999


99997774, ,>,99997774
99997774,0,>,999977748
99997774,1,>,999977748
99997774,2,>,999977748
99997774,3,>,999977748
99997774,4,>,999977748
99997774,5,>,999977748
99997774,6,>,999977748
99997774,7,>,999977748

999977748,0,>,999977748
999977748,1,>,999977748
999977748,2,>,999977748
999977748,3,>,999977748
999977748,4,>,999977748
999977748,5,>,999977748
999977748,6,>,999977748
999977748,7,>,999977748
999977748, ,4,888889999

99997775, ,>,99997775
99997775,0,>,999977758
99997775,1,>,999977758
99997775,2,>,999977758
99997775,3,>,999977758
99997775,4,>,999977758
99997775,5,>,999977758
99997775,6,>,999977758
99997775,7,>,999977758

999977758,0,>,999977758
999977758,1,>,999977758
999977758,2,>,999977758
999977758,3,>,999977758
999977758,4,>,999977758
999977758,5,>,999977758
999977758,6,>,999977758
999977758,7,>,999977758
999977758, ,5,888889999

99997776, ,>,99997776
99997776,0,>,999977768
99997776,1,>,999977768
99997776,2,>,999977768
99997776,3,>,999977768
99997776,4,>,999977768
99997776,5,>,999977768
99997776,6,>,999977768
99997776,7,>,999977768

999977768,0,>,999977768
999977768,1,>,999977768
999977768,2,>,999977768
999977768,3,>,999977768
999977768,4,>,999977768
999977768,5,>,999977768
999977768,6,>,999977768
999977768,7,>,999977768
999977768, ,6,888889999

99997777, ,>,99997777
99997777,0,>,999977778
99997777,1,>,999977778
99997777,2,>,999977778
99997777,3,>,999977778
99997777,4,>,999977778
99997777,5,>,999977778
99997777,6,>,999977778
99997777,7,>,999977778

999977778,0,>,999977778
999977778,1,>,999977778
999977778,2,>,999977778
999977778,3,>,999977778
999977778,4,>,999977778
999977778,5,>,999977778
999977778,6,>,999977778
999977778,7,>,999977778
999977778, ,7,888889999


888889999,0,<,888889999
888889999,1,<,888889999
888889999,2,<,888889999
888889999,3,<,888889999
888889999,4,<,888889999
888889999,5,<,888889999
888889999,6,<,888889999
888889999,7,<,888889999
888889999, ,<,99998

999977788,0, ,999977788e0
999977788,1, ,999977788e1
999977788,2, ,999977788e2
999977788,3, ,999977788e3
999977788,4, ,999977788e4
999977788,5, ,999977788e5
999977788,6, ,999977788e6
999977788,7, ,999977788e7

999977788e0, ,>,999977788e0
999977788e0,0,>,999977788e00
999977788e0,1,>,999977788e00
999977788e0,2,>,999977788e00
999977788e0,3,>,999977788e00
999977788e0,4,>,999977788e00
999977788e0,5,>,999977788e00
999977788e0,6,>,999977788e00
999977788e0,7,>,999977788e00

999977788e00,0,>,999977788e00
999977788e00,1,>,999977788e00
999977788e00,2,>,999977788e00
999977788e00,3,>,999977788e00
999977788e00,4,>,999977788e00
999977788e00,5,>,999977788e00
999977788e00,6,>,999977788e00
999977788e00,7,>,999977788e00
999977788e00, ,0,endfile

999977788e1, ,>,999977788e1
999977788e1,0,>,999977788e001
999977788e1,1,>,999977788e001
999977788e1,2,>,999977788e001
999977788e1,3,>,999977788e001
999977788e1,4,>,999977788e001
999977788e1,5,>,999977788e001
999977788e1,6,>,999977788e001
999977788e1,7,>,999977788e001

999977788e001,0,>,999977788e001
999977788e001,1,>,999977788e001
999977788e001,2,>,999977788e001
999977788e001,3,>,999977788e001
999977788e001,4,>,999977788e001
999977788e001,5,>,999977788e001
999977788e001,6,>,999977788e001
999977788e001,7,>,999977788e001
999977788e001, ,1,endfile

999977788e2, ,>,999977788e2
999977788e2,0,>,999977788e002
999977788e2,1,>,999977788e002
999977788e2,2,>,999977788e002
999977788e2,3,>,999977788e002
999977788e2,4,>,999977788e002
999977788e2,5,>,999977788e002
999977788e2,6,>,999977788e002
999977788e2,7,>,999977788e002

999977788e002,0,>,999977788e002
999977788e002,1,>,999977788e002
999977788e002,2,>,999977788e002
999977788e002,3,>,999977788e002
999977788e002,4,>,999977788e002
999977788e002,5,>,999977788e002
999977788e002,6,>,999977788e002
999977788e002,7,>,999977788e002
999977788e002, ,2,endfile

999977788e3, ,>,999977788e3
999977788e3,0,>,999977788e003
999977788e3,1,>,999977788e003
999977788e3,2,>,999977788e003
999977788e3,3,>,999977788e003
999977788e3,4,>,999977788e003
999977788e3,5,>,999977788e003
999977788e3,6,>,999977788e003
999977788e3,7,>,999977788e003

999977788e003,0,>,999977788e003
999977788e003,1,>,999977788e003
999977788e003,2,>,999977788e003
999977788e003,3,>,999977788e003
999977788e003,4,>,999977788e003
999977788e003,5,>,999977788e003
999977788e003,6,>,999977788e003
999977788e003,7,>,999977788e003
999977788e003, ,3,endfile


999977788e4, ,>,999977788e4
999977788e4,0,>,999977788e004
999977788e4,1,>,999977788e004
999977788e4,2,>,999977788e004
999977788e4,3,>,999977788e004
999977788e4,4,>,999977788e004
999977788e4,5,>,999977788e004
999977788e4,6,>,999977788e004
999977788e4,7,>,999977788e004

999977788e004,0,>,999977788e004
999977788e004,1,>,999977788e004
999977788e004,2,>,999977788e004
999977788e004,3,>,999977788e004
999977788e004,4,>,999977788e004
999977788e004,5,>,999977788e004
999977788e004,6,>,999977788e004
999977788e004,7,>,999977788e004
999977788e004, ,4,endfile

999977788e5, ,>,999977788e5
999977788e5,0,>,999977788e005
999977788e5,1,>,999977788e005
999977788e5,2,>,999977788e005
999977788e5,3,>,999977788e005
999977788e5,4,>,999977788e005
999977788e5,5,>,999977788e005
999977788e5,6,>,999977788e005
999977788e5,7,>,999977788e005

999977788e005,0,>,999977788e005
999977788e005,1,>,999977788e005
999977788e005,2,>,999977788e005
999977788e005,3,>,999977788e005
999977788e005,4,>,999977788e005
999977788e005,5,>,999977788e005
999977788e005,6,>,999977788e005
999977788e005,7,>,999977788e005
999977788e005, ,5,endfile

999977788e6, ,>,999977788e6
999977788e6,0,>,999977788e006
999977788e6,1,>,999977788e006
999977788e6,2,>,999977788e006
999977788e6,3,>,999977788e006
999977788e6,4,>,999977788e006
999977788e6,5,>,999977788e006
999977788e6,6,>,999977788e006
999977788e6,7,>,999977788e006

999977788e006,0,>,999977788e006
999977788e006,1,>,999977788e006
999977788e006,2,>,999977788e006
999977788e006,3,>,999977788e006
999977788e006,4,>,999977788e006
999977788e006,5,>,999977788e006
999977788e006,6,>,999977788e006
999977788e006,7,>,999977788e006
999977788e006, ,6,endfile

999977788e7, ,>,999977788e7
999977788e7,0,>,999977788e007
999977788e7,1,>,999977788e007
999977788e7,2,>,999977788e007
999977788e7,3,>,999977788e007
999977788e7,4,>,999977788e007
999977788e7,5,>,999977788e007
999977788e7,6,>,999977788e007
999977788e7,7,>,999977788e007

999977788e007,0,>,999977788e007
999977788e007,1,>,999977788e007
999977788e007,2,>,999977788e007
999977788e007,3,>,999977788e007
999977788e007,4,>,999977788e007
999977788e007,5,>,999977788e007
999977788e007,6,>,999977788e007
999977788e007,7,>,999977788e007
999977788e007, ,7,endfile

endfile,0,<,endfile
endfile,1,<,endfile
endfile,2,<,endfile
endfile,3,<,endfile
endfile,4,<,endfile
endfile,5,<,endfile
endfile,6,<,endfile
endfile,7,<,endfile
endfile, ,<,endfile1

endfile1, ,<,endfile2
endfile2,0,>,eeeennnndddd
endfile2,1,>,eeeennnndddd
endfile2,2,>,eeeennnndddd
endfile2,3,>,eeeennnndddd
endfile2,4,>,eeeennnndddd
endfile2,5,>,eeeennnndddd
endfile2,6,>,eeeennnndddd
endfile2,7,>,eeeennnndddd
endfile2, ,>,nextsdvig
///// no end

eeeennnndddd, ,>,eeeennnndddd1
eeeennnndddd1, ,-,eeeennnndddd2
eeeennnndddd2,-,>,eeeennnndddd3

eeeennnndddd3,0,>,eeeennnndddd3
eeeennnndddd3,1,>,eeeennnndddd3
eeeennnndddd3,2,>,eeeennnndddd3
eeeennnndddd3,3,>,eeeennnndddd3
eeeennnndddd3,4,>,eeeennnndddd3
eeeennnndddd3,5,>,eeeennnndddd3
eeeennnndddd3,6,>,eeeennnndddd3
eeeennnndddd3,7,>,eeeennnndddd3
eeeennnndddd3, , ,FFFF

nextsdvig, ,>,nextsdvig1
nextsdvig1, ,>,nextsdvig2

nextsdvig2,0, ,nextsdvig20
nextsdvig2,1, ,nextsdvig21
nextsdvig2,2, ,nextsdvig22
nextsdvig2,3, ,nextsdvig23
nextsdvig2,4, ,nextsdvig24
nextsdvig2,5, ,nextsdvig25
nextsdvig2,6, ,nextsdvig26
nextsdvig2,7, ,nextsdvig27
nextsdvig2, ,<,endfile67

endfile67, ,<,endfile

nextsdvig20, ,<,nextsdvig208
nextsdvig208, ,0,nextsdvigof
nextsdvigof,0,>,nextsdvig1

nextsdvig21, ,<,nextsdvig218
nextsdvig218, ,1,nextsdvigof1
nextsdvigof1,1,>,nextsdvig1

nextsdvig22, ,<,nextsdvig228
nextsdvig228, ,2,nextsdvigof2
nextsdvigof2,2,>,nextsdvig1

nextsdvig23, ,<,nextsdvig238
nextsdvig238, ,3,nextsdvigof3
nextsdvigof3,3,>,nextsdvig1

nextsdvig24, ,<,nextsdvig248
nextsdvig248, ,4,nextsdvigof4
nextsdvigof4,4,>,nextsdvig1

nextsdvig25, ,<,nextsdvig258
nextsdvig258, ,5,nextsdvigof5
nextsdvigof5,5,>,nextsdvig1

nextsdvig26, ,<,nextsdvig268
nextsdvig268, ,6,nextsdvigof6
nextsdvigof6,6,>,nextsdvig1

nextsdvig27, ,<,nextsdvig278
nextsdvig278, ,7,nextsdvigof7
nextsdvigof7,7,>,nextsdvig1


