#Readme File 

# The GOAL: Create a graph. Retreive the highest capacity between two Nodes in the graph. 
## Note: When getting multiple capacities (crossing multiple edges), the smallest capacity will be retrieved.   

## Program Overview: 
# How graph is being represented: 
The graph is being represented as an undirected graph. The graph information is stored inside an unordered map called adjList. The adjList holds the different Nodes and their associated weight since the adjList unordered map is a <int, vector<pair<int, float>> pair. The int value represents the current node you are currently on, node 1. The vector<pair<int, float>> stores the neighboring node, node 2, in the int slot and the weight (in this scenario, the weight between node 1 & 2, known as the capacity) in the float slot. The adjList is pulled from to set properties like the capacity in the hw2prog method. The graph is being traversed through with a priority queue that holds the nodes you want to examine. The method then loops through the priority queue nodes and applies the algorithm. 

# Algorithm 
In this program, a modified version of the Dijsktra algorithm was used (here, breadth-first-search, with a priority queue). The original algorithm grabs the shortest path in a graph. The algorithm views the weight on the graph as a distance and grabs the lowest distance value between two points. This algorithm can be easily modified to grab the highest weight between two nodes instead of the lowest. This modification was made by replacing dist[s] = 0 with dist[s] = numeric_limits<float>::max() & changing the pq.push(make_pair(0, s)) -- > pq.push(make_pair(dist[s], s)). The most significant change was in the for loop that loops through adjList to examine each vertice value. In the unmodified version, this for loop sets the alt value to the weight of the next vertice and compares it to the current weight, & if alt < curr weight then you swap and curr weight inherits alts weight value. This is then pushed onto the priority queue as the new capacity for the associated vertice. However, this finds the smallest capacity instead of the highest capacity, so this had to be changed to where alt > curr weight(dist[neighbor]), written as alt > dist[neighbor]. Instead of viewing the weight as distance, it can be viewed as capacity in this scenario, where the highest weight is the highest graph capacity. 


## Test Cases: 
First line = # of vertices, # of edges, # of paths that will be looked for.  
Other lines with 3 #s = Node1, Node2, Weight between Nodes. 
Lines with 2 #s = Paths that want to be found between two Nodes.
### Original Input:   
4 5 3
0 1 8
0 2 7
3 2 2
3 1 3
1 2 5
0 1 
1 3 
2 1 

### Rubric First Example Test input from HKitty Tamagou --> should output path: 0 --> 4 with capacity 110 
5 6 1
0 1 145
0 2 150 
1 3 65 
2 3 125 
3 4 110 
2 4 65 
0 4 

### Custom test set - two cities connected with at least one connection including multiple segments 
## Output: 0 -> 1 : Path : 0  4  3  1    capacity : 50 5 -> 1 : Path : 5  1    capacity : 200
6 9 2 
0 5 20 
0 4 50 
0 1 30 
2 1 90
3 1 70 
3 2 80 
4 1 40 
4 3 60 
5 1 200
0 1 
5 1 

### Custom test set - two cities connected with at least one connection including multiple segments 
## Output: 0 -> 3 : Path : 0  3    capacity : 8. 2 -> 0 : Path : 2  4  0    capacity : 5
5 8 2 
0 3 8 
0 4 7 
0 1 1 
3 2 3 
3 4 4 
2 1 2 
2 4 5 
1 4 6 
0 3 
2 0 

## 1000 nodes with 20 queries 
1000 1500 20
0 1 9
1 2 25
2 3 88
3 4 16
4 5 79
5 6 68
6 7 85
7 8 44
8 9 68
9 10 62
10 11 31
11 12 53
12 13 2
13 14 42
14 15 49
15 16 89
16 17 86
17 18 63
18 19 19
19 20 94
20 21 57
21 22 48
22 23 94
23 24 92
24 25 92
25 26 69
26 27 46
27 28 43
28 29 8
29 30 88
30 31 11
31 32 17
32 33 22
33 34 85
34 35 21
35 36 10
36 37 96
37 38 8
38 39 40
39 40 46
40 41 30
41 42 75
42 43 67
43 44 75
44 45 1
45 46 81
46 47 71
47 48 41
48 49 55
49 50 8
50 51 60
51 52 18
52 53 81
53 54 15
54 55 84
55 56 94
56 57 29
57 58 12
58 59 16
59 60 28
60 61 38
61 62 9
62 63 60
63 64 42
64 65 82
65 66 99
66 67 48
67 68 73
68 69 60
69 70 26
70 71 92
71 72 93
72 73 87
73 74 100
74 75 68
75 76 31
76 77 29
77 78 44
78 79 15
79 80 48
80 81 100
81 82 91
82 83 25
83 84 37
84 85 2
85 86 26
86 87 89
87 88 91
88 89 25
89 90 78
90 91 85
91 92 89
92 93 45
93 94 69
94 95 52
95 96 28
96 97 44
97 98 72
98 99 83
99 100 85
100 101 35
101 102 95
102 103 67
103 104 20
104 105 54
105 106 87
106 107 75
107 108 8
108 109 77
109 110 90
110 111 25
111 112 53
112 113 25
113 114 39
114 115 62
115 116 35
116 117 88
117 118 5
118 119 49
119 120 42
120 121 85
121 122 83
122 123 84
123 124 29
124 125 42
125 126 82
126 127 35
127 128 62
128 129 44
129 130 70
130 131 88
131 132 8
132 133 86
133 134 13
134 135 7
135 136 2
136 137 43
137 138 70
138 139 42
139 140 40
140 141 11
141 142 49
142 143 46
143 144 68
144 145 78
145 146 43
146 147 44
147 148 85
148 149 87
149 150 93
150 151 70
151 152 7
152 153 31
153 154 36
154 155 23
155 156 38
156 157 19
157 158 97
158 159 94
159 160 35
160 161 59
161 162 2
162 163 54
163 164 87
164 165 92
165 166 77
166 167 17
167 168 32
168 169 51
169 170 53
170 171 54
171 172 90
172 173 69
173 174 14
174 175 1
175 176 90
176 177 97
177 178 11
178 179 18
179 180 75
180 181 3
181 182 45
182 183 97
183 184 2
184 185 71
185 186 48
186 187 65
187 188 47
188 189 2
189 190 44
190 191 58
191 192 55
192 193 34
193 194 67
194 195 6
195 196 55
196 197 88
197 198 31
198 199 33
199 200 10
200 201 22
201 202 100
202 203 85
203 204 12
204 205 62
205 206 88
206 207 37
207 208 4
208 209 82
209 210 10
210 211 45
211 212 64
212 213 2
213 214 66
214 215 60
215 216 30
216 217 71
217 218 56
218 219 60
219 220 30
220 221 28
221 222 55
222 223 15
223 224 41
224 225 70
225 226 13
226 227 74
227 228 90
228 229 82
229 230 4
230 231 26
231 232 97
232 233 92
233 234 76
234 235 6
235 236 77
236 237 79
237 238 64
238 239 26
239 240 74
240 241 86
241 242 94
242 243 12
243 244 91
244 245 8
245 246 8
246 247 18
247 248 20
248 249 86
249 250 27
250 251 46
251 252 28
252 253 58
253 254 47
254 255 41
255 256 31
256 257 44
257 258 77
258 259 43
259 260 86
260 261 63
261 262 59
262 263 79
263 264 93
264 265 69
265 266 77
266 267 13
267 268 65
268 269 27
269 270 50
270 271 1
271 272 49
272 273 97
273 274 80
274 275 77
275 276 46
276 277 11
277 278 80
278 279 43
279 280 86
280 281 43
281 282 55
282 283 9
283 284 54
284 285 18
285 286 11
286 287 48
287 288 70
288 289 34
289 290 66
290 291 15
291 292 6
292 293 3
293 294 30
294 295 4
295 296 3
296 297 52
297 298 93
298 299 43
299 300 84
300 301 73
301 302 47
302 303 28
303 304 39
304 305 88
305 306 63
306 307 75
307 308 26
308 309 11
309 310 18
310 311 25
311 312 5
312 313 11
313 314 14
314 315 5
315 316 87
316 317 81
317 318 10
318 319 27
319 320 100
320 321 36
321 322 81
322 323 51
323 324 1
324 325 39
325 326 60
326 327 3
327 328 86
328 329 19
329 330 74
330 331 17
331 332 55
332 333 17
333 334 25
334 335 80
335 336 79
336 337 92
337 338 13
338 339 2
339 340 24
340 341 34
341 342 26
342 343 17
343 344 11
344 345 100
345 346 28
346 347 70
347 348 67
348 349 86
349 350 91
350 351 65
351 352 15
352 353 20
353 354 13
354 355 16
355 356 94
356 357 58
357 358 92
358 359 99
359 360 92
360 361 63
361 362 5
362 363 13
363 364 2
364 365 71
365 366 69
366 367 1
367 368 12
368 369 70
369 370 71
370 371 59
371 372 55
372 373 40
373 374 46
374 375 87
375 376 36
376 377 61
377 378 90
378 379 70
379 380 61
380 381 39
381 382 30
382 383 9
383 384 33
384 385 1
385 386 97
386 387 29
387 388 51
388 389 83
389 390 29
390 391 70
391 392 4
392 393 75
393 394 74
394 395 29
395 396 20
396 397 6
397 398 74
398 399 41
399 400 6
400 401 82
401 402 77
402 403 4
403 404 68
404 405 12
405 406 16
406 407 63
407 408 48
408 409 57
409 410 37
410 411 90
411 412 70
412 413 76
413 414 5
414 415 46
415 416 26
416 417 89
417 418 75
418 419 25
419 420 78
420 421 81
421 422 88
422 423 94
423 424 59
424 425 29
425 426 97
426 427 6
427 428 32
428 429 31
429 430 47
430 431 94
431 432 14
432 433 74
433 434 71
434 435 68
435 436 48
436 437 58
437 438 59
438 439 91
439 440 18
440 441 31
441 442 48
442 443 53
443 444 55
444 445 82
445 446 64
446 447 59
447 448 64
448 449 40
449 450 14
450 451 62
451 452 28
452 453 28
453 454 18
454 455 98
455 456 96
456 457 26
457 458 94
458 459 56
459 460 24
460 461 60
461 462 21
462 463 7
463 464 20
464 465 79
465 466 7
466 467 85
467 468 73
468 469 11
469 470 28
470 471 78
471 472 27
472 473 73
473 474 9
474 475 2
475 476 34
476 477 60
477 478 73
478 479 10
479 480 8
480 481 72
481 482 84
482 483 68
483 484 92
484 485 33
485 486 97
486 487 60
487 488 89
488 489 49
489 490 67
490 491 31
491 492 71
492 493 41
493 494 16
494 495 35
495 496 79
496 497 65
497 498 45
498 499 76
499 500 19
500 501 26
501 502 37
502 503 28
503 504 81
504 505 81
505 506 81
506 507 100
507 508 71
508 509 26
509 510 86
510 511 5
511 512 29
512 513 81
513 514 14
514 515 72
515 516 96
516 517 10
517 518 66
518 519 79
519 520 99
520 521 78
521 522 36
522 523 44
523 524 99
524 525 15
525 526 55
526 527 85
527 528 24
528 529 70
529 530 57
530 531 55
531 532 97
532 533 2
533 534 58
534 535 42
535 536 94
536 537 3
537 538 68
538 539 16
539 540 31
540 541 6
541 542 59
542 543 60
543 544 2
544 545 96
545 546 32
546 547 67
547 548 42
548 549 100
549 550 20
550 551 27
551 552 74
552 553 91
553 554 41
554 555 31
555 556 70
556 557 17
557 558 35
558 559 100
559 560 31
560 561 7
561 562 36
562 563 42
563 564 73
564 565 59
565 566 21
566 567 20
567 568 12
568 569 53
569 570 62
570 571 78
571 572 38
572 573 3
573 574 49
574 575 81
575 576 25
576 577 91
577 578 79
578 579 86
579 580 100
580 581 18
581 582 85
582 583 59
583 584 92
584 585 58
585 586 33
586 587 30
587 588 37
588 589 62
589 590 89
590 591 69
591 592 73
592 593 55
593 594 63
594 595 10
595 596 26
596 597 97
597 598 38
598 599 82
599 600 70
600 601 99
601 602 49
602 603 65
603 604 37
604 605 27
605 606 30
606 607 80
607 608 50
608 609 90
609 610 81
610 611 73
611 612 17
612 613 12
613 614 95
614 615 61
615 616 81
616 617 96
617 618 48
618 619 32
619 620 45
620 621 51
621 622 15
622 623 66
623 624 30
624 625 74
625 626 31
626 627 12
627 628 45
628 629 32
629 630 57
630 631 49
631 632 50
632 633 60
633 634 32
634 635 51
635 636 16
636 637 97
637 638 90
638 639 87
639 640 2
640 641 34
641 642 50
642 643 75
643 644 14
644 645 44
645 646 100
646 647 79
647 648 53
648 649 37
649 650 74
650 651 1
651 652 49
652 653 70
653 654 21
654 655 3
655 656 74
656 657 20
657 658 83
658 659 51
659 660 59
660 661 38
661 662 78
662 663 59
663 664 32
664 665 88
665 666 89
666 667 97
667 668 92
668 669 9
669 670 69
670 671 45
671 672 33
672 673 21
673 674 63
674 675 61
675 676 16
676 677 86
677 678 56
678 679 43
679 680 15
680 681 15
681 682 4
682 683 98
683 684 92
684 685 44
685 686 66
686 687 61
687 688 74
688 689 87
689 690 90
690 691 78
691 692 81
692 693 1
693 694 75
694 695 98
695 696 23
696 697 1
697 698 68
698 699 11
699 700 21
700 701 8
701 702 47
702 703 90
703 704 67
704 705 30
705 706 11
706 707 81
707 708 39
708 709 12
709 710 59
710 711 3
711 712 41
712 713 44
713 714 63
714 715 18
715 716 65
716 717 49
717 718 58
718 719 2
719 720 14
720 721 15
721 722 57
722 723 21
723 724 14
724 725 56
725 726 59
726 727 12
727 728 40
728 729 59
729 730 13
730 731 52
731 732 75
732 733 45
733 734 32
734 735 32
735 736 87
736 737 64
737 738 66
738 739 12
739 740 65
740 741 5
741 742 66
742 743 10
743 744 10
744 745 95
745 746 88
746 747 61
747 748 66
748 749 58
749 750 87
750 751 24
751 752 94
752 753 47
753 754 75
754 755 7
755 756 35
756 757 23
757 758 27
758 759 61
759 760 37
760 761 1
761 762 88
762 763 56
763 764 98
764 765 18
765 766 23
766 767 23
767 768 28
768 769 52
769 770 67
770 771 55
771 772 46
772 773 49
773 774 95
774 775 48
775 776 61
776 777 40
777 778 36
778 779 68
779 780 84
780 781 16
781 782 83
782 783 80
783 784 69
784 785 6
785 786 10
786 787 42
787 788 59
788 789 34
789 790 89
790 791 36
791 792 1
792 793 42
793 794 81
794 795 92
795 796 11
796 797 44
797 798 83
798 799 69
799 800 28
800 801 48
801 802 28
802 803 98
803 804 64
804 805 44
805 806 61
806 807 74
807 808 68
808 809 75
809 810 58
810 811 73
811 812 33
812 813 13
813 814 1
814 815 73
815 816 46
816 817 42
817 818 87
818 819 32
819 820 51
820 821 2
821 822 8
822 823 59
823 824 3
824 825 14
825 826 26
826 827 75
827 828 73
828 829 29
829 830 56
830 831 3
831 832 52
832 833 49
833 834 87
834 835 87
835 836 22
836 837 65
837 838 13
838 839 88
839 840 38
840 841 28
841 842 92
842 843 61
843 844 17
844 845 27
845 846 81
846 847 41
847 848 11
848 849 35
849 850 41
850 851 10
851 852 10
852 853 88
853 854 76
854 855 100
855 856 8
856 857 97
857 858 33
858 859 33
859 860 70
860 861 38
861 862 47
862 863 53
863 864 59
864 865 84
865 866 2
866 867 86
867 868 71
868 869 62
869 870 84
870 871 5
871 872 10
872 873 15
873 874 15
874 875 6
875 876 95
876 877 70
877 878 42
878 879 68
879 880 38
880 881 47
881 882 1
882 883 75
883 884 58
884 885 79
885 886 14
886 887 53
887 888 27
888 889 39
889 890 3
890 891 94
891 892 7
892 893 18
893 894 19
894 895 97
895 896 58
896 897 34
897 898 68
898 899 44
899 900 87
900 901 11
901 902 81
902 903 76
903 904 53
904 905 1
905 906 12
906 907 44
907 908 28
908 909 73
909 910 77
910 911 47
911 912 22
912 913 15
913 914 82
914 915 54
915 916 18
916 917 44
917 918 56
918 919 41
919 920 34
920 921 40
921 922 85
922 923 31
923 924 73
924 925 96
925 926 66
926 927 62
927 928 24
928 929 78
929 930 24
930 931 64
931 932 54
932 933 9
933 934 51
934 935 36
935 936 95
936 937 18
937 938 62
938 939 70
939 940 62
940 941 70
941 942 72
942 943 51
943 944 94
944 945 2
945 946 37
946 947 24
947 948 50
948 949 35
949 950 97
950 951 82
951 952 13
952 953 17
953 954 77
954 955 6
955 956 78
956 957 55
957 958 17
958 959 45
959 960 49
960 961 88
961 962 93
962 963 63
963 964 79
964 965 42
965 966 67
966 967 62
967 968 29
968 969 21
969 970 96
970 971 48
971 972 85
972 973 55
973 974 99
974 975 90
975 976 85
976 977 93
977 978 72
978 979 38
979 980 50
980 981 65
981 982 43
982 983 74
983 984 88
984 985 20
985 986 62
986 987 80
987 988 68
988 989 66
989 990 6
990 991 89
991 992 75
992 993 76
993 994 56
994 995 89
995 996 96
996 997 12
997 998 68
998 999 96
711 232 10
746 927 69
763 36 94
308 299 6
350 524 100
437 718 36
157 992 22
82 247 97
744 488 60
366 648 66
81 122 61
614 934 83
870 93 53
869 219 30
757 230 4
105 648 94
320 419 15
245 337 8
360 976 96
349 247 69
396 739 47
112 951 97
206 864 95
769 260 78
466 236 33
829 834 77
456 661 25
975 586 74
173 892 95
526 416 57
143 784 1
899 862 21
169 464 30
760 994 51
667 652 23
33 929 61
862 98 89
315 588 2
951 98 5
657 712 56
552 761 10
921 578 68
422 892 74
889 724 36
252 178 17
995 276 27
283 584 24
731 453 2
78 832 15
612 264 66
160 658 90
773 929 56
609 835 88
406 411 41
542 783 63
814 155 1
111 818 56
40 198 11
763 627 62
196 244 98
835 244 15
66 965 100
612 846 11
336 569 63
711 16 54
320 238 11
694 683 92
808 544 69
859 144 59
795 430 61
373 535 1
921 290 17
827 864 25
185 90 41
130 150 26
884 812 65
726 793 7
235 369 82
679 664 21
503 704 13
70 125 30
920 777 10
736 437 100
117 904 14
928 704 53
116 593 84
310 825 44
271 193 39
815 224 67
738 642 69
111 384 43
453 667 13
630 131 36
751 947 89
302 218 99
342 162 13
352 113 98
630 230 76
671 441 23
941 889 17
573 413 60
561 181 75
720 378 26
872 294 13
563 50 53
789 462 76
948 120 67
727 970 76
954 419 93
442 630 43
912 958 18
833 992 4
273 250 73
958 454 23
39 418 75
347 799 19
903 360 60
526 726 3
156 587 90
956 444 65
523 601 16
700 278 85
424 815 54
329 523 9
779 890 25
382 2 92
898 188 87
929 304 28
964 366 41
427 458 42
550 356 98
628 953 58
707 649 92
893 240 78
810 83 75
124 698 60
4 861 59
8 583 95
54 387 1
358 24 93
927 615 88
981 159 1
792 429 71
730 468 54
970 369 10
901 349 84
59 139 97
29 271 64
39 368 88
779 124 43
635 687 46
831 835 56
861 273 85
750 67 20
568 10 88
440 638 91
943 128 12
96 849 70
223 166 26
489 465 38
288 704 9
860 900 71
692 376 84
216 421 20
4 789 10
714 265 74
489 697 36
36 825 81
836 712 42
918 306 81
984 75 7
589 900 77
304 720 49
969 360 77
660 535 9
453 84 60
705 548 11
895 21 61
725 476 43
602 656 31
227 278 67
26 675 4
13 736 71
22 255 50
816 602 5
485 974 40
335 811 78
989 697 5
605 703 13
604 717 89
388 688 84
151 783 11
993 374 70
755 698 1
314 234 52
197 674 67
561 738 60
992 47 40
784 174 47
558 370 30
332 348 69
279 996 13
634 784 2
493 500 52
42 920 33
836 719 68
266 575 40
899 12 61
724 283 85
340 829 45
493 210 83
64 155 7
479 778 49
997 774 5
554 78 62
619 558 34
446 35 64
380 57 50
809 497 48
784 374 38
160 401 40
174 247 33
210 403 99
501 406 52
848 935 73
288 800 74
259 838 25
469 111 93
968 849 19
752 258 74
936 718 62
985 739 62
588 13 15
664 356 56
665 73 77
827 398 26
533 399 77
408 95 58
40 559 11
746 822 18
900 430 95
560 400 84
369 903 53
836 68 2
638 430 95
552 851 81
81 507 85
176 824 65
833 775 39
242 945 60
3 613 58
611 550 5
937 722 35
573 280 29
197 358 89
239 684 7
527 140 63
255 399 97
242 789 16
236 199 92
538 533 94
941 76 30
634 924 10
686 19 9
542 312 33
860 676 50
669 376 20
609 26 79
338 42 72
46 604 68
361 980 55
416 89 99
745 503 57
297 186 15
581 150 42
787 310 35
59 616 23
709 617 18
506 799 70
54 270 61
181 413 33
596 914 61
804 539 81
878 880 71
739 617 57
621 6 1
725 245 86
645 768 67
572 143 100
370 757 4
454 135 83
169 918 11
782 832 13
123 400 23
624 716 4
449 721 47
262 407 5
165 148 21
610 945 39
115 750 80
676 927 27
409 234 18
574 731 99
183 109 75
206 179 4
116 337 54
998 414 43
853 68 1
661 839 98
349 465 26
784 655 12
863 486 22
190 743 54
937 209 73
339 444 94
483 147 38
134 757 90
503 678 76
399 210 91
252 406 59
74 984 41
693 151 13
165 448 11
603 915 15
983 148 14
407 35 98
372 661 34
417 625 90
537 482 11
753 188 79
34 797 49
253 859 97
318 794 97
52 379 100
7 577 40
766 286 30
628 345 46
885 337 49
135 404 68
775 550 33
894 876 56
339 428 90
211 38 25
214 199 5
170 302 13
974 317 97
195 580 13
131 738 14
928 511 98
127 65 99
383 83 42
533 576 41
319 363 35
471 701 84
457 145 51
524 886 21
96 921 63
280 594 93
770 140 69
936 68 99
992 677 18
114 106 4
472 678 91
281 358 85
497 416 48
681 147 52
939 958 77
834 180 26
305 206 53
85 470 70
110 608 1
122 877 63
933 904 75
78 49 46
695 283 36
423 887 72
945 785 10
554 654 63
398 326 64
821 265 13
267 307 16
305 789 31
377 855 91
890 816 13
819 48 21
114 807 25
767 115 85
253 556 85
418 183 7
316 278 33
237 287 23
110 30 44
61 457 71
173 384 16
845 370 20
796 34 20
192 131 45
603 258 69
323 696 72
257 80 34
148 800 3
60 573 14
391 435 11
712 45 37
708 169 37
957 178 14
398 388 32
3 779 39
258 587 80
62 377 75
867 455 64
278 715 34
517 794 78
325 654 61
794 901 98
753 608 39
691 314 73
649 852 26
370 265 68
280 81 62
574 437 74
175 439 60
398 540 74
960 421 5
411 955 57
648 431 90
389 556 49
283 106 48
343 381 16
398 561 26
386 579 79
798 640 12
139 496 54
387 769 12
94 629 82
123 681 26
879 815 49
759 468 80
641 165 72
810 380 77
432 309 41
908 771 5
128 865 41
852 848 90
654 89 86
83 932 63
710 621 36
98 312 26
835 234 87
145 389 13
92 325 94
882 494 2
420 917 27
42 938 34
458 988 97
205 142 91
428 152 64
330 177 78
857 22 46
620 734 94
892 674 15
908 166 80
96 477 21
245 36 41
221 223 31
742 441 48
469 661 45
90 132 13
680 878 76
334 287 87
822 465 66
125 753 24
794 618 37
67 796 4
951 915 62
602 897 22
523 690 10
919 788 36
187 546 79
65 919 26
372 920 72
342 927 42
415 486 76
304 618 69
299 165 24
401 387 43
146 627 93
398 464 85
653 623 60
3 574 89
973 53 99
267 394 72
35 907 96
64 133 15
696 81 48
464 650 6
864 561 90
181 21 79
523 684 7
764 822 44
859 517 35
338 857
321 752
582 889
102 780
980 288
910 465
951 343
718 752
644 412
759 909
555 12
465 155
123 320
549 9
595 689
793 383
424 844
420 600
887 888
670 368