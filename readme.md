#Readme File 

# The GOAL: Create a graph. Retreive the highest capacity between two Nodes in the graph. 
## Note: When getting multiple capacities (crossing multiple edges), the smallest capacity will be retrieved.   

# Algorithm 
In this program, a modified version of the Dijsktra algorithm was used. The original algorithm grabs the shortest path in a graph. The algorithm views the weight on the graph as a distance and grabs the lowest distance value between two points. This algorithm can be easily modified to grab the highest weight between two nodes instead of the lowest. Instead of viewing the weight as distance, it can be viewed as capacity. 

## Test Cases: 
First line = # of vertices, # of edges, # of paths that will be looked for.  
Other lines with 3 #s = Node1, Node2, Weight between Nodes. 
Lines with 2 #s = Paths that want to be found between two Nodes. 
### Original Input Modified to work:   
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
## output: path 1 --> 2: . Path 6 --> 2: 
6 9 2 
1 6 20 
1 5 50 
1 2 30 
3 2 90
4 2 70 
4 3 80 
5 2 40 
5 4 60 
6 2 200
1 2 
6 2 

### Custom test set - two cities connected with at least one connection including multiple segments 
## Output: 1 -> 4 : Path : 1  4    capacity : 8. 3 -> 1 : Path : 3  1    capacity : 5
5 8 2 
1 4 8 
1 5 7 
1 2 1 
4 3 3 
4 5 4 
3 2 2 
3 5 5 
2 5 6 
1 4 
3 1 

## 1000 nodes with 20 queries 
1000 1500 20
1 2 81
2 3 48
3 4 31
4 5 13
5 6 34
6 7 2
7 8 57
8 9 63
9 10 65
10 11 5
11 12 24
12 13 66
13 14 74
14 15 3
15 16 46
16 17 58
17 18 36
18 19 46
19 20 9
20 21 40
21 22 3
22 23 35
23 24 54
24 25 82
25 26 10
26 27 38
27 28 88
28 29 91
29 30 64
30 31 86
31 32 43
32 33 29
33 34 14
34 35 32
35 36 69
36 37 42
37 38 53
38 39 27
39 40 95
40 41 4
41 42 8
42 43 49
43 44 52
44 45 23
45 46 74
46 47 26
47 48 86
48 49 78
49 50 56
50 51 12
51 52 24
52 53 84
53 54 74
54 55 7
55 56 100
56 57 48
57 58 94
58 59 7
59 60 93
60 61 25
61 62 72
62 63 37
63 64 31
64 65 77
65 66 60
66 67 36
67 68 8
68 69 4
69 70 86
70 71 3
71 72 43
72 73 12
73 74 22
74 75 85
75 76 24
76 77 44
77 78 91
78 79 85
79 80 33
80 81 25
81 82 77
82 83 60
83 84 21
84 85 44
85 86 89
86 87 56
87 88 65
88 89 93
89 90 96
90 91 43
91 92 9
92 93 39
93 94 17
94 95 24
95 96 93
96 97 58
97 98 92
98 99 75
99 100 1
100 101 86
101 102 48
102 103 44
103 104 40
104 105 1
105 106 42
106 107 41
107 108 95
108 109 48
109 110 9
110 111 27
111 112 100
112 113 67
113 114 33
114 115 90
115 116 43
116 117 80
117 118 55
118 119 39
119 120 23
120 121 21
121 122 56
122 123 72
123 124 30
124 125 82
125 126 24
126 127 64
127 128 99
128 129 87
129 130 26
130 131 61
131 132 74
132 133 29
133 134 78
134 135 20
135 136 82
136 137 35
137 138 16
138 139 52
139 140 30
140 141 78
141 142 55
142 143 3
143 144 2
144 145 37
145 146 74
146 147 31
147 148 11
148 149 59
149 150 93
150 151 61
151 152 52
152 153 75
153 154 80
154 155 1
155 156 1
156 157 11
157 158 76
158 159 65
159 160 40
160 161 15
161 162 31
162 163 62
163 164 67
164 165 79
165 166 28
166 167 21
167 168 94
168 169 33
169 170 13
170 171 49
171 172 52
172 173 68
173 174 92
174 175 65
175 176 97
176 177 48
177 178 81
178 179 68
179 180 80
180 181 99
181 182 56
182 183 85
183 184 13
184 185 3
185 186 76
186 187 48
187 188 7
188 189 40
189 190 14
190 191 73
191 192 46
192 193 17
193 194 41
194 195 14
195 196 35
196 197 97
197 198 50
198 199 35
199 200 82
200 201 16
201 202 28
202 203 86
203 204 59
204 205 84
205 206 59
206 207 34
207 208 15
208 209 95
209 210 34
210 211 89
211 212 85
212 213 73
213 214 22
214 215 40
215 216 24
216 217 8
217 218 86
218 219 62
219 220 38
220 221 85
221 222 2
222 223 99
223 224 6
224 225 58
225 226 55
226 227 4
227 228 87
228 229 70
229 230 4
230 231 53
231 232 63
232 233 26
233 234 43
234 235 84
235 236 63
236 237 39
237 238 97
238 239 19
239 240 80
240 241 74
241 242 29
242 243 36
243 244 83
244 245 40
245 246 83
246 247 22
247 248 16
248 249 39
249 250 71
250 251 61
251 252 4
252 253 35
253 254 93
254 255 51
255 256 5
256 257 9
257 258 12
258 259 51
259 260 51
260 261 97
261 262 100
262 263 52
263 264 5
264 265 84
265 266 19
266 267 33
267 268 73
268 269 60
269 270 36
270 271 16
271 272 96
272 273 31
273 274 97
274 275 28
275 276 71
276 277 55
277 278 26
278 279 100
279 280 60
280 281 80
281 282 10
282 283 57
283 284 34
284 285 23
285 286 40
286 287 12
287 288 41
288 289 29
289 290 4
290 291 9
291 292 59
292 293 87
293 294 25
294 295 10
295 296 69
296 297 32
297 298 1
298 299 90
299 300 25
300 301 25
301 302 90
302 303 39
303 304 42
304 305 24
305 306 40
306 307 26
307 308 21
308 309 64
309 310 86
310 311 17
311 312 41
312 313 96
313 314 23
314 315 12
315 316 27
316 317 19
317 318 34
318 319 5
319 320 78
320 321 18
321 322 22
322 323 99
323 324 75
324 325 59
325 326 55
326 327 97
327 328 65
328 329 1
329 330 97
330 331 67
331 332 86
332 333 39
333 334 91
334 335 95
335 336 94
336 337 34
337 338 34
338 339 44
339 340 24
340 341 88
341 342 76
342 343 17
343 344 47
344 345 70
345 346 6
346 347 17
347 348 22
348 349 48
349 350 98
350 351 77
351 352 13
352 353 3
353 354 24
354 355 35
355 356 31
356 357 59
357 358 69
358 359 60
359 360 77
360 361 25
361 362 5
362 363 91
363 364 33
364 365 26
365 366 75
366 367 41
367 368 10
368 369 32
369 370 97
370 371 4
371 372 79
372 373 67
373 374 86
374 375 35
375 376 33
376 377 51
377 378 7
378 379 54
379 380 30
380 381 35
381 382 4
382 383 66
383 384 50
384 385 65
385 386 18
386 387 10
387 388 90
388 389 58
389 390 76
390 391 74
391 392 61
392 393 17
393 394 89
394 395 50
395 396 67
396 397 37
397 398 67
398 399 33
399 400 66
400 401 79
401 402 57
402 403 63
403 404 43
404 405 56
405 406 18
406 407 23
407 408 89
408 409 62
409 410 77
410 411 95
411 412 28
412 413 75
413 414 27
414 415 3
415 416 43
416 417 81
417 418 79
418 419 87
419 420 26
420 421 70
421 422 81
422 423 11
423 424 94
424 425 68
425 426 90
426 427 72
427 428 37
428 429 27
429 430 10
430 431 53
431 432 45
432 433 15
433 434 39
434 435 92
435 436 88
436 437 2
437 438 59
438 439 8
439 440 9
440 441 74
441 442 58
442 443 21
443 444 24
444 445 69
445 446 86
446 447 98
447 448 99
448 449 85
449 450 62
450 451 61
451 452 74
452 453 19
453 454 63
454 455 70
455 456 96
456 457 18
457 458 75
458 459 87
459 460 13
460 461 97
461 462 92
462 463 72
463 464 85
464 465 80
465 466 90
466 467 65
467 468 92
468 469 94
469 470 35
470 471 56
471 472 30
472 473 65
473 474 37
474 475 63
475 476 58
476 477 18
477 478 92
478 479 79
479 480 67
480 481 19
481 482 65
482 483 63
483 484 23
484 485 40
485 486 95
486 487 67
487 488 65
488 489 37
489 490 25
490 491 28
491 492 69
492 493 47
493 494 65
494 495 52
495 496 39
496 497 33
497 498 31
498 499 5
499 500 83
500 501 42
501 502 12
502 503 16
503 504 7
504 505 26
505 506 62
506 507 8
507 508 10
508 509 88
509 510 71
510 511 46
511 512 20
512 513 56
513 514 36
514 515 66
515 516 68
516 517 66
517 518 27
518 519 57
519 520 32
520 521 59
521 522 73
522 523 24
523 524 47
524 525 55
525 526 34
526 527 76
527 528 73
528 529 31
529 530 40
530 531 94
531 532 38
532 533 91
533 534 15
534 535 44
535 536 94
536 537 48
537 538 4
538 539 64
539 540 8
540 541 4
541 542 34
542 543 28
543 544 99
544 545 8
545 546 32
546 547 44
547 548 6
548 549 71
549 550 53
550 551 62
551 552 50
552 553 70
553 554 14
554 555 20
555 556 95
556 557 80
557 558 77
558 559 28
559 560 43
560 561 52
561 562 20
562 563 88
563 564 15
564 565 87
565 566 18
566 567 38
567 568 61
568 569 16
569 570 36
570 571 71
571 572 87
572 573 32
573 574 58
574 575 59
575 576 1
576 577 90
577 578 88
578 579 100
579 580 29
580 581 5
581 582 92
582 583 85
583 584 63
584 585 35
585 586 54
586 587 17
587 588 97
588 589 96
589 590 94
590 591 68
591 592 40
592 593 38
593 594 49
594 595 100
595 596 88
596 597 17
597 598 22
598 599 20
599 600 18
600 601 11
601 602 79
602 603 29
603 604 29
604 605 33
605 606 54
606 607 77
607 608 58
608 609 48
609 610 48
610 611 7
611 612 8
612 613 43
613 614 4
614 615 1
615 616 91
616 617 87
617 618 66
618 619 78
619 620 48
620 621 55
621 622 29
622 623 26
623 624 84
624 625 45
625 626 11
626 627 6
627 628 30
628 629 39
629 630 27
630 631 58
631 632 37
632 633 19
633 634 81
634 635 95
635 636 9
636 637 6
637 638 8
638 639 74
639 640 64
640 641 9
641 642 79
642 643 52
643 644 66
644 645 18
645 646 38
646 647 54
647 648 37
648 649 10
649 650 17
650 651 21
651 652 91
652 653 9
653 654 6
654 655 46
655 656 33
656 657 46
657 658 28
658 659 73
659 660 53
660 661 36
661 662 55
662 663 87
663 664 1
664 665 39
665 666 39
666 667 33
667 668 21
668 669 36
669 670 38
670 671 72
671 672 24
672 673 57
673 674 42
674 675 48
675 676 1
676 677 59
677 678 73
678 679 39
679 680 54
680 681 5
681 682 63
682 683 61
683 684 57
684 685 66
685 686 47
686 687 76
687 688 50
688 689 34
689 690 47
690 691 24
691 692 52
692 693 81
693 694 9
694 695 28
695 696 21
696 697 5
697 698 45
698 699 38
699 700 59
700 701 5
701 702 46
702 703 15
703 704 80
704 705 83
705 706 3
706 707 83
707 708 53
708 709 18
709 710 27
710 711 11
711 712 11
712 713 54
713 714 57
714 715 2
715 716 83
716 717 25
717 718 53
718 719 85
719 720 31
720 721 49
721 722 83
722 723 41
723 724 87
724 725 67
725 726 99
726 727 50
727 728 92
728 729 95
729 730 64
730 731 69
731 732 6
732 733 79
733 734 31
734 735 17
735 736 49
736 737 22
737 738 34
738 739 41
739 740 64
740 741 57
741 742 23
742 743 23
743 744 77
744 745 37
745 746 86
746 747 96
747 748 2
748 749 77
749 750 82
750 751 36
751 752 72
752 753 6
753 754 99
754 755 51
755 756 66
756 757 64
757 758 59
758 759 86
759 760 60
760 761 23
761 762 49
762 763 8
763 764 41
764 765 52
765 766 34
766 767 49
767 768 99
768 769 3
769 770 23
770 771 68
771 772 45
772 773 8
773 774 64
774 775 8
775 776 41
776 777 90
777 778 60
778 779 70
779 780 1
780 781 21
781 782 42
782 783 84
783 784 57
784 785 38
785 786 94
786 787 86
787 788 10
788 789 24
789 790 16
790 791 58
791 792 6
792 793 23
793 794 23
794 795 96
795 796 21
796 797 74
797 798 47
798 799 39
799 800 35
800 801 41
801 802 61
802 803 86
803 804 65
804 805 43
805 806 1
806 807 89
807 808 6
808 809 19
809 810 43
810 811 4
811 812 54
812 813 76
813 814 8
814 815 26
815 816 28
816 817 33
817 818 84
818 819 9
819 820 78
820 821 26
821 822 88
822 823 20
823 824 91
824 825 99
825 826 32
826 827 67
827 828 66
828 829 99
829 830 10
830 831 49
831 832 17
832 833 95
833 834 100
834 835 43
835 836 95
836 837 95
837 838 55
838 839 34
839 840 77
840 841 59
841 842 82
842 843 96
843 844 30
844 845 74
845 846 45
846 847 57
847 848 97
848 849 3
849 850 64
850 851 66
851 852 22
852 853 3
853 854 92
854 855 3
855 856 97
856 857 49
857 858 42
858 859 71
859 860 1
860 861 18
861 862 17
862 863 8
863 864 13
864 865 88
865 866 2
866 867 71
867 868 3
868 869 84
869 870 58
870 871 78
871 872 81
872 873 77
873 874 39
874 875 21
875 876 99
876 877 76
877 878 98
878 879 100
879 880 81
880 881 31
881 882 23
882 883 34
883 884 11
884 885 43
885 886 9
886 887 35
887 888 29
888 889 11
889 890 84
890 891 63
891 892 30
892 893 11
893 894 97
894 895 50
895 896 1
896 897 62
897 898 57
898 899 93
899 900 54
900 901 54
901 902 25
902 903 91
903 904 36
904 905 97
905 906 13
906 907 35
907 908 85
908 909 89
909 910 44
910 911 53
911 912 51
912 913 100
913 914 1
914 915 86
915 916 96
916 917 2
917 918 67
918 919 91
919 920 13
920 921 8
921 922 63
922 923 34
923 924 30
924 925 48
925 926 29
926 927 78
927 928 54
928 929 8
929 930 42
930 931 49
931 932 70
932 933 100
933 934 53
934 935 41
935 936 13
936 937 14
937 938 2
938 939 47
939 940 89
940 941 80
941 942 72
942 943 18
943 944 37
944 945 16
945 946 29
946 947 8
947 948 88
948 949 16
949 950 69
950 951 59
951 952 30
952 953 95
953 954 68
954 955 100
955 956 78
956 957 64
957 958 50
958 959 40
959 960 58
960 961 16
961 962 35
962 963 42
963 964 73
964 965 73
965 966 68
966 967 40
967 968 76
968 969 22
969 970 7
970 971 77
971 972 26
972 973 6
973 974 35
974 975 59
975 976 21
976 977 58
977 978 89
978 979 99
979 980 61
980 981 25
981 982 43
982 983 28
983 984 16
984 985 79
985 986 50
986 987 53
987 988 17
988 989 46
989 990 28
990 991 58
991 992 60
992 993 16
993 994 87
994 995 71
995 996 90
996 997 46
997 998 85
998 999 31
999 1000 67
976 265 66
532 839 78
950 606 46
346 873 55
321 124 43
872 327 13
131 33 7
389 427 65
645 250 53
153 582 71
227 457 23
239 281 89
765 483 90
710 979 61
578 14 92
356 631 49
374 532 12
132 519 2
921 106 66
919 428 51
546 337 20
212 387 63
673 174 96
652 844 88
649 530 39
481 738 29
178 243 99
314 344 19
898 15 72
194 314 68
505 147 35
874 193 32
918 21 43
345 140 1
971 961 6
653 244 66
502 343 76
979 205 26
710 639 31
604 368 44
824 786 99
17 920 11
433 651 56
11 445 12
347 750 23
997 974 98
876 202 72
185 647 56
20 345 27
740 523 73
520 207 47
845 758 66
885 381 59
899 746 31
76 473 40
229 865 56
222 114 39
481 879 45
287 66 95
912 643 87
223 947 30
179 565 4
195 293 46
649 350 59
405 889 51
163 622 13
784 327 36
992 152 47
294 348 6
228 274 52
524 806 92
631 696 12
189 747 72
904 726 20
234 878 46
178 996 11
235 810 49
590 587 79
70 97 51
75 521 41
721 199 35
681 646 68
407 942 26
419 613 51
508 325 7
149 783 71
705 754 12
820 66 69
129 912 38
97 852 12
279 416 95
953 109 89
905 868 76
45 540 33
586 216 88
558 198 87
301 887 70
139 428 92
754 410 40
347 225 42
792 895 66
611 201 75
475 94 22
856 313 69
846 678 32
154 932 3
426 262 71
982 941 26
749 430 33
872 700 97
717 571 6
122 95 17
324 70 21
788 451 95
723 778 50
425 852 91
58 843 6
374 773 29
634 814 92
494 175 99
11 799 31
874 626 69
933 560 30
541 992 16
154 66 2
796 591 94
549 526 98
339 220 46
44 910 4
677 550 51
990 141 22
180 987 53
383 742 49
692 252 62
22 249 24
949 135 72
479 347 28
384 780 64
912 520 92
69 627 60
433 70 48
79 885 62
516 614 84
910 985 95
851 321 80
145 111 10
263 962 100
857 794 49
710 884 61
469 661 9
908 375 93
268 669 58
638 326 16
874 798 98
110 35 20
945 989 47
123 533 79
76 185 43
459 822 2
577 543 63
654 634 10
858 112 34
532 787 3
747 418 77
61 119 45
226 460 31
338 348 73
521 328 55
480 441 40
464 915 7
209 39 96
824 217 18
880 706 12
879 627 53
153 209 28
476 62 62
570 983 45
334 407 3
566 112 69
667 137 81
40 767 67
26 901 91
178 399 57
933 15 42
550 774 41
626 829 3
662 538 37
923 164 94
328 50 38
819 508 70
885 275 35
788 826 47
851 457 32
721 195 59
809 405 12
151 358 41
870 356 59
74 77 6
948 481 73
563 753 27
358 547 27
938 302 74
83 106 55
235 852 47
196 921 36
849 65 76
933 727 94
171 162 86
225 349 38
410 525 97
964 294 14
503 979 75
304 264 69
636 291 15
138 656 83
820 980 63
983 673 80
213 479 21
97 643 46
702 372 38
767 196 42
284 45 81
473 343 90
426 524 51
220 424 66
134 295 93
721 809 99
148 652 65
97 317 2
882 411 38
234 195 69
719 562 76
872 398 88
77 235 97
307 388 94
910 275 6
256 718 12
740 6 22
518 874 26
487 412 57
130 336 40
487 965 42
955 157 16
845 774 94
473 439 93
444 145 23
229 345 72
703 6 49
452 344 29
547 448 38
208 270 49
655 796 46
359 565 50
664 448 76
473 438 76
988 272 5
701 296 4
996 1000 44
596 436 43
210 282 6
55 800 47
721 572 87
375 860 34
319 251 76
429 551 51
375 925 76
181 924 70
986 506 52
729 593 99
955 688 24
768 383 14
635 43 22
629 461 40
93 235 81
434 642 8
924 158 81
781 927 45
490 884 26
156 372 60
337 845 79
233 753 84
36 353 6
692 138 29
501 87 90
197 969 81
564 702 9
617 841 29
879 257 49
55 517 26
575 107 85
864 36 12
753 493 99
889 594 58
830 645 48
120 738 91
354 829 81
668 76 38
625 524 47
197 613 45
770 147 72
693 947 26
606 259 89
456 345 9
850 597 50
717 550 55
215 99 65
924 449 74
229 517 58
409 34 9
749 815 64
736 322 18
387 393 52
797 502 39
404 871 76
213 262 99
120 572 52
150 634 30
452 665 46
287 740 35
323 576 86
933 183 18
861 418 28
320 830 60
80 979 74
96 250 64
382 588 62
703 207 37
503 373 19
373 430 39
108 946 35
461 407 26
425 58 59
640 478 1
135 967 66
188 879 76
754 400 42
22 855 96
762 755 11
494 715 37
313 921 67
602 642 48
610 796 40
747 162 88
103 708 77
397 868 46
777 661 25
754 431 99
708 906 96
366 999 64
726 340 95
17 356 12
410 428 59
448 654 95
962 736 3
131 757 30
783 619 7
660 146 44
256 973 18
650 976 34
329 105 40
431 368 60
545 277 17
509 905 94
161 193 13
106 730 33
668 989 32
979 533 37
903 458 57
169 469 29
795 725 89
968 26 6
772 478 91
447 351 56
823 907 30
754 840 29
654 980 81
96 909 42
425 162 57
724 315 61
900 593 70
515 385 2
737 970 45
578 888 87
140 207 13
279 467 71
653 229 17
746 98 22
775 146 90
282 117 73
614 462 55
338 47 96
931 441 16
736 381 48
816 550 34
818 142 16
298 670 61
329 963 82
630 735 20
78 800 56
111 840 39
502 499 16
851 150 74
902 83 36
462 609 63
763 73 73
86 930 27
636 690 24
814 507 35
222 422 27
996 366 39
323 705 66
640 665 20
507 839 84
147 104 8
849 238 11
452 625 66
525 845 49
178 273 79
831 31 77
433 59 82
140 471 89
771 386 15
251 94 52
299 40 43
192 999 21
347 335 62
600 583 90
375 451 44
435 886 33
672 942 68
56 823 74
466 241 1
642 101 12
546 268 14
141 12 49
449 129 28
670 745 77
617 893 35
310 63 38
991 591 81
142 121 96
340 45 94
617 824 86
58 673 90
196 95 73
134 706 2
434 411 62
806 601 54
558 557 31
597 958 68
965 692 92
92 310 51
894 560 41
585 460 59
656 861 62
555 508 88
377 190 43
918 780 99
115 611 77
830 196 34
980 596 6
277 1000 32
341 431 21
55 717 9
362 880 33
724 209 7
634 919 20
229 37 44
328 143 75
188 326 33
765 878 42
617 861 97
490 704 49
176 641 32
831 682 75
122 839 41
863 102 56
664 195 33
381 111 72
641 463 8
697 896 4
198 872 58
966 567 5
613 57 56
97 510 35
933 949 1
192 423 54
841 249 59
407 521 3
921 821 12
337 469 93
341 800 66
870 761 64
6 46 73
938 980 93
701 228 77
562 490 46
640 368 85
704 709 91
355 889 4
844 694 98
556 344
544 903
241 212
336 548
555 869
502 405
249 770
702 68
566 320
332 990
437 691
651 126
852 386
617 568
439 777
531 984
192 889
102 760
425 657
756 393

